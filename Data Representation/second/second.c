#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
	//Read in info
		if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r");
			int dig; //how many digits
			int r;
			signed long dec; //the number
			while (fscanf(f,"%ld %d\n", &dec, &dig)!= EOF){

		if(dec >= 0){ //if positive


							long pow = 1;
							long goal =0;
							for (long i = 0; i < 64; i++){
								
								pow = 1;
								if(i == 0){
								pow = 1;		

								}
								else if (i == 1){
								pow = 2;
								}
								else{
								int count = i;
								while (count != 1){
									pow = pow * 2;
									count--;
								}
									//printf ("%lu\n", pow);
								}
								if ((-1* (pow))<= dec && dec <= (pow)){
									int t =0;									
									while (pow !=1){
										pow = pow/2;
										t++;
									}
									t++;
									//printf("p %d\n", t);
									goal = t;
									break;	
								}
								 
							} //change to long max
							if (dig == 1 && dec == 1){
								printf("0");
								printf("\n");
							}
							else if (dig == 2 && dec == 2){
								printf("01");
								printf("\n");
							}
							else if (goal > dig){
								for (int i = 0; i < dig; i++){
									if (i == 0){
									printf("0");
									}
									else{
									printf("1");
									}
								}
								printf("\n");
							}

			else{
			int r = 0;
			int count = 0; //tells us how many we have added
			int i = 0;
			int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
			for (int y = 0; y < 64; y++){ //populates the array
				binary[y] = 0;
			}
			while(dec > 0){
				r = dec % 2; //tells us if 0 or 1
				//printf("%d\n", r);
				dec = dec/2; //drops our decimal to the next power of 2
				if (i <= dig){ //except up to and including the given dig
				binary[i]= r; //0 or 1
				i++;
				count++;
				}
			}
				while (count < dig ){ //the pre 0's if the number of dig is greater than the binary form
					printf("0");
					count++;
					}
			//printf("%d", count);
				for (long u = i- 1; u >= 0; u--){ //prints out the reversed list in the correct order
					if (u < dig){
					printf("%d", binary[u]); //print up to the given dig
					}
					
				}

				printf("\n");
				free(binary);//frees malloc
				}
			}
			//end of if pos

			
			else if (dec < 0){
			//printf("error\n");
							dec = dec * -1;
							long pow = 1;
							long goal =0;
							for (long i = 0; i < 64; i++){
								
								pow = 1;
								if(i == 0){
								pow = 1;		

								}
								else if (i == 1){
								pow = 2;
								}
								else{
								int count = i;
								while (count != 1){
									pow = pow * 2;
									count--;
								}
									//printf ("%lu\n", pow);
								}
								if ((-1* (pow))<= dec && dec <= (pow)){
									int t =0;									
									while (pow !=1){
										pow = pow/2;
										t++;
									}
									t++;
									//printf("p %d\n", t);
									goal = t;
									break;	
								}
								 
							} //change to long max
							if (goal > dig){
								for (int i = 0; i < dig; i++){
									if (i == 0){
									printf("1");
									}
									else{
									printf("0");
									}
								}
								printf("\n");
							}
							else{
							int count = 0; //tells us how many we have added
							int i = 0;
							int* binary = malloc(64 * sizeof(int)); //hold the binary sequence in reverse
							int* holder = malloc(64 * sizeof(int));
							for (int y = 0; y < 64; y++){ //populates the array
								binary[y] = 0;
								holder[y] = 0;
							}
							while(dec > 0){
								r = dec % 2; //tells us if 0 or 1
								//printf("%d\n", r);
								dec = dec/2; //drops our decimal to the next power of 2
								if (i <= dig){ //except up to and including the given dig
								binary[i]= r; //0 or 1
								i++;
								count++;
								}
							}
								//int two = i;
								int ind;
								for (ind = 0; count < dig; ind++ ){ //the pre 0's if the number of dig is greater than the binary form
									//printf("0");
									holder[ind] = 0;
									count++;
									}
								//ind++;//up count to the next index
							//printf("%d", count);
								for (long u = i- 1; u >= 0; u--){ //prints out the reversed list in the correct order
									if (u < dig){
									//printf("%d", binary[u]); //print up to the given dig
									int r = binary[u];
									holder[ind] = r; //put it in the array at index
									ind++;
									}

									}
								

								//do the neg part
								//first switch all the 1s and 0s (ones comp)
								for (int t = 0; t < dig; t++){
									if (holder[t] == 1){
										holder[t] = 0;
									}
									else if (holder[t] == 0){
										holder[t] = 1;
									}
								}
								//add one to ones complement to get 2s complement
								//int flag = 0; //tells if we placed a remainder
								for (long u = dig- 1; u >= 0; u--){
									if(holder[u] == 1){ //1+1 is 0 and continue that remainder till at the end
										holder[u] = 0;

									}
									else if (holder[u] == 0){ //if 0 then 0+1 is 1 and you are done
										holder[u] = 1;
										//flag = 1;
										break;
									 }

								}
								for (int p = 0; p < dig; p++){
									printf("%d", holder[p]);
									}


								printf("\n");
								free(binary);//frees malloc
								free(holder);
			}
}

			}
		}

}
