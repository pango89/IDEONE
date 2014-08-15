#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int detectAndRemoveLoop(struct node* list)
{
    struct node* slow_p = list;
    struct node* fast_p = list;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
            return 1;
        }
    }
    return 0;
}
void removeLoop(struct node* loop_node, struct node* head)
{
    struct node* ptr1 = head;
    struct node* ptr2 = loop_node;
    struct node* prev_of_ptr2=loop_node;
    while(ptr1!=ptr2)
    {
    	ptr1=ptr1->next;
    	prev_of_ptr2=ptr2;
    	ptr2=ptr2->next;
    }
    prev_of_ptr2->next=NULL;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node* node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
    head->next->next->next->next->next = head->next->next;
    detectAndRemoveLoop(head);
    printf("Linked List after removing loop \n");
    printList(head);
    getchar();
    return 0;
}
