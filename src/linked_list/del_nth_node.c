/*Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?

A simple solution is to traverse the linked list until you find the node you want to delete. But this solution requires pointer to the head node which contradicts the problem statement.

Fast solution is to copy the data from the next node to the node to be deleted and delete the next node.
    */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

void append_node(struct node **head, int data){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
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
	printf("\n\n");
}

void delete_nth(struct node *nth){
	struct node *temp=nth->next;
	nth->data=temp->data;
	nth->next=temp->next;
	free(temp);
}

void main(){
	struct node *head=NULL;
	append_node(&head, 1);
	append_node(&head, 2);
	append_node(&head, 3);
	append_node(&head, 4);
	append_node(&head, 5);

	print_list(head);

	delete_nth(head);

	print_list(head);

}

