/*
A FUNCTION TO REVERSE A LINKED LIST
RECURSIVE METHOD
---------------------------------
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)--FOR RECURSION
---------------------------------
IMPLEMENTATION OF RECURSIVE METHOD
*/
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* reverse(Node* head)
{
    if(head==NULL||head->next==NULL)
		return head;
	Node* secondElem=head->next;
	head->next=NULL;
	Node* remaining=reverse(secondElem);
	secondElem->next=head;
	return remaining;	
}
void push(Node** head_ref, int new_data)
{
    Node* new_Node = new Node;
    new_Node->data  = new_data;
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}  
int main()
{
    Node* head = NULL;
	Node* reversed=NULL;   
    push(&head, 20);
    push(&head, 4);
    push(&head, 15); 
    push(&head, 85);  
    printList(head);    
    reversed=reverse(head);                      
    printf("\n Reversed Linked list \n");
    printList(reversed);    
    return 0;
}
