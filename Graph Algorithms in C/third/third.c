#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graph{
	int* seen;
	char * name;
	struct node** list;

};
struct node{
	size_t vertex;
	struct node* next;
};


struct ll{
		int data;// data of the node
		struct ll* next;//ptr to next node

	};
struct ll *allocate (int ata)
{				//makes new node
  struct ll *insert = malloc (sizeof (struct ll));
  insert->data = ata;
  insert->next = 0;
  return insert;
}


// Check if the queue is empty
int empty(struct ll* head, size_t num) {
	int count = 0;
	struct ll *current = head;	//set current to head
		  while (current != 0)
		    {		//while not at the end
			count ++;
		      current = current->next;
		    }
return count;
}




// BFS algorith------PSUDO provided
//1  procedure BFS(G, root) is
//2      let Q be a queue
//3      label root as discovered
//4      Q.enqueue(root)
//5      while Q is not empty do
//6          v := Q.dequeue()
//7          if v is the goal then
//8              return v
//9          for all edges from v to w in G.adjacentEdges(v) do
//10             if w is not labeled as discovered then
//11                 label w as discovered
//12                 Q.enqueue(w)
void bfs (struct graph* undirected, int startex, int num, char** converter) { //vertex is the node you want to start the search at
struct ll * head = 0; //2      make queue
	for(size_t uy = 0; uy < num; uy++){
	undirected->seen[uy] = 0; //3      label root as discovered
	}

  undirected->seen[startex] = 1;
  struct ll *insert = allocate (startex); //4      Q.enqueue(root)
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

	



  while (empty(head,num) != 0) { //5      while Q is not empty do
	
    int currtex =head-> data; //the front
		struct ll* tmp = head;
			head = head -> next;
			free(tmp); 

    printf("%s ", converter[currtex]);

    struct node* trav = undirected->list[currtex];
    while (trav != 0) { //9          for all edges from v to w in G.adjacentEdges(v) do
      int adjtex = trav->vertex;
      if (undirected->seen[adjtex] == 0) { //10          if w is not labeled as discovered then
       undirected->seen[adjtex] = 1; //11                 label w as discovered
        //12                 Q.enqueue(w)
	struct ll *insert = allocate (adjtex); //4      Q.enqueue(root)
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
      trav = trav->next;
    }
  }
//free(q);
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




	char** converter;
		size_t num; //number of vertex
		struct graph* undirected = malloc(sizeof(struct graph));
		if (fopen(argv[1],"r")){
			FILE* f = fopen(argv[1],"r"); //reads number in

			char dori[21]; //Current vertex name

			fscanf(f,"%zu\n", &num); //first read in the # of vertex


			undirected -> list = malloc(num * sizeof(struct node*)); 
			 converter = malloc(num * sizeof(char*));
			undirected -> seen = malloc(num * sizeof(int));
			
			for (size_t l = 0; l < num; l++){
			 //then read in the vertex names

				fscanf(f,"%s\n",dori);
				//char hi[21];
				converter[l]=malloc(21 * sizeof(char));
				strcpy(converter[l],dori);
				//printf("hello\n");
				//converter[l]= hi;
				undirected -> list[l] = 0; //MAKE THE HEAD OF LIST THE STRING
				undirected -> seen[l]=0;
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

if (fopen(argv[2], "r")){
		FILE* f = fopen(argv[2],"r");
		char g[21];
			while (fscanf(f,"%s\n", g)!=EOF){
				for(int i = 0; i < num; i++){
					if(strcmp(g, converter[i])==0){

						bfs(undirected, i, num, converter);
					}
				}
				printf("\n");
		}

	}//end read file of query
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


