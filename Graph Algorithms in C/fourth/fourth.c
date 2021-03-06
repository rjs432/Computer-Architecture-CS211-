#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graph{
	int* seen;
	char * name;
	struct node** list;

};
struct node{
	int weight;
	size_t vertex;
	struct node* next;
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

////DFS- PSUDO Provided
////procedure DFS(G, v) is
////    label v as discovered
////    for all directed edges from v to w that are in G.adjacentEdges(v) do
////        if vertex w is not labeled as discovered then
////            recursively call DFS(G, w)
void DFS(struct graph* directed, size_t vertex, int num, char** converter, int count) {
  struct node* adjList = directed->list[vertex]; //make adjlist the vertex of the q

  struct node* temp = adjList;

  directed->seen[vertex] = 1; ///    label v as discovered
 printf("%s ", converter[vertex]);
if (count == num){
printf("\n");
}
  while (temp != 0) {//    for all directed edges from v to w that are in G.adjacentEdges(v) do
    if (directed->seen[temp->vertex] == 0) {// if vertex w is not labeled as discovered then
      DFS(directed, temp->vertex, num, converter, count+1); //recursively call DFS(G, w)
    }
    temp = temp->next;
  }
//return holder;
}
//
int main(int argc, char* argv[argc + 1]) {

////Read in info
	char** converter;
	size_t num; //number of vertex
		struct graph* undirected = malloc(sizeof(struct graph));
		if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r"); //reads number in

			char dori[21]; //Current vertex name

			fscanf(f,"%zu\n", &num); //first read in the # of vertex

	//		printf("%d\n", num);
	
			undirected -> list = malloc(num * sizeof(struct node*)); 
			undirected -> seen = malloc(num * sizeof(int*));
			 converter = malloc(num * sizeof(char*));
			
			for (size_t l = 0; l < num; l++){
			 //then read in the vertex names

				fscanf(f,"%s\n",dori);
				//char hi[21];
				converter[l]=malloc(21 * sizeof(char));
				strcpy(converter[l],dori);
				//printf("hello\n");
				//converter[l]= hi;
				undirected -> list[l] = 0; //MAKE THE HEAD OF LIST THE STRING
				undirected -> seen[l] = 0;
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


			char* a = malloc(21 *sizeof(char));
			char* b = malloc(21 * sizeof(char)); 
int weig = 0;
			while (fscanf(f,"%s %s %d\n",a, b, &weig)!=EOF){ //read in the edges that will go till end of file
				size_t i;
				//size_t weig = 0;
			//printf("read: %s %s %zu\n",a, b, weig);
				for( i =0; i < num; i++){
				if (strcmp(converter[i], a) ==0){
					//printf("a: %s\n",a);
					break;
				}
			}
				size_t u;
				for( u =0; u < num; u++){
							if (strcmp(converter[u], b) ==0){
								//printf("a: %s\n",a);
								break;
							}
						}

	//printf("ind: %d\n",i);

	//printf("ind: %d\n",o);
				struct node* join = malloc(sizeof(struct node));
							//strcpy(join->vertex, a);
				join -> vertex = u; //make the name of the vertex
				join -> weight = weig;
							//join -> next = 0; //point it to null
				//edge maker
				  join->next = undirected ->list[i];
				  undirected->list[i] = join;

			}
free(a);
free(b);
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

		
		}
		//end read of undirected graph
//	//end read of undirected graph
int co = 0;
		DFS(undirected, 0, num, converter, co);
		
		for(size_t y = 0; y < num; y++){
		if (undirected-> seen[y] ==0){
			DFS(undirected, y, num, converter,co);
	}
}
//for(size_t y = 0; y < num; y++){

		//printf("%d ",converter[holder[num]]);
	//}
//printf("\n");

	//free
free(undirected->seen);
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

}//end main


