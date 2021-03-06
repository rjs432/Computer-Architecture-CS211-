#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int data;// data of the node
	struct node* next;//ptr to next node

};

struct node* allocate (int data){ //makes new node
	struct node* insert = malloc(sizeof(struct node));
				insert->data = data;
				insert->next = 0;
				return insert;
}

void freeer (struct node* t){
	if (t == 0)return;
	freeer(t-> next);
	free(t);
	return;
}

int main(int argc, char* argv[argc + 1]) {
	struct node* head=0; // intialize head to 0
	int bo = 0;
//Read in info
if (fopen(argv[1],"r")){
FILE* f = fopen(argv[1],"r"); //reads number in
	char dori [7]; //for the taking in of d or i
	int num;
	while (fscanf(f,"%s %d\n",dori, &num)!=EOF){
		bo = 1;

if (strcmp(dori, "INSERT")==0){
//INSERT
struct node* insert = allocate(num);

if (head == 0){ //if the head is not assigned yet (LL is on its on its own
	head = insert;
}

else{ //traverse to find where to insert
struct node* current;
current = head; //set current to head
	if(head->data > insert->data && head->data != insert->data){
		insert-> data = num;
		insert-> next = head;
		head = insert;
	}
	else{
        while (current->next != 0 ) {//while not at the end of the list and the value is less then the insert
        	if(current->next->data < insert->data){
        	current = current->next;
        	}
        	else{
        		break;
        	}
        }
        //breaks out when at the node before it is greater
         int yiy = 0;
  	struct node* i = head;
  	while (i->next !=0){
  	if(insert -> data == i->data){
  		yiy =1;
  	}
  	i= i->next;
  	}
  	if (yiy != 1){
          insert->next = current->next;
          current->next = insert;

        }
        else{
        	free(insert);
        }
    }
}
struct node* current2;
current2 = head;
if (current2 == 0){// if empty print empty
	printf("EMPTY");
}
while (current2 != 0){
	printf("%d ", current2 ->data);
	current2 = current2 -> next;
}
printf("\n");
}//end insert


if (strcmp(dori,"DELETE") == 0){
//DELETE
int toDelete = num;// number we looking to delete

	if(head == 0){// if null
		continue;
	}
	else{
		struct node* current1;// what we iterate with
		current1 = head; //set current to head

			if (head -> data == toDelete){
				 struct node *tempr = head;
						  head = head->next;

						  // deletes temp which is still pointing to front
									free(tempr);
									struct node* current2;
											        current2 = head;
											        if (current2 == 0){// if empty print empty
											        	printf("EMPTY");
											        }
											        while (current2 != 0){
											        	printf("%d ", current2 ->data);
											        	current2 = current2 -> next;
											        }
											        printf("\n");
			}
			else{
		        while (current1->next != 0 && current1->next->data != toDelete) { //while not at the end of the list and the value is not equal to the supposes
		        	current1 = current1->next;
		        }
		        if (current1 -> next -> data == toDelete){
		        	//struct node* temp  = current1;
		        	//current1->next = temp->next;
		        	//free(temp);
		        	struct node* temp = current1->next;
		        	current1-> next = temp->next;
		        	free(temp);

		        }
		        struct node* current2;
		        current2 = head;
		        if (current2 == 0){// if empty print empty
		        	printf("EMPTY\n");
		        }
		        while (current2 != 0){
		        	printf("%d ", current2 ->data);
		        	current2 = current2 -> next;
		        }
		        printf("\n");
		    }
	}
	}

	}

}
	freeer(head);

if (bo == 0){
	 printf("error");
}

}
