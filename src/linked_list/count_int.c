/*
 * count_int.c
 *
 *  Created on: Jun 23, 2014
 Write a function that counts the number of times a given int occurs in a Linked List

 1. Initialize count as zero.
2. Loop through each element of linked list:
     a) If element data is equal to the passed number then
        increment the count.
3. Return count.
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void add_node(struct node **head, int data){
	struct node *new_node=(struct node *)malloc(sizeof(struct node));

	new_node->data=data;
	new_node->next= *head;
	*head=new_node;
}

void print_list(struct node *head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

int count(struct node *head, int n){
	int counter=0;
	struct node *temp=head;
	while(temp!=NULL){
		if(temp->data == n){
			counter++;
		}
		temp=temp->next;
	}
	return counter;
}


void main(){
	struct node *head=NULL;
	add_node(&head, 9);
	add_node(&head, 9);
	add_node(&head, 9);
	add_node(&head, 6);
	add_node(&head, 9);
	add_node(&head, 4);
	add_node(&head, 3);
	add_node(&head, 2);
	add_node(&head, 1);
	add_node(&head, 0);

	print_list(head);
	printf("\n\n9 occurs %d times",count(head, 9));

}
