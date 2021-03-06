#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

    typedef struct block{
	char * policy;
	unsigned long int tag;
	int valid;
	unsigned long int addr;
	unsigned long int poltime;
	unsigned long int index;

	}block;

	unsigned long int reads = 0; //the total number of reads
	unsigned long int writes = 0; // the total number of writes
	unsigned long int hits = 0; // the total number of cache hits
	unsigned long int miss = 0; // the total number of cache misses

	char * policy = "a";
	unsigned long int polcount;

int computer (struct block** cache, unsigned long int setIndex, unsigned long int r){
	int flag = 0;
	if(cache[setIndex][r].valid == 0 &&  strcmp(cache[setIndex][r].policy, "fifo")==0){
		flag = 1;
	}
	else if(cache[setIndex][r].valid == 0 &&  strcmp(cache[setIndex][r].policy, "lru")==0){
		flag = 2;
	}
	else if(cache[setIndex][r].valid == 1 &&  strcmp(cache[setIndex][r].policy, "fifo")==0){
			flag = 3;
		}
	else if(cache[setIndex][r].valid == 1 &&  strcmp(cache[setIndex][r].policy, "lru")==0){
		flag = 4;
	}
	return flag;
}

void cacheSim(struct block** cache, unsigned long int tag,unsigned long int addr,unsigned long int setIndex,unsigned long int rob, unsigned long int linespset,char * fasso){
	if (( strcmp(fasso, "direct") == 0)){
	unsigned long int smallest;
	int flag2 = 0;
for(unsigned long int r = 0; r < linespset; r++){
	int flag = computer (cache, setIndex, r);
		smallest = 0;
	unsigned long int s = cache[setIndex][r].index;
		unsigned long int t = cache[setIndex][r].tag;
	 if (flag == 3){
		if( s == setIndex && t == tag){
			hits++;
			break;
		}
		}
		else if (flag == 4){
			if( s == setIndex && t == tag){
				polcount++;
				cache[setIndex][r].poltime = polcount;
				hits++;
				break;
			}
		}
	else if(flag == 1 || flag == 2){
		cache[setIndex][r].index = setIndex;
		cache[setIndex][r].valid = 1;
		cache[setIndex][r].addr = addr;
		cache[setIndex][r].tag = tag;
		polcount++;
		cache[setIndex][r].poltime = polcount;
		miss++;
		reads++;
	break;
	}

	
		for(unsigned long int f = 0; f < linespset; f++){
			if (f == r){
				if (f == rob){
				flag2 = 5;
				}
				break;
			}
		}
		 if(flag2 == 5){
				miss++;
				reads++;
			for(unsigned long int i = 0; i < linespset; i++){
				unsigned long int fir = cache[setIndex][smallest].poltime;
				unsigned long int sec = cache[setIndex][i].poltime;
				if(cache[setIndex][i].index == cache[setIndex][smallest].index && fir > sec ){
					polcount++;
					smallest = i;
					
				}
			}
				
				cache[setIndex][smallest].index = setIndex;
				cache[setIndex][smallest].valid = 1;
				cache[setIndex][smallest].addr = addr;
		        	cache[setIndex][smallest].tag = tag;
		        	cache[setIndex][smallest].poltime = polcount;
		        break;
			}
		}

		}

else{
	unsigned long int smallest;
	int flag2 = 0;
for(unsigned long int r = 0; r < linespset; r++){
	int flag = computer (cache, setIndex, r);
	if(rob == r){
		flag2 = 5;
		smallest = 0;
	}
	else{
		flag2 = 6;
	}
		unsigned long int s = cache[setIndex][r].index;
		unsigned long int t = cache[setIndex][r].tag;
	if (flag == 3){
		if(s == setIndex && t == tag){
			hits++;
			break;
		}
		}
		else if (flag == 4){
			if(s == setIndex && t == tag){
				polcount++;
				cache[setIndex][r].poltime = polcount;
				hits++;
				break;
			}
		}
	else if(flag == 1 || flag == 2){
		cache[setIndex][r].index = setIndex;
		cache[setIndex][r].valid = 1;
		cache[setIndex][r].addr = addr;
		cache[setIndex][r].tag = tag;
		polcount++;
		cache[setIndex][r].poltime = polcount;
		miss++;
		reads++;
	break;
	}


		 if(flag2 == 5){
				miss++;
				reads++;
			for(unsigned long int i = 0; i < linespset; i++){
				unsigned long int fir = cache[setIndex][smallest].poltime;
				unsigned long int sec = cache[setIndex][i].poltime;
				if(cache[setIndex][i].index == cache[setIndex][smallest].index && fir > sec ){
					smallest = i;
				}
			}
					
				cache[setIndex][smallest].index = setIndex;
				cache[setIndex][smallest].valid = 1;
				cache[setIndex][smallest].addr = addr;
		        	cache[setIndex][smallest].tag = tag;
				polcount++;
		        	cache[setIndex][smallest].poltime = polcount;
		        break;
			}
		}
}
}


int main(int argc, char** argv){
if (argc != 6){
	printf("error\n");
}
else {
	 policy = argv[3];
	 int wrongp = 0;
	 if ( strcmp(policy, "lru")==0 || strcmp(policy, "fifo")==0 ){
		 wrongp = 1;

	 }


	 int wrongas = 0;
	char * fasso = argv[2];
	  int nval;//set assoc;
	if ( strcmp(fasso, "direct") == 0){
		wrongas = 1;
	}
	if (strcmp(fasso, "assoc") == 0){
		wrongas = 1;
	}
	if (fasso[5] ==':'){
		 nval = atoi(&fasso[6]);
		 double yr = log(nval)/log(2);
		 int yu = 0;
		 if (yr == floor(yr)){ //means not a decimal
			 yu = 1;
		 }
		 if (nval == 2 || yu ==1 ){
			 wrongas = 1;

		 }
	}


	unsigned long int cachSize = atoi(argv[1]);
	 double yr = log(cachSize)/log(2);
			 int worngcs = 0;
			 if (yr == floor(yr)){ //means not a decimal
				 worngcs = 1;
			 }

    char* trace = argv[5];

    int blockSize = atoi(argv[4]);
	 double yp = log(blockSize)/log(2);
			 int worngbs = 0;
			 if (yp == floor(yp)){ //means not a decimal

				 worngbs = 1;
			 }

	if (worngbs == 1 && worngcs ==1 && wrongas ==1 &&wrongp ==1){

			//printf ("ere\n");

    unsigned long int numofsets = 0;
    unsigned long int linespset = 0;
    char wOr;
    unsigned long int addr;
    unsigned long int tag;
    unsigned long int setIndex;



  if(strcmp(fasso, "direct") == 0){ //if direct

  			//Computation
	  numofsets = cachSize/blockSize;;
	  linespset = 1;

  	}


  	else if(strcmp(fasso, "assoc") == 0){ //if fully assoc

  			//Computation
  		numofsets = 1;
  		linespset = cachSize/blockSize;
  	}


  	else{ //if n assoc
  		if(fasso[5] ==':'){ //to verify first 6 say :

  			 nval = atoi(&fasso[6]); //gives us the n-way connect value

  			//Computation
  			linespset = nval;
  			  numofsets = cachSize/blockSize/nval;
  		}
  	}

	unsigned long int rob = linespset-1;
	unsigned long int offsetSize = log(blockSize)/log(2);
	unsigned long int setSize = log(numofsets)/log(2);

struct block** cache = malloc(numofsets * sizeof(block*));
for(unsigned long int r = 0; r < numofsets; r++){
  cache[r] = malloc(linespset * sizeof(block));
}

for(unsigned long int r = 0; r < numofsets; r++){
  for(unsigned long int c = 0; c < linespset; c++){
	   cache[r][c].addr = 0;
       cache[r][c].valid = 0;
       cache[r][c].policy = policy;
       cache[r][c].tag = 0;
       cache[r][c].index = 0;
  }
}

 FILE * traceF = fopen(trace, "r");
 while(fscanf(traceF, "%c %lx\n", &wOr, &addr) != EOF){
	 setIndex = (addr >> offsetSize) & ((1 << setSize)-1);
	 tag = addr >> (setSize + offsetSize);

	 if(wOr == 'R'){
		 cacheSim(cache, tag, addr, setIndex, rob, linespset, fasso);
	}
	 else if(wOr == 'W'){
		cacheSim(cache, tag, addr, setIndex, rob, linespset, fasso);
		writes++;
		
	}


}//end while



 printf("memread:");
 printf("%lu\n", reads);

 printf("memwrite:");
 printf("%lu\n", writes);

 printf("cachehit:");
 printf("%lu\n", hits);

 printf("cachemiss:");
 printf("%lu\n", miss);

 for(int i = 0;i < numofsets; i++){
   free(cache[i]);
 }
 free(cache);
	}
	else {
		printf("error\n");
	}
}
}
