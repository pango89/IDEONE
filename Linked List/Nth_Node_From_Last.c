/*
NTH NODE FROM THE END OF A LINKED LIST
GIVEN A LINKED LIST AND A NUMBER N, WRITE A FUNCTION THAT RETURNS THE VALUE AT 
THE NTH NODE FROM END OF THE LINKED LIST.
----------------------------------------------------------------------------------
METHOD 2 (USE TWO POINTERS) 
----------------------------------------------------------------------------------
1.MAINTAIN TWO POINTERS – REFERENCE POINTER AND MAIN POINTER. 
2.INITIALIZE BOTH REFERENCE AND MAIN POINTERS TO HEAD. 
3.FIRST MOVE REFERENCE POINTER TO N NODES FROM HEAD. 
4.NOW MOVE BOTH POINTERS ONE BY ONE UNTIL REFERENCE POINTER REACHES END. 
5.NOW MAIN POINTER WILL POINT TO NTH NODE FROM THE END. 
6.RETURN MAIN POINTER.

TIME COMPLEXITY: O(N) WHERE N IS THE LENGTH OF LINKED LIST.

IMPLEMENTATION:
*/
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
  int data;
  struct node* next;
};
 
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct node *head, int n)
{
  struct node *main_ptr = head;
  struct node *ref_ptr = head;
 
  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } /* End of while*/
 
     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d ", 
              n, main_ptr->data);
  }
}
 
void push(struct node** head_ref, int new_data)
{
  /* allocate node */
  struct node* new_node =
          (struct node*) malloc(sizeof(struct node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);    
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}
 
/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
  push(&head, 20);
  push(&head, 4);
  push(&head, 15); 
 
  printNthFromLast(head, 3);
  getchar();
}
