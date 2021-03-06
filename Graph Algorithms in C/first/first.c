#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graph{
	char * name;
	struct node** list;
};
struct node{
	size_t vertex;
	struct node* next;
};
struct ll{
	char* data;// data of the node
	struct ll* next;//ptr to next node

};
int checker (struct node* a, char r, struct graph* b, char s){
	int flag = 0;	
	if (r == 'r'){
		if (a == 0){
			flag = 1;
		}
		else if (a != 0){
			flag = 0;
		}
	}
	else if (s == 's'){
		if (b == 0){
			flag = 1;
		}
		else if (b != 0){
			flag = 0;
		}
	}
	return flag;
}

int main(int argc, char* argv[argc + 1]) {




//Read in info
	char** converter;
	size_t num; //number of vertex
	struct graph* undirected = malloc(sizeof(struct graph));
	if (fopen(argv[1],"r")){
		FILE* f = fopen(argv[1],"r"); //reads number in

		char dori[21]; //Current vertex name

		fscanf(f,"%zu\n", &num); //first read in the # of vertex

//		printf("%d\n", num);

		 converter = malloc(num * sizeof(char*));
		undirected -> list = malloc(num * sizeof(struct node*)); 
		
		
		for (size_t l = 0; l < num; l++){
		 //then read in the vertex names

			fscanf(f,"%s\n",dori);
			//char hi[21];
			converter[l]=malloc(21 * sizeof(char));
			strcpy(converter[l],dori);
			undirected -> list[l] = 0; 
		}

	int c = 0;
	  for (size_t s = 1; s < num; s++) {
	 	c = num - s;
   	 size_t i = 0;
		while(i < c){
      if (strcmp(converter[i], converter[i+1])>0) {
        char tmp[21];
	//bubble sort swap
	strcpy(tmp, converter[i]);
        strcpy(converter[i], converter[i + 1]);
        strcpy(converter[i + 1], tmp);
      }
	i++;
    }
  }



		struct node* join;
		struct node*joi;
		char* a = malloc(21 *sizeof(char));
		char* b = malloc(21 * sizeof(char));
		while (fscanf(f,"%s %s\n",a, b)!=EOF){ //read in the edges that will go till end of file
			size_t i;
		//printf("read: %s %s\n",a, b);
			for( i =0; i < num; i++){
			if (strcmp(converter[i], a) ==0){
				//printf("a: %s\n",a);
				break;
			}
		}
//printf("ind: %d\n",i);
			size_t o;
			 for( o =0; o < num; o++){
				 if (strcmp(converter[o], b) ==0){
					//printf("b: %s\n",b);
					break;
					}
				}
//printf("ind: %d\n",o);
			 join = malloc(sizeof(struct node));
						//strcpy(join->vertex, a);
			join -> vertex = i; //make the name of the vertex

						//join -> next = 0; //point it to null
			//edge maker
			  join->next = undirected ->list[o];
			  undirected->list[o] = join;

			   joi = malloc(sizeof(struct node));
			  joi -> vertex = o;
			 // printf ("jj %s\n" ,join -> vertex );
			  joi->next = undirected ->list[i];
			  undirected->list[i] = joi;

		}
			//put in alphabetical order sorting each vertex
		for (size_t d = 0; d < num; d++){
			struct node *move;
			struct node *rob = undirected->list[d];
			for (size_t kl = 0; checker(rob, 'r', undirected, 'y') ==0; kl++){
		            move = rob->next;
		             for (size_t sd = 0; checker(move, 'r', undirected, 'y') ==0; sd++) {
					int tempval = sd;
		                    if(sd >= 0 && kl >= 0 && move->vertex <= rob->vertex ) {
		                        tempval = rob->vertex;
		                        rob->vertex = move->vertex;
		                        move->vertex = tempval;
		                    }
		                    move = move->next;
		                }
		                rob = rob->next;
		            }
		}


	free(a);
	free(b);
//	free(join);
//		free(joi);
	}
	//end read of undirected graph




	if (fopen(argv[2], "r")){
		FILE* f = fopen(argv[2],"r");
		char k;
		char g[21];
			while (fscanf(f,"%c %s\n",&k, g)!=EOF){

			if (k == 'd'){ //print out the # of edges
				size_t count = 0;
				size_t i = 0;
				for(i = 0; i < num; i++){
					if (strcmp(converter[i], g)==0){
						 break;
						}
					}
				struct node* temp = undirected->list[i];
					while (checker(temp, 'r', undirected, 'y') ==0) {
						 count++;
						temp = temp->next;
					}
				printf("%zu\n", count);
			}


			else if (k == 'a'){ //print out the adj list
				size_t v;
				 for (v = 0; v < num; v++) {
					 if (strcmp(converter[v], g)==0){
					  struct node* temp = undirected->list[v];
						    while (checker(temp, 'r', undirected, 'y') ==0) {
							char* a = converter[temp->vertex];
						      printf("%s ",a);
						      temp = temp->next;
						    }
						    printf("\n");
					}
				 }

			}
		}
	}//end read file of query
//free everything
if((checker(0,'t',undirected, 's') == 0) || undirected->list != 0){
	size_t vertex = 0;
            while(vertex < num){
               struct node* current =undirected->list[vertex];
		while(checker(current, 'r', undirected, 'y') ==0){
                    struct node *temp = current;
                    current = current->next;
                    free(temp);
                }
		vertex++;
            }
         free(undirected->list);
        free(undirected);
    }



	for (int n = 0; n < num; n++){
	free(converter[n]);	
	}
	free(converter);
	//free(join);
	//free(joi);


}//end main
