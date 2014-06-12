/*Program to get the nth node of a linked list

1. Initialize count = 0
2. Loop through the link list
     a. if count is equal to the passed index then return current
         node
     b. Increment count
     c. change current to point to next of the current.
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



struct node{
	int data;
	struct node *next;
};



void push_node(struct node **head, int val){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;

	new_node->next= *head;
	*head=new_node;
}


int get_nth(struct node *head, int index){
	int counter=0;
	struct node* temp= head;
	while(temp!=NULL){
		if(counter==index)
			return temp->data;
		temp=temp->next;
		counter++;
	}
	assert(0);
}

int main(){
	struct node *head=NULL;
	push_node(&head, 1);
	push_node(&head, 2);
	push_node(&head, 3);
	push_node(&head, 4);
	push_node(&head, 5);
	push_node(&head, 6);

	printf("\nElement at index 4 is %d",get_nth(head, 4));

}



