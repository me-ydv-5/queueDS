#include"my_library.h"



int main(int argc, char const *argv[])
{
	int n,er;

	printf("Please enter values of n and i : ");
	scanf("%d %d",&n,&er);

	if( n < 2 || er == 0)
	{
		printf("Give a valid value of constraints!\n");
		exit(0);
	}

	int i;
	for ( i = n; i > 0 ; i--)
		enqueue = push(enqueue,i);

	printf("\nThe removal sequence is as follows-\n\n");
	movement(enqueue,dequeue,n,er);
	
	return 0;
}

