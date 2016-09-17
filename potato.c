//The following program solves the 'Josephus problem' using a circular
//doubly linked list. 


/*
** NAME    - Sahil Yadav
** ROLL    - B15130
** BRANCH  - CSE
** COURSE  - IC 250
** ASSIGNMENT 3 HOT POTATO
*/


#include <stdio.h>
#include <stdlib.h>

//defining a structural node for the linked list
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head = NULL;

//declaring the functions and global variables
int count=0;
struct node*  fill(int n,struct node * queue, struct node* head);
void movement(int n,int i,struct node* head);


int main(int argc, char const *argv[])
{
	int n,i;
	//head is the pointer to the first added element in the list
	head = (struct node*)malloc(sizeof(struct node));

	//queue is the pointer to the last added element in the list
	struct node * queue;

	printf("Please enter values of n and i : ");
	scanf("%d %d",&n,&i);
	printf("\n");

	//error message for invalid input
	if( n < 2 || i == 0 )
	{
		printf("Give a valid value of constraints!\n");
		exit(0);
	}

	//fills the queue and returns the address of the last element
	queue = fill(n,queue,head);
	printf("The removal sequence is as follows-\n\n");

	//function to manipulate queue and give the output
	movement(n,i,head);

	free(queue);

	return 0;
}

//a function that makes a CIRCULAR LINKED LIST and returns the
//address of the last added element
struct node* fill(int n,struct node * queue,  struct node* head)
{
	//rear is the int that keeps track of the no. of values 
	//that have been entered.
	int rear=1;
	while(rear != n+1)
	{
		if (rear==1)
		{
			head->data = rear;
			head->next = NULL;
			head->prev = NULL;
			queue = head;
		}
		else
		{
			struct node * temp; 
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data = rear;
			temp->next = queue;
			temp->prev = NULL;
			queue->prev = temp;
			queue = temp;
		}
		
		if (rear==n)
		{
			head->next = queue;
			queue->prev = head;
		}
		
		rear++;
	}
	return queue;
};

void movement(int n,int i,struct node* head)
{
	int NOofChildren = n;
	while(NOofChildren != 1)
	{	
		//this for loop will point to the element in accordance with
		//the elimination rule entered.
		int t;
		for ( t = 0; t < i-1; ++t)
			head = head->prev;
		
		//stores the value of the node that has to be removed.	
		int out = head->data;

		//the next few lines join two nodes after deleting the 
		//node present between them.
		struct node * ptr1,*ptr2,*transit;
		ptr1 = head->prev;
		ptr2 = head->next;
		
		(head->next)->prev = ptr1;
		(head->prev)->next = ptr2;
		
		transit = head ;
		head = head->prev;
	
		free(transit);
		
		
		//printing of the result.
		if(NOofChildren == n)
			printf("[%d] Firstly, the person at position %d is removed.\n",++count,out);
		
		else if(NOofChildren == 2)
			{
				printf("[%d] Finally, the person at position %d is removed.\n",++count,out);
				printf("\nHence the person at position %d survives. (WINNER)\n",head->data);
				free(head);
			}
		else 
			printf("[%d] Then person at position %d is removed.\n",++count,out );
			
		
		NOofChildren--;
	}
};
