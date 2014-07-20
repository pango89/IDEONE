/*
GIVEN TWO NUMBERS REPRESENTED BY TWO LISTS, WRITE A FUNCTION THAT RETURNS SUM LIST. 
THE SUM LIST IS LIST REPRESENTATION OF ADDITION OF TWO INPUT NUMBERS.
EXAMPLE 1:
INPUT:
  FIRST LIST: 5->6->3  // REPRESENTS NUMBER 365
  SECOND LIST: 8->4->2 //  REPRESENTS NUMBER 248
OUTPUT
  RESULTANT LIST: 3->1->6  // REPRESENTS NUMBER 613
EXAMPLE 2:
INPUT:
  FIRST LIST: 7->5->9->4->6  // REPRESENTS NUMBER 64957
  SECOND LIST: 8->4 //  REPRESENTS NUMBER 48
OUTPUT
  RESULTANT LIST: 5->0->0->5->6  // REPRESENTS NUMBER 65005
*/
#include<stdio.h>
#include<stdlib.h>
 
/* LINKED LIST NODE */
struct node
{
    int data;
    struct node* next;
};
 
/* FUNCTION TO CREATE A NEW NODE WITH GIVEN DATA */
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* FUNCTION TO INSERT A NODE AT THE BEGINNING OF THE DOUBLY LINKED LIST */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = newNode(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* ADDS CONTENTS OF TWO LINKED LISTS AND RETURN THE HEAD NODE OF RESULTANT LIST */
struct node* addTwoLists (struct node* first, struct node* second)
{
    struct node* res = NULL; // res is head node of the resultant list
    struct node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list. 
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = newNode(sum);
 
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;
 
        // Set prev for next insertion
        prev  = temp;
 
        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }
 
    if (carry > 0)
      temp->next = newNode(carry);
 
    // return head of the resultant list
    return res;
}
 
// A utility function to print a linked list
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
/* Drier program to test above function */
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);
 
   return 0;
}