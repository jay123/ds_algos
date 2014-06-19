/*
 * nth_from_end_recur.c
 *
 *  Created on: Jun 19, 2014
 *      Author: linux
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

	new_node->next= *head;
	*head= new_node;
}

void print_list(struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

void nth_from_end(struct node *head, int n){
	static int i=0;
	if(head==NULL)
		return;
	nth_from_end(head->next,n);
	if(++i==n)
		printf("\n\nnth from last is %d\n",head->data);
}

void main(){
	struct node *head=NULL;
	append(&head, 8);
	append(&head, 7);
	append(&head, 6);
	append(&head, 5);
	append(&head, 4);
	append(&head, 3);
	append(&head, 2);
	append(&head, 1);

	print_list(head);

	nth_from_end(head, 3);

}
