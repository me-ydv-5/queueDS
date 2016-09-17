#include"my_library.h"

struct stack * push(struct stack* peg,int data)
{
	
	if (peg == NULL)
    	{
        	peg =(struct stack *)malloc(1*sizeof(struct stack));
        	peg->next = NULL;
        	peg->data = data;
    	}
    else
    	{
    		
        	struct stack* temp =(struct stack *)malloc(1*sizeof(struct stack));
        	temp->next = peg;
        	temp->data = data;
        	peg = temp;
    	}
    	
    	return peg;
}


struct stack * pop(struct stack* peg)
{
	if(peg != NULL)
	{
		temp = peg->next ;
		free(peg);
		peg=temp;
		return peg; 
	}
	else return peg;
}

void movement(struct stack * enqueue,struct stack * dequeue,int n,int i)
{
	int head ;
	int NOofChildren = n;
	while(NOofChildren != 1)
	{
		int j;
		for(j = 0; j < i-1 ; j++)
		{
			
			head = enqueue->data;
			enqueue = pop(enqueue);

			while(enqueue != NULL)
			{
				dequeue = push(dequeue,enqueue->data);
				enqueue = pop(enqueue);
			}
			
			enqueue = push(enqueue,head);
			
			while(dequeue != NULL)
			{
				enqueue = push(enqueue,dequeue->data);
				dequeue = pop(dequeue);	
			}
		}

		int out = enqueue->data;
		
		enqueue = pop(enqueue);
	

		if(NOofChildren == n){
			printf("[%d] Firstly, the person at position %d is removed.\n",++count,out);
			if(n==2)
				printf("\nHence the person at position %d survives. (WINNER)\n\n",enqueue->data);
		}
		
		else if(NOofChildren == 2)
			{
				printf("[%d] Finally, the person at position %d is removed.\n",++count,out);
				printf("\nHence the person at position %d survives. (WINNER)\n\n",enqueue->data);
				free(enqueue);
			}
		else 
			printf("[%d] Then person at position %d is removed.\n",++count,out );

		NOofChildren--;

	}
}
