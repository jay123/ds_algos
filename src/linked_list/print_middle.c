/*
 *
 *      Write a C function to print the middle of a given linked list
 *
 *      Traverse linked list using two pointers.
 *      Move one pointer by one and other pointer by two.
 *      When the fast pointer reaches end slow pointer will reach middle of the linked list.
 */


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push_node(struct node **head, int data){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;

	new_node->next = *head;
	*head=new_node;
}

struct node * middle(struct node * head){
	struct node *temp1=head;
	struct node *temp2=head;
	while(temp2!=NULL && temp2->next!=NULL){
		temp1=temp1->next;
		temp2=temp2->next->next;
	}

	return temp1;
}

void print_list(struct node * head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

void main(){
	struct node* head=NULL;
	push_node(&head, 1);
	push_node(&head, 2);
	push_node(&head, 3);
	push_node(&head, 4);
	push_node(&head, 5);

	print_list(head);

	printf("\nMiddle element is %d: ", middle(head)->data);
}



