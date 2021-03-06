#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct graph{
	int* seen;
	int* distance;
	char * name;
	struct node** list;

};
struct node{
	int weight;
	size_t vertex;
	struct node* next;
};
struct ll{
	int data;// data of the node
	int pri;
	struct ll* next;//ptr to next node

};
struct ll *allocate (int ata)
{				//makes new node
  struct ll *insert = malloc (sizeof (struct ll));
  insert->data = ata;
  insert->next = 0;
  return insert;
}
int dfs(int i, int t, int* v, int* order, struct graph* directed){
	 struct node* adjList = directed->list[t]; //make adjlist the vertex of the que
	  struct node* temp = adjList;

	 v[t] = 1; //label as seen

	  while (temp != 0) {
	    if (v[temp->vertex] == 0) { //if not seen
	      i= dfs(i, temp->vertex, v,order, directed); //recursive
	    }
	    temp = temp->next;
	  }
	//printf("%d\n", t);
	  order[i]=t;
	  return i-1;
}
int* top(struct graph* directed, int num, char** converter) {
	int* v = malloc(num * sizeof(int*)); //make arr and make them all false
	//int ans=0;
	for (int i = 0; i < num; i++){
		v[i]=0;
	}
	int* order = malloc(num * sizeof(int*));
	for (int k = 0; k < num; k++){
			order[k]=0;
	}
	int ind = num -1; //tracks the insertion position of the next el
	for (int t = 0; t < num; t++){ //tracks node we curr proc
		if(v[t]==0){ //check if on visted node
			//int* visited = malloc(num * sizeof(int*)); //add nodes as we find them
			  ind=dfs(ind, t, v, order, directed);

		}
	}
	//for (int p = 0; p < num; p++){
		//printf("%d ",order[p]);
//}
//printf("\n");
	free(v);
	return order;
	//free(order);
	//for (int a = 0; a < num; a++){
	//free(order[a]);	
	//}
	//for (int n = 0; n < num; n++){
	//free(v[n]);	
	//}
	
}

void dij (struct graph* directed,int src, int num, char** converter){
	struct ll * head = 0;
	int* sorted = top(directed, num, converter);//top sort it
	//insert into ll
	for(int r = 0; r < num; r++){
	struct ll *insert = allocate (sorted[r]);
	      if (head == 0)
		{
		  head = insert;
		}

	      else
		{
		  struct ll *current = head;	//set current to head
		  while (current->next != 0)
		    {		//while not at the end
		      current = current->next;
		    }
		  //when at the end of the list Enque
		  current->next = insert;	//points the last element to insert

		}
	}

	int* distance = malloc(num * sizeof(int));
	
//initalize to inf
	for (int n = 0; n < num; n++){
	distance[n] = INT_MAX;
		}
	distance[src] = 0;
	

	//for (int u = 0; u < num; u++){
	while(head != 0){
	//pop
	int node = head-> data; //the front
		struct ll* tmp = head;
			head = head -> next;
			free(tmp);


		
		if (distance[node] != INT_MAX){
		 struct node* adjList = directed->list[node];
		struct node* temp = adjList;
		int v =0;
		while( temp != 0){
			//printf("node      %s\n", converter[node]);
			//printf("tempvertx %s\n", converter[temp->vertex]);
			//printf("tempweigh %ld\n", temp->weight);
			//printf("distahead %d\n", distance[node]);
			//printf("dtempvert %d\n", distance[temp->vertex]);
			//printf("\n");
			int newdist = distance[node] + temp->weight;
		if (distance[temp->vertex] > newdist){
			distance[temp->vertex] = newdist;
		}
		temp = temp -> next;
		v++;
	}
	}
}
//printf("\n");
	//int flag = 0;
	
	
	
	for (int n = 0; n < num; n++){
		if(distance[n] == INT_MAX){
			printf ("%s ", converter[n]);
			printf("INF\n");
		}
		else{
			printf ("%s ", converter[n]);
		printf("%d\n", distance[n]);
			}
	
}
printf("\n");
	free(distance);
	free(sorted);
}

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
//
//
//
//
////Read in info
	char** converter;
	size_t num; //number of vertex
		struct graph* undirected = malloc(sizeof(struct graph));
		if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r"); //reads number in

			char dori[21]; //Current vertex name

			fscanf(f,"%zu\n", &num); //first read in the # of vertex

	
			undirected -> list = malloc(num * sizeof(struct node*)); 
			undirected -> seen = malloc(num * sizeof(int*));
			undirected -> distance = malloc(num * sizeof(int*));

			 converter = malloc(num * sizeof(char*));
				
			for (size_t l = 0; l < num; l++){
			 //then read in the vertex names

				fscanf(f,"%s\n",dori);
				//char hi[21];
				converter[l]=malloc(21 * sizeof(char));
				strcpy(converter[l],dori);
				//printf("hello\n");
				//converter[l]= hi;
				undirected -> list[l] = 0; 
				undirected -> seen[l] = 0;
				undirected -> distance[l] = 2147483647;
				//topsort[l] = 0;
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
			//int* weight = malloc(num* sizeof(int));
int weig = 0;
			while (fscanf(f,"%s %s %d\n",a, b, &weig)!=EOF){ //read in the edges that will go till end of file
				size_t i;
				//size_t weig = 0;
			//printf("read: %s %s %ld\n",a, b, weig);
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
					size_t tempval = sd;
					int tmp = kl;
		                    if(sd >= 0 && kl >= 0 && move->vertex <= rob->vertex ) {
		                        tempval = rob->vertex;
					tmp = rob -> weight;
		                        rob->vertex = move->vertex;
					rob->weight = move->weight;
		                        move->vertex = tempval;
					move->weight = tmp;
		                    }
		                    move = move->next;
		                }
		                rob = rob->next;
		            }
		}


		}
		//end read of undirected graph
//	//end read of undirected graph
				size_t v;
				size_t count =0;
				//int flag = 0;
				size_t h;
					for (h = 0; h < num; h++){
					 //struct node* temp = undirected->list[h];
					    char* a = converter[h];
					for (v = 0; v < num; v++) {
						struct node* temp = undirected->list[v];
								 while (temp != 0) {
									if (strcmp(converter[temp->vertex], a) == 0){ //means indeg
	
										//flag = 1;
										count++;
										temp = temp->next;
									}
									else{
	break;
									//flag = 0;
									}

					}
					//printf("%zu\n", count);
					}
		}



	if (fopen(argv[2], "r")){
		FILE* f = fopen(argv[2],"r");
		
		char g[21];
			while (fscanf(f,"%s\n", g)!=EOF){
				for(int i = 0; i < num; i++){
					if(strcmp(g, converter[i])==0){
//printf("hellsmd\n");
						 int * seen = malloc(num* sizeof(int*));
						for (int i = 0; i < num; i++){
							seen[i] = 0;
						}
						//printf("\n");
						dij(undirected,i,  num, converter);
						//DFS(undirected, seen, i, num, converter);
						free(seen);
						//free(topsort);
					}
				}
				//printf("\n");
		}
//printf("\n");
	}//end read file of query
	free(undirected->seen);
	free(undirected -> distance);
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


