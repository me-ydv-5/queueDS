/*
** NAME    - Sahil Yadav
** ROLL    - B15130
** BRANCH  - CSE
** COURSE  - IC 250
** ASSIGNMENT 3 HOT POTATO
*/

#include<stdio.h>
#include<stdlib.h>


struct stack
{
	int data;
	struct stack* next;
}*enqueue,*dequeue,*temp;

int count;
struct stack *push(struct stack* peg,int data);
struct stack *pop(struct stack* peg);
void movement(struct stack * enqueue,struct stack * dequeue,int n,int i);

