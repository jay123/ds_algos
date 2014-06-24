/*
 * reverse_list.c
 *
 *  Created on: Jun 24, 2014
 *      Author: linux
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};


void push_node(struct node **head, int data){
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=data;

	new_node->next=*head;
	*head=new_node;
}

void print_list(struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

void reverse(struct node **head){
	struct node *prev=NULL;
	struct node *current=*head;
	struct node *next;

	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}


void main(){
	struct node *head=NULL;
	push_node(&head,9);
	push_node(&head,8);
	push_node(&head,7);
	push_node(&head,6);
	push_node(&head,5);
	push_node(&head,4);
	push_node(&head,3);
	push_node(&head,2);
	push_node(&head,1);

	print_list(head);

	reverse(&head);
	printf("\n\nAfter reversal:\n\n");
	print_list(head);
}
