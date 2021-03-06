#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

typedef struct block {
  char * policy;
  unsigned long int tag;
  int valid;
  unsigned long int addr;
  unsigned long int poltime;
  unsigned long int index;

}
block;

unsigned long int reads = 0; //the total number of reads
unsigned long int writes = 0; // the total number of writes
unsigned long int hits1 = 0; // the total number of cache hits
unsigned long int miss1 = 0; // the total number of cache misses
unsigned long int hits2 = 0; // the total number of cache hits
unsigned long int miss2 = 0; // the total number of cache misses
char * policy1 = "a";
char * policy2 = "a";
//int ttt = 0;
unsigned long int polcount;

int computer(struct block ** cache, unsigned long int setIndex, unsigned long int r) {
  int flag = 0;
  if (cache[setIndex][r].valid == 0 && strcmp(cache[setIndex][r].policy, "fifo") == 0) {
    flag = 1;
  } else if (cache[setIndex][r].valid == 0 && strcmp(cache[setIndex][r].policy, "lru") == 0) {
    flag = 2;
  } else if (cache[setIndex][r].valid == 1 && strcmp(cache[setIndex][r].policy, "fifo") == 0) {
    flag = 3;
  } else if (cache[setIndex][r].valid == 1 && strcmp(cache[setIndex][r].policy, "lru") == 0) {
    flag = 4;
  }
  return flag;
}

void write(struct block ** cache1, struct block ** cache2, unsigned long int tag1, unsigned long int tag2, unsigned long int addr, unsigned long int setIndex1, unsigned long int setIndex2, unsigned long int linespset1, unsigned long int linespset2, unsigned long int offsetSize2, unsigned long int setSize2) {
  //1. If the block is found in L1 cache, then the data is read from L1 cache
  //2. If the block is notfound in the L1 cache, but present in the L2 cache (An L2 cache hit), then the cache blockis moved from the L2 cache to the L1 cache.  If this causes a block to be evicted from L1,the evicted block is then placed into L2
  //3. If not found in either L1 or L2, thenit is read from main memory and placed just in L1 and not in L2.
  unsigned long int smallest;
  int rob = linespset1 - 1;
  int hitted = 0;
  for (unsigned long int r = 0; r < linespset1; r++) {
    int flag = computer(cache1, setIndex1, r);
    if (rob == r) {
      smallest = 0;
    }

    if (flag == 1 || flag == 2) { // miss - array index is empty
      miss1++;
      int hited = 0;
      //hit in l2 fifo
      for (unsigned long int p = 0; p < linespset2; p++) { //search through l2 to see if there is a hit
        if (cache2[setIndex2][p].tag == tag2) {
          hited = 1;
          hitted = 1;
          hits2++;
          //reads++;
          //writes++;
          //insert block into l1 at r because it is empty

          cache1[setIndex1][r].index = setIndex1;
          cache1[setIndex1][r].valid = 1;
          cache1[setIndex1][r].addr = addr;
          cache1[setIndex1][r].tag = tag1;
          polcount++;
          cache1[setIndex1][r].poltime = polcount;
          //delete block in l2
          cache2[setIndex2][p].valid = 0;
          break;
        }

      }
      if (hited == 0) {
        miss2++; //miss in both -no replacement needed since the l1 array is empty
        //writes++;
        reads++;
        cache1[setIndex1][r].index = setIndex1;
        cache1[setIndex1][r].valid = 1;
        cache1[setIndex1][r].addr = addr;
        cache1[setIndex1][r].tag = tag1;
        cache1[setIndex1][r].poltime = polcount;
        hitted = 1;
        break; //done with this ad
      }
      break; //done with this ad
    } else if (flag == 3) { //l1 hit and a fifo
      unsigned long int s = cache1[setIndex1][r].index;
      unsigned long int t = cache1[setIndex1][r].tag;
      if (s == setIndex1 && t == tag1) {
        hitted = 1;
        //reads++;
        hits1++;
        break; //leave the general for
      }
    } else if (flag == 4) { //l1 hit and a lru
      unsigned long int s = cache1[setIndex1][r].index;
      unsigned long int t = cache1[setIndex1][r].tag;
      if (s == setIndex1 && t == tag1) {
        hitted = 1;
        //reads++;
        polcount++;
        cache1[setIndex1][r].poltime = polcount;
        hits1++;
        break;
      }
    }

  }
  if (hitted == 0) { // if was a miss in L1 and the adresses are all full
    int hited = 0;
    miss1++;
    for (unsigned long int p = 0; p < linespset2; p++) { //search through l2 to see if there is a hit
      if (cache2[setIndex2][p].tag == tag2) { // if hit in l2
        hited = 1;
        hitted = 1;
        hits2++;
        //writes++;
        //insert block into l1 but use the eviction policy needed
        //first find min from l1 so we can evict that
        unsigned long int i;
        for (i = 0; i < linespset1; i++) { //finds min of l1
          unsigned long int fir = cache1[setIndex1][smallest].poltime;
          unsigned long int sec = cache1[setIndex1][i].poltime;
          if (fir > sec) {
            smallest = i;
          }
        }
        //see if replacement is needed in l2 (if not full add it at the 0 valid) (if full evict with l2 policy) -recalc the l2 adresss
        unsigned long int setIndex2_1 = ((cache1[setIndex1][smallest].addr) >> offsetSize2) & ((1 << setSize2) - 1);
        unsigned long int tag2_1 = cache1[setIndex1][smallest].addr >> (setSize2 + offsetSize2);
        //insert to l1

        cache1[setIndex1][smallest].index = setIndex1;
        cache1[setIndex1][smallest].valid = 1;
        cache1[setIndex1][smallest].addr = addr;
        cache1[setIndex1][smallest].tag = tag1;
        polcount++;
        cache1[setIndex1][smallest].poltime = polcount;
        int yu = 0;
        for (unsigned long int i = 0; i < linespset2; i++) {
          int flage = computer(cache2, setIndex2_1, i);
          if (flage == 1 || flage == 2) { //means not full add it l1 eviction to the 0 valid
            //writes++;
            polcount++;
            cache2[setIndex2_1][i].index = setIndex2_1;
            cache2[setIndex2_1][i].valid = 1;
            cache2[setIndex2_1][i].addr = cache1[setIndex1][smallest].addr;
            cache2[setIndex2_1][i].tag = tag2_1;
            cache2[setIndex2_1][i].poltime = polcount;
            break; // block 1 is in 2
          } else {
            yu = 1;
          }
        }
        if (yu == 1) { //full evict by finding the smallest at the new adr then use l2 policy to add
          for (unsigned long int i = 0; i < linespset2; i++) {
            //printf("smallest %lu\n", smallest);
            smallest = 0;
            unsigned long int fir = cache2[setIndex2_1][smallest].poltime;
            unsigned long int sec = cache2[setIndex2_1][i].poltime;
            if (fir > sec) {
              smallest = i;
            }
          }
          //writes++;

          cache2[setIndex2_1][smallest].index = setIndex2_1;
          cache2[setIndex2_1][smallest].valid = 1;
          cache2[setIndex2_1][smallest].addr = addr;
          cache2[setIndex2_1][smallest].tag = tag2_1;
          polcount++;
          cache2[setIndex2_1][smallest].poltime = polcount;
          break; //block 1 is in 2
        }
      }
    }

    if (hited == 0) { //miss in both -put in l1 using replacement policy
      //look if l1 is empty at that index - if so insert
      int yt = 0;
      miss2++;
      for (unsigned long int p = 0; p < linespset1; p++) { //search through l1 to see if there is an empty valid
        int flagel = computer(cache1, setIndex1, p);
        if (flagel == 1 || flagel == 2) { // if free in l1
          //writes++;

          yt = 1;
          cache1[setIndex1][p].index = setIndex1;
          cache1[setIndex1][p].valid = 1;
          cache1[setIndex1][p].addr = addr;
          cache1[setIndex1][p].tag = tag1;
          polcount++;
          cache1[setIndex1][p].poltime = polcount;
          break; // block 1 is in 1
        }
      }
      //follow replacement policy for l1 and insert
      unsigned long smales = 0;
      if (yt == 0) {
        for (unsigned long int i = 0; i < linespset1; i++) {
          unsigned long int fir = cache1[setIndex1][smales].poltime;
          unsigned long int sec = cache1[setIndex1][i].poltime;
          if (fir > sec) {
            smales = i;
          }
        }

        unsigned long int setIndex2_1 = ((cache1[setIndex1][smales].addr) >> offsetSize2) & ((1 << setSize2) - 1);
        unsigned long int tag2_1 = cache1[setIndex1][smales].addr >> (setSize2 + offsetSize2);
        int yo = 0;
        for (unsigned long int i = 0; i < linespset2; i++) {
          int flagels = computer(cache2, setIndex2_1, i);
          if (flagels == 1 || flagels == 2) { //means not full add it l1 eviction to the 0 valid
            //writes++;
            cache2[setIndex2_1][i].index = setIndex2_1;
            cache2[setIndex2_1][i].valid = 1;
            cache2[setIndex2_1][i].addr = cache1[setIndex1][smales].addr;
            cache2[setIndex2_1][i].tag = tag2_1;
            polcount++;
            cache2[setIndex2_1][i].poltime = polcount;
            break; // block 1 is in 2
          } else {
            yo = 1;
          }
        }
        if (yo == 1) { //full evict by finding the smallest at the new adr then use l2 policy to add
          for (unsigned long int i = 0; i < linespset2; i++) {
            smallest = 0;
            unsigned long int fir = cache2[setIndex2_1][smallest].poltime;
            unsigned long int sec = cache2[setIndex2_1][i].poltime;
            if (fir > sec) {
              smallest = i;
            }
          }
          //writes++;
          //ttt++;
          //printf("%d\n", ttt);

          cache2[setIndex2_1][smallest].index = setIndex2_1;
          cache2[setIndex2_1][smallest].valid = 1;
          cache2[setIndex2_1][smallest].addr = addr;
          cache2[setIndex2_1][smallest].tag = tag2_1;
          polcount++;
          cache2[setIndex2_1][smallest].poltime = polcount;
          // break; //block 1 is in 2
        }
        //writes++;
        reads++;
        polcount++;
        cache1[setIndex1][smales].index = setIndex1;
        cache1[setIndex1][smales].valid = 1;
        cache1[setIndex1][smales].addr = addr;
        //printf("tag %lu\n", tag1);
        //printf("smallest %lu\n", smales);
        //printf("st %lu\n", setIndex1);
        cache1[setIndex1][smales].tag = tag1;
        cache1[setIndex1][smales].poltime = polcount;
      }
    }

  }
}

int main(int argc, char ** argv) {
  if (argc != 9) {
    printf("error\n");
  } else {
    policy1 = argv[3];
    policy2 = argv[7];
    int wrongp1 = 0;
    int wrongp2 = 0;
    if (strcmp(policy1, "lru") == 0 || strcmp(policy1, "fifo") == 0) {
      wrongp1 = 1;

    }
    if (strcmp(policy2, "lru") == 0 || strcmp(policy2, "fifo") == 0) {
      wrongp2 = 1;
    }

    char * fasso1 = argv[2];
    char * fasso2 = argv[6];
    int wrongas1 = 0;
    int nval; //set assoc;
    if (strcmp(fasso1, "direct") == 0) {
      wrongas1 = 1;
    }
    if (strcmp(fasso1, "assoc") == 0) {
      wrongas1 = 1;
    }
    if (fasso1[5] == ':') {
      nval = atoi( & fasso1[6]);
      double yr = log(nval) / log(2);
      int yu = 0;
      if (yr == floor(yr)) { //means not a decimal
        yu = 1;
      }
      if (nval == 2 || yu == 1) {
        wrongas1 = 1;
      }
    }

    int wrongas2 = 0;
    if (strcmp(fasso2, "direct") == 0) {
      wrongas2 = 1;
    }
    if (strcmp(fasso2, "assoc") == 0) {
      wrongas2 = 1;
    }
    if (fasso2[5] == ':') {
      nval = atoi( & fasso2[6]);
      double yr = log(nval) / log(2);
      int yu = 0;
      if (yr == floor(yr)) { //means not a decimal
        yu = 1;
      }
      if (nval == 2 || yu == 1) {
        wrongas2 = 1;

      }
    }

    unsigned long int cachSize1 = atoi(argv[1]);
    unsigned long int cachSize2 = atoi(argv[5]);
    double yr = log(cachSize1) / log(2);
    int worngcs1 = 0;
    if (yr == floor(yr)) { //means not a decimal
      worngcs1 = 1;
    }
    yr = log(cachSize2) / log(2);
    int worngcs2 = 0;
    if (yr == floor(yr)) { //means not a decimal
      worngcs2 = 1;
    }

    char * trace = argv[8];
    int blockSize = atoi(argv[4]);
    double yp = log(blockSize) / log(2);
    int worngbs = 0;
    if (yp == floor(yp)) { //means not a decimal

      worngbs = 1;
    }
    if (worngbs == 1 && worngcs1 == 1 && worngcs2 == 1 && wrongas1 == 1 && wrongas2 == 1 && wrongp1 == 1 && wrongp2 == 1) {
      int nval1; //set assoc;
      unsigned long int numofsets1 = 0;
      unsigned long int linespset1 = 0;
      int nval2; //set assoc;
      unsigned long int numofsets2 = 0;
      unsigned long int linespset2 = 0;
      char wOr;
      unsigned long int addr;
      unsigned long int tag1;
      unsigned long int setIndex1;
      unsigned long int tag2;
      unsigned long int setIndex2;

      if (strcmp(fasso1, "direct") == 0) { //if direct

        //Computation
        numofsets1 = cachSize1 / blockSize;;
        linespset1 = 1;

      } else if (strcmp(fasso1, "assoc") == 0) { //if fully assoc

        //Computation
        numofsets1 = 1;
        linespset1 = cachSize1 / blockSize;
      } else { //if n assoc
        if (fasso1[5] == ':') { //to verify first 6 say :

          nval1 = atoi( & fasso1[6]); //gives us the n-way connect value

          //Computation
          linespset1 = nval1;
          numofsets1 = cachSize1 / blockSize / nval1;
        }
      }

      if (strcmp(fasso2, "direct") == 0) { //if direct

        //Computation
        numofsets2 = cachSize2 / blockSize;;
        linespset2 = 1;

      } else if (strcmp(fasso2, "assoc") == 0) { //if fully assoc

        //Computation
        numofsets2 = 1;
        linespset2 = cachSize2 / blockSize;
      } else { //if n assoc
        if (fasso2[5] == ':') { //to verify first 6 say :

          nval2 = atoi( & fasso2[6]); //gives us the n-way connect value

          //Computation
          linespset2 = nval2;
          numofsets2 = cachSize2 / blockSize / nval2;
        }
      }

      unsigned long int offsetSize1 = log(blockSize) / log(2);
      unsigned long int setSize1 = log(numofsets1) / log(2);
      unsigned long int offsetSize2 = log(blockSize) / log(2);
      unsigned long int setSize2 = log(numofsets2) / log(2);

      struct block ** cache1 = malloc(numofsets1 * sizeof(block * ));
      for (unsigned long int r = 0; r < numofsets1; r++) {
        cache1[r] = malloc(linespset1 * sizeof(block));
      }

      for (unsigned long int r = 0; r < numofsets1; r++) {
        for (unsigned long int c = 0; c < linespset1; c++) {
          cache1[r][c].addr = 0;
          cache1[r][c].valid = 0;
          cache1[r][c].policy = policy1;
          cache1[r][c].tag = 0;
          cache1[r][c].index = 0;
        }
      }

      struct block ** cache2 = malloc(numofsets2 * sizeof(block * ));
      for (unsigned long int r = 0; r < numofsets2; r++) {
        cache2[r] = malloc(linespset2 * sizeof(block));
      }

      for (unsigned long int r = 0; r < numofsets2; r++) {
        for (unsigned long int c = 0; c < linespset2; c++) {
          cache2[r][c].addr = 0;
          cache2[r][c].valid = 0;
          cache2[r][c].policy = policy2;
          cache2[r][c].tag = 0;
          cache2[r][c].index = 0;
        }
      }

      FILE * traceF = fopen(trace, "r");
      while (fscanf(traceF, "%c %lx\n", & wOr, & addr) != EOF) {

        setIndex1 = (addr >> offsetSize1) & ((1 << setSize1) - 1);
        tag1 = addr >> (setSize1 + offsetSize1);

        setIndex2 = (addr >> offsetSize2) & ((1 << setSize2) - 1);
        tag2 = addr >> (setSize2 + offsetSize2);

        if (wOr == 'R') {
          write(cache1, cache2, tag1, tag2, addr, setIndex1, setIndex2, linespset1, linespset2, offsetSize2, setSize2);
        } else if (wOr == 'W') {
          write(cache1, cache2, tag1, tag2, addr, setIndex1, setIndex2, linespset1, linespset2, offsetSize2, setSize2);
          writes++;
        }

      } //end while

      miss2 = reads;
      printf("memread:");
      printf("%lu\n", reads);

      printf("memwrite:");
      printf("%lu\n", writes);

      printf("l1cachehit:");
      printf("%lu\n", hits1);

      printf("l1cachemiss:");
      printf("%lu\n", miss1);

      printf("l2cachehit:");
      printf("%lu\n", hits2);

      printf("l2cachemiss:");
      printf("%lu\n", miss2);

      for (int i = 0; i < numofsets1; i++) {
        free(cache1[i]);
      }
      free(cache1);
      for (int i = 0; i < numofsets2; i++) {
        free(cache2[i]);
      }
      free(cache2);
    } else {
      printf("error\n");
    }
  }
}
