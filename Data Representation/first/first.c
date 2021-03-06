#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char* argv[argc + 1]) {
	//Read in info
		if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r");
			int dig;
			//int binary [33];
			//int count = 0;
			int r;
			unsigned long decimal;
			//int i = 0;
			while (fscanf(f,"%lu %d\n", &decimal, &dig)!= EOF){
			int count = 0;
			int i = 0;
			int* binary = malloc(64 * sizeof(int));
			for (int y = 0; y < 64; y++){
				binary[y] = 0;
			}
			while(decimal > 0){
				r = decimal % 2;
				//printf("%d\n", r);
				decimal = decimal/2;
				if (i <= dig){
				binary[i]= r; //0 or 1
				i++;
				count++;
				}
			}
				while (count < dig ){
					printf("0");
					count++;
					}
			//printf("%d", count);
				for (long u = i- 1; u >= 0; u--){
					if (u < dig){
					printf("%d", binary[u]);
					}
			
					}
				
				printf("\n");
				free(binary);
				}

		}
	
}
