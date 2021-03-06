#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[argc + 1]) {
	FILE* f = fopen(argv[1],"r"); //reads number in
		int num;
	while (fscanf(f,"%d\n", &num)!=EOF){

		int tOrF1 = 0;// equals false init
			int tOrF2 = 0;
			int tOrF = 1;

			char yes[] = "yes";
			char no[] = "no";

			int primeRem;
			int twin1 = num - 2;
			int twin2 = num + 2;
			
			
			if (num <= 1){
					tOrF = 0;
						}
			else{
			for(int i = 2; i < num/2; i++){ //checks num
				primeRem = num % i;
				
		
				if(primeRem == 0){
					tOrF = 0; //not prime
					break;
				}
		}
			}
			if (tOrF != 0){
	if (num <= 1){
		tOrF1 = 0;
	}
	else if (twin1 == 2 || twin1 == 3 || twin1 == 5 || twin1 == 7){
		tOrF1 = 1;
	}
	else if (twin2 == 2 || twin2 == 3 || twin2 == 5 || twin2 == 7){
		tOrF2 = 1;
		}

	else{
	for(int i = 2; i < twin1/2; i++){ //checks twin1
		primeRem = twin1 % i;

		if(primeRem == 0){
			tOrF1 = 0; //not prime
			break;
		}
		else{
			tOrF1 = 1; //its prime
		}
	}
	for(int i = 2; i < twin2/2; i++){ //checks twin2
			primeRem = twin2 % i;
			if(primeRem == 0){
				tOrF2 = 0; //its not prime
				break;
			}
			else{
				tOrF2 = 1; //its prime
			}
		}
	}


	if (tOrF1 == 0 && tOrF2 ==0){
		printf("%s\n", no);
	}

	else if (tOrF1 == 1 || tOrF2 == 1){
			printf("%s\n", yes);
		}
	}
			else{
				printf("%s\n", no);
			}
	}
	fclose(f);
	return EXIT_SUCCESS;

}
