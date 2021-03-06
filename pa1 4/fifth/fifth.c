#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void printmat(int** mat, int n ){ //prints the matrix
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			printf("%d ", mat[i][j]);
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


double determinent(int** matrix, int size){

	   int count = 1;
	   int sizer = size - 1;
		int rec = 0;
	    int curr = 0;
	    int r = 0;
	    int c = 0;
	   
	    double determ = 0; // s is the sign + or - of the deterem
	    int** small = malloc(size*sizeof(int*)); //makes b
	    		for (int i =0; i < size; i++){
	    			small[i] = malloc(size*sizeof(int*));
	    		}

	    if(size == 1)
	    {
	        determ = matrix[0][0];
	    }
	    else if (size == 2){ //add on

	    	      determ = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	    }

	   else{
	        while( curr<size){
	         for( int row =0; row <size; row++){
	                for( int col =0; col <size; col++){
	                	int flag = checker(row, 0);
	                	int flag2 = checker(col, curr);
	                    if(flag != 1 && flag2 != 1){ //makes elemements not in the first row or same col
	                        small[r][c] = matrix[row][col]; //make that smaller matrix equal to the larger matrix at the point
	                        int flag3 = checker(c, (sizer-1));
	                        if(flag3 != 2 ){ //if not at the end of the row
	                        	c=0;//start at first col and increase row by 1
	                        	r++;
	                        }
	                        else{
	                          c++;
	                        }
	                    }
	                }
	            }
		int currentM = matrix[0][curr];
if (count ==1){
		rec = (currentM * determinent(small, sizer));
		 determ = determ + rec; //recursive case
	            count = 0;
}
else if (count == 0){
		rec = (currentM * determinent(small, sizer));
		rec = rec * -1;
 		 determ = determ + rec; //recursive case
	            count = 1;
}
 r = 0; // index of the smaller matrix
 c = 0;
curr++;
	        }
	    }
	    freeer(small, size);
	    return (determ);

	}

int main (int argc, char* argv[argc + 1]){

	FILE* f = fopen(argv[1], "r");
		int n;

		fscanf(f, "%d\n", &n); //reading in number of rows

		int** matrix = malloc(n*sizeof(int*));
		for (int i =0; i < n; i++){
			matrix[i] = malloc(n*sizeof(int*));
		}
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				fscanf(f, "%d", &matrix[i][j]); //reads values of the ith row
			}
			fscanf(f, "\n");
		}

		
	double det = determinent(matrix, n);
	printf("%g\n", det);
	freeer(matrix, n);
	fclose(f);
	return EXIT_SUCCESS;
}

