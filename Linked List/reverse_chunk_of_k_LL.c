#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref,int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=*head_ref;
    *head_ref=newNode;
}
void printList(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
struct node* reverseChunkOfK(struct node* head,int k)
{
    struct node* current=head;
    struct node* nextNode;
    struct node* prev=NULL;
    int count=0;
    while(current!=NULL && count<k)
    {
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
        count++;
    }
    //CURRENT IS POINTING TO (K+1)TH NODE
    if(current!=NULL)
    {
        head->next=reverseChunkOfK(current,k);
    }
    return prev;
}
int main()
{
    struct node* list=NULL;
    push(&list,8);
    push(&list,7);
    push(&list,6);
    push(&list,5);
    push(&list,4);
    push(&list,3);
    push(&list,2);
    push(&list,1);
    push(&list,0);
    printf("\n Given linked list \n");
    printList(list);
    list = reverseChunkOfK(list, 5);
    printf("\n Reversed Linked list \n");
    printList(list);
    return(0);
}
