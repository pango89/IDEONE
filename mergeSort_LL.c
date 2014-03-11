#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node** head,int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void printList(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void FrontBackSplit(struct node* source,struct node** frontRef,struct node** backRef)
{
	struct node* slowptr=source;
	struct node* fastptr=source;
	struct node* prev_of_slowptr=source;
	while(fastptr!=NULL && fastptr->next!=NULL)
	{
		fastptr=fastptr->next->next;
		prev_of_slowptr=slowptr;
		slowptr=slowptr->next;
	}
	if(fastptr!=NULL)
	{
		prev_of_slowptr=slowptr;
		slowptr=slowptr->next;
	}
	prev_of_slowptr->next=NULL;
	*frontRef=source;
	*backRef=slowptr;
}
struct node* sortedMerge(struct node* a,struct node* b)
{
	struct node* result=NULL;
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	if(a->data<b->data)
	{
		result=a;
		result->next=sortedMerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=sortedMerge(a,b->next);
	}
	return result;
}
void mergeSort(struct node** head)
{
	struct node* h=*head;
	struct node* a;
	struct node* b;
	if(h==NULL||h->next==NULL)
	{
		return;
	}
	FrontBackSplit(h,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	*head=sortedMerge(a,b);
}


int main()
{
	struct node* a=NULL;
	push(&a,15);
	push(&a,-15);
	push(&a,0);
	push(&a,51);
	push(&a,29);
	push(&a,51);
	push(&a,-15);
	printList(a);
	mergeSort(&a);
	printList(a);
	return 0;
}
