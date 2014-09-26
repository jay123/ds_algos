#include <stdio.h>
#include<stdlib.h>

typedef struct llnode{
	int data;
	struct llnode *next;
}node;

typedef struct return_val{
	int carry;
	node *ll_node;
}ret;

int insert_node(node **head, int data){
	node *new_node=malloc(sizeof(node));
	if(!new_node){
		printf("\nmem allocation failed");
		return 0;
	}
	new_node->next=*head;
	new_node->data=data;
	*head=new_node;
	return 1;
}

void print_list(node *head){
	while(head!=NULL)
	{
		printf("%d->",head->data);
		head=head->next;
	}
	printf("\n");
}

int delete_last(node **head){
	node *temp=*head,*temp1=NULL;
	if(temp->next==NULL){
		printf("\ndeleting head");
		free(temp);
		return 0;
	}
	temp1=temp->next;
	while(temp1->next!=NULL){
		temp1=temp1->next;
		temp=temp->next;
	}
	temp->next=temp1->next;
	free(temp1);
	return 0;
}

int delete_val(node **head, int val){
	node *temp=*head,*temp1=NULL;
	if(temp->data==val){
		*head=temp->next;
		free(temp);
		printf("\ndeleted head");
		return 0;
	}
	while(temp){
		if(temp->next->data==val){
			temp1=temp->next;
			temp->next=temp->next->next;
			free(temp1);
			return 1;
		}
	}
	return 0;
}

int insert_end(node **head,int val){
	node *new_node=malloc(sizeof(node));
	new_node->data=val;
	new_node->next=NULL;
	node *temp=*head;

	while(temp){
		if(temp->next==NULL){
			temp->next=new_node;
			return 0;
		}
		temp=temp->next;
	}

	return 0;
}

int remove_duplicates(node **head){
	node *elem=*head;
	node *runner=NULL;
	node *temprunner=NULL;

	while(elem){
		runner=elem;
		while(runner->next){
			if(runner->next->data==elem->data){
				temprunner=runner->next;
				runner->next=runner->next->next;
				free(temprunner);
			}
			else{
				runner=runner->next;
			}
		}
		elem=elem->next;
	}
	return 0;
}

int kthfromlast_recur(node **head, int k){
	if(*head==NULL)
		return 0;
	int i=kthfromlast(&(*head)->next, k)+1;
	if(i==k)
		printf("\nkth from last recursively is %d",(*head)->data);
	return i;
}

int kthfromlast(node **head, int k){
	node *node1=*head;
	node *node2 = *head;
	int counter=1;
	while(counter<k){
		if(node2==NULL)
			return 1;
		node2=node2->next;
		counter++;
	}
	while(node2->next!=NULL){
		node1=node1->next;
		node2=node2->next;
	}
	printf("\nkth from last iterative is %d",node1->data);
	return 0;
}

int delete_middle(node **middle){
	node *temp=*middle;
	node *temp1=temp;
	if(temp1->next==NULL){
		printf("\nCannot delete the last element\n");
		return 1;
	}
	temp1=temp1->next;
	temp->data=temp1->data;
	temp->next=temp1->next;
	free(temp1);
	return 0;
}

int rearrange_list(node **head, int pivot){
	node *first=NULL;
	node *second=NULL;
	node *temp=*head;

	if(temp==NULL || temp->next==NULL){
		printf("\nSingle or no element");
		return 1;
	}
	while(temp!=NULL){
		if(temp->data<pivot)
			insert_node(&first,temp->data);
		else if(temp->data>=pivot)
			insert_node(&second,temp->data);
		temp=temp->next;
	}
	if(first!=NULL){
		temp=first;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=second;
		*head=first;
	}
	if(first==NULL && second!=NULL){
		*head=second;
	}
	return 0;
}

node* add_numbers_rev(node *l1, node* l2, int carry){
	node *new_node=malloc(sizeof(node));
	new_node->next=NULL;
	int result;
	printf("\nhere1");

	if(l1==NULL && l2==NULL && carry==0){
		printf("\nhere2");
		return NULL;
	}

	printf("\nhere3");
	if(l1!=NULL&&l2!=NULL)
		result=l1->data + l2->data + carry;
	else if(l1==NULL)
		result=l2->data + carry;
	else if(l2==NULL)
		result=l1->data + carry;

	new_node->data=result%10;
	carry=result/10;
	printf("\nhere5");
	new_node->next=add_numbers_rev(l1 == NULL ? NULL:l1->next, l2==NULL ? NULL:l2->next, carry);
	printf("\nhere6");
	return new_node;
}

ret *add_numbers_forward(node *l1, node *l2){
	node *new_node = malloc(sizeof(node));
	new_node->next=NULL;
	ret *ret_elem;
	ret_elem=malloc(sizeof(ret));
	int result=0;

	if(l1==NULL && l2==NULL){
		ret_elem->ll_node=NULL;
		ret_elem->carry=0;
		return ret_elem;
	}

	ret *ret_elem1=add_numbers_forward(l1->next,l2->next);

	result=(l1->data + l2->data + ret_elem1->carry)%10;
	new_node->data=result;
	new_node->next=ret_elem1->ll_node;
	ret_elem->ll_node=new_node;
	ret_elem->carry=(l1->data + l2->data + ret_elem1->carry)/10;

	return ret_elem;
}

node* add_numbers_forward_wrapper(node *l1, node *l2){
	int len1=1;
	int len2=1;
	int diff=0;
	node *temp1=l1;
	node *temp2=l2;
	ret *ret_val;

	while(temp1->next!=NULL){
		temp1=temp1->next;
		len1++;
	}
	while(temp2->next!=NULL){
		temp2=temp2->next;
		len2++;
	}

	if(len1>len2){
		diff=len1-len2;
		for(;diff!=0;diff--){
			insert_node(&l2,0);
		}
	}
	else if(len1<len2){
		diff=len2-len1;
		for(;diff!=0;diff--){
			insert_node(&l1,0);
		}
	}

	ret_val=add_numbers_forward(l1,l2);
	if(ret_val->carry!=0)
		insert_node(&ret_val->ll_node,ret_val->carry);

	return ret_val->ll_node;
}

node *find_loop_start(node *head){
	node *fast=head;
	node *slow=head;

	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);

	slow=head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}

	return slow;
}

int check_palindrome(node *head, int length, int even, int tmp_len){
	node *temp=head;
	int counter=1;
	int result;

	while(counter<tmp_len){
		counter++;
		temp=temp->next;
	}
	if(head->data!=temp->data)
		return 0;

	if(tmp_len==((length/2)+1)){
		if(even){
			if(head->data==temp->data)
				return 1;
			else
				return 0;
		}
		if(!even)
			return 1;
	}

	result=check_palindrome(head->next,length,even,tmp_len=tmp_len-2);

	return result;
}

int check_palindrome_wrapper(node *head){
	int counter=1;
	int even=0;
	int res;
	node *temp=head;
	while(temp->next!=NULL){
		counter++;
		temp=temp->next;
	}
	if(counter%2==0)
		even=1;
	//printf("\ncounter is %d",counter);
	res=check_palindrome(head,counter,even,counter);
	if(res==0)
	{
		printf("\nNot a palindrome\n");
	}
	else{
		printf("\nA palindrome\n");
	}
	return res;
}


int main(){
	node *head=NULL;
	node *head1=NULL;
	node *temp,*head7,*temp1;
	insert_node(&head,2);
	insert_node(&head,1);
	insert_node(&head,7);
	insert_node(&head,2);
	insert_node(&head,2);
	//temp=head;
	//head=head->next;
	//head7=head->next;
	//head=head7;
	//head=head->next;
	//head=head->next;
	//head->next=head7;
	//head=temp;

	print_list(head);

	//delete_last(&head);
	//print_list(head);
	//delete_val(&head,4);
	//print_list(head);
	//insert_end(&head,6);
	//remove_duplicates(&head);
	//delete_middle(&temp);
	//rearrange_list(&head,5);
	//temp=add_numbers_rev(head,head1,0);
	//temp=add_numbers_forward_wrapper(head,head1);
	//temp1=find_loop_start(head);
	//printf("\nloop start is %d",temp1->data);
	//kthfromlast(&head,2);
	check_palindrome_wrapper(head);

return 0;
}
