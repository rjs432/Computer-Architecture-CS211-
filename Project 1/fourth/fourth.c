#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printmat(int** mat, int n ){ //prints the matrix
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			printf("%d\t", mat[i][j]);
		}
		printf ("\n");
	}
}

void freeer (int** mat, int n){ //frees the mallocs
	for (int i = 0; i < n; i++){
		free(mat[i]);
	}
	free(mat);
}

int evenOodd (int n, int num){
	int ans = 0;
	if(num % n == 0){
		ans = 1;
	}
	else {
		ans = 0;
	}
	return ans;
}
int checker (int m , int n){
	int ans = 0;
	if (m == n){
		ans = 1;
	}
	else if (m < n){
		ans = 2;
	}
	else if (m > n){
		ans = 3;
	}
	return ans;
}

int main(int argc, char* argv[argc + 1]) {
	int n = atoi(argv[1]);
	//int n = 3;

	//if size taken in mod 2 != 0 then do this

	int size = n * n; //n by n square matrix
	int row = 0;
	int holder = 0;
	int rw;
	int col= n/2;
	int eoo;
	eoo = evenOodd(2, n);
	if (eoo == 0){ //if the matrix is not an even size

	//make 2d array malloc
	int** mat = malloc(n*sizeof(int*)); //creates array of pointers d
	for (int i = 0; i < n; i++){
		mat[i]= malloc(n*sizeof(int));
	}
		int num = 1;
		
		


	while(num <= size){
		if (num == 1){ // 1 always goes there
		rw = evenOodd(n, num);
		mat[0][n/2] = 1;
		}
		else{
	    	rw = evenOodd(n, num);
	        mat[row][col]=num;
			}
		int flag = checker(rw, holder); //expect 1
		col = col + 1;
		int flag1 = checker(col, n); //expect 1
	        row = row - 1;
		int flag3 = checker(row, holder); //expect 2
		
	        if ( flag == 1){
	            if (flag1 == 1){
	                col = 0; //maybe make 0
	            }
	            else if (flag3 == 2){
	                row = row + n;
	            }
	        }
	        else
	        	        {
	        	            row = row + 2;
	        	            col = col -1;
	        	        }
	        num++;
	    }

	    printmat(mat, n);
	    freeer(mat, n);
	}


			else{
				printf("error");
			}
	 return EXIT_SUCCESS;
}
