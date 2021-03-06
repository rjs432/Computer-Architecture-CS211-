#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[argc + 1]) {
	if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r");
			long double dec;
			int dig;
			while (fscanf(f,"%Lf %d\n", &dec, &dig)!= EOF){
	//int dig = 3;
	//long double dec = 12.5;
		int flag = 0;
			if (dec < 1){
				flag = 1;
			}
			int poscount = 0;
			while(1 <= dec){
				if (1 <= (dec/2)){
					poscount++;
					dec = dec/2;
				}
				else{
					break;
				}
			}

			//broken down to 1.xxx

			long double deci = fmod(dec, 1); //gives after deci point
			//long int whole = dec - deci; //gives what is before the decimal point
			//printf("%Lf\n", deci);
			//printf("%ld\n", whole);
			// convert whole to bin
						//long double r = 0;
						//int count = 0; //tells us how many we have added
						//int i = 0;
						//int* binaryc = malloc(64 * sizeof(int));//correct order
						int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
						int* wholebinary = malloc(64 * sizeof(int));//hold the binary sequence in correct order
						int* decibinary = malloc(64 * sizeof(int));//holds binary for the deci
						for (int y = 0; y < 64; y++){ //populates the array
							binary[y] = 0;
							wholebinary[y] = 0;
							decibinary[y] = 0;
						}
						wholebinary[0]= 1; //puts in the 1 for the whole binary

						//the binary for the whole is done now do binary for the decimal


						long double mal = deci;
						int decimallen = 0;
						for(int t = 0; mal != 0; t++){
							decimallen++;
							mal = mal * 2;
							long double h = fmod(mal, 1); //gives after deci point
							 long int  add = mal - h; //gives what is before the decimal poi
							 mal=h;
							 if (add == 1){
								 decibinary[t]= 1;
								 //printf("1\n");
							 	}
							 else if (add == 0){
								 decibinary[t]= 0;
								 //printf("0\n");
							 	}
						}
						//now we print it out(should be number of dig behind the decimal point and should be a one infront (move - if have to)
						int negcount = 0;
						//int poscount = 0;
						int onepos =0;

						if (flag == 1){
							for (int r = 0; r < dig; r++){
								if (decibinary[r] == 1){
									negcount ++;
									onepos = r;
									break;
								}
								else if (decibinary[r] == 0){
									negcount++;
								}
							}
							int gg = 0;
							printf ("%d.", decibinary[onepos]);
							for (int t = onepos+1; t < dig+1; t++){
								printf ("%d", decibinary[t]);
								gg++;
							}
							if (gg < dig){
								while(gg<dig){
									printf("0");
									gg++;
								}
							}
							negcount = -1 * negcount;
							printf(" %d", negcount);
							printf("\n");
						}

						else if (flag == 0){
							printf ("%d.", wholebinary[0]);
						for (int r = 0; r < dig; r++){
							printf ("%d", decibinary[r]);
						}
						printf(" %d", poscount);
						printf("\n");
						}
							free(binary);//frees malloc
							free(wholebinary);
							free(decibinary);
		}
	}
}

