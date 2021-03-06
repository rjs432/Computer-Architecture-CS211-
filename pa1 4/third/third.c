#include <stdio.h>
#include <stdlib.h>
#include <string.h>









struct node
{
  int data;			// data of the node
  struct node *next;		//ptr to next node

};
struct node *allocate (int);

struct node *
allocate (int data)
{				//makes new node
  struct node *insert = malloc (sizeof (struct node));
  insert->data = data;
  insert->next = 0;
  return insert;
}

void
freeer (struct node *t)
{
  if (t == 0)
    return;
  freeer (t->next);
  free (t);
  return;
}


int
main (int argc, char *argv[argc + 1])
{
  struct node *head = 0;

  //Read in info
  if (fopen (argv[1], "r"))
    {				//works to read in string and int
      FILE *f = fopen (argv[1], "r");	//reads number in
      char dori[8];
      int num;
      while (fscanf (f, "%s ", dori) != EOF)
	{
	



	 	//makes new node




	  //enque
	  if (strcmp (dori, "ENQUEUE") == 0)
	    {			//works
		  fscanf(f, "%d ", &num);
		  struct node *insert = allocate (num);

	      if (head == 0)
		{
		  head = insert;
		}

	      else
		{
		  struct node *current = head;	//set current to head
		  while (current->next != 0)
		    {		//while not at the end
		      current = current->next;
		    }
		  //when at the end of the list Enque
		  current->next = insert;	//points the last element to insert

		}

	    }

	  else if (strcmp (dori, "PUSH") == 0)
	    {			//logic is good
		  fscanf(f, "%d ", &num);
		  struct node *insert = allocate (num);
	      if (head == 0)
		{
		  head = insert;

		}

	      else
		{
		  insert->data = num;
		  insert->next = head;
		  head = insert;

		}

	    }

	  else if (strcmp (dori, "POP") == 0)
	    {

	     if (head != 0)
		//{
	    	  //printf("EMPTY\n");
		  
		//}
	      //else
		{
		  struct node *temp = head;
		  head = head->next;

		  // deletes temp which is still pointing to front
					free(temp);
					//free(insert);

		}

	    }
	  //PRINT OUT THE LL AFTER EVERY ITERATION

	  struct node *current2;
	  current2 = head;
	  if (current2 == 0)
	    {			// if empty print empty
	      printf ("EMPTY\n");
	    }
	  else
	    {
	      while (current2 != 0)
		{
		  printf ("%d ", current2->data);	//puts space after each
		  current2 = current2->next;
		}
	      printf ("\n");
	    }


	}


      freeer (head);
      fclose (f);

    }
  else
    {
      printf ("error");
      return EXIT_SUCCESS;
    }
}

