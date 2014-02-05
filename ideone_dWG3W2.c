#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *pairWiseSwap(struct node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct node* remaing = head->next->next;
    struct node* newhead = head->next;
    newhead->next = head;
    head->next = pairWiseSwap(remaing);
    return newhead;
} 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node *start = NULL; 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1); 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start); 
    start = pairWiseSwap(start);  // NOTE THIS CHANGE 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start); 
    return 0;
}