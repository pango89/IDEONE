#include<stdio.h>
#include<malloc.h>
struct node
{
	char data;
	struct node *next;
};
struct node *reverse(struct node* head)
{
	if(head==NULL or head->next==NULL)
	{
		return head;		
	}
	else
	{
		struct node *nextnode,*temp=NULL;
		while(head!=NULL)
		{
			nextnode=head->next;
			head->next=temp;
			temp=head;
			head=nextnode;
		}
		return temp;
	}
}
bool compareLists(struct node *head1,struct node *head2)
{
		struct node *temp1=head1;
		struct node *temp2=head2;
		while(temp1!=NULL && temp2!=NULL)
		{
			if(temp1->data!=temp2->data)
			{
				return false;
			}
			else
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
		if(temp1==NULL && temp2==NULL)
			return true;
		return false;	
}
void push(struct node **head,char data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void printList(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%c ->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
bool isPalindrome(struct node *head)
{
	struct node *slowptr=head,*fastptr=head;
	struct node *prev_of_slowptr=head;
	struct node *second_half=NULL,*midnode=NULL;
	while(fastptr!=NULL && fastptr->next!=NULL)
	{
		fastptr=fastptr->next->next;
		prev_of_slowptr=slowptr;
		slowptr=slowptr->next;
	}
	if(fastptr!=NULL)
	{
		midnode=slowptr;
		slowptr=slowptr->next;
	}
	prev_of_slowptr->next=NULL;
	second_half=slowptr;
	second_half=reverse(second_half);
	bool res=compareLists(head,second_half);
	second_half=reverse(second_half);
	if(midnode!=NULL)
	{
		prev_of_slowptr->next=midnode;
		midnode->next=second_half;
	}
	else
	{
		prev_of_slowptr->next=second_half;
	}
	return res;
}
int main()
{
	struct node *head=NULL;
	char str[]="radar";
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		push(&head,str[i]);
		printList(head);
		isPalindrome(head)?printf("Is Palindrome\n\n"):printf("Is Not Palindrome\n\n");
	}
	return 0;
}
