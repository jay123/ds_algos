/*
 * nth_from_end.c
 *
Nth node from the end of a Linked List
Given a Linked List and a number n, write a function that returns the value at the nth node from end of the Linked List.

Maintain two pointers – reference pointer and main pointer.
Initialize both reference and main pointers to head.
First move reference pointer to n nodes from head.
Now move both pointers one by one until reference pointer reaches end.
Now main pointer will point to nth node from the end.
Return main pointer.
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void append(struct node **head, int data){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;

	new_node->next=*head;
	*head=new_node;
}

void print_list(struct node *head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

int nth_from_last(struct node *head, int n){
	int i=0;
	struct node *temp=head;
	while(i<n){
		temp=temp->next;
		i++;
	}

	while(temp!=NULL && temp->next!=NULL){
		temp=temp->next;
		head=head->next;
	}

	return head->data;
}

void main(){
	struct node *head=NULL;
	append(&head,8);
	append(&head,7);
	append(&head,6);
	append(&head,5);
	append(&head,4);
	append(&head,3);
	append(&head,2);
	append(&head,1);

	print_list(head);

	printf("\n3rd from last is %d\n",nth_from_last(head,3));
}
