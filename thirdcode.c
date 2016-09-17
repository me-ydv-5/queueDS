/* josephus problem using array */
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n,er,i;

	printf("Please enter values of n and i : "); // n is the number of children
	scanf("%d %d",&n,&er); // er is elimination rule
	int* a[n];

	for ( i = 0; i < n; ++i)
	{
		a[i] = (int*)malloc(sizeof(int));
		*a[i] = i+1;        // storing number in the array
	}
	int nos = n,r,j;
	while(nos != 1)
	{
		j=0;
		while( j != er-1)
		{
			 r = *a[n-nos];
			for (i = n-nos; i < n-1; i++)
			{
				*a[i] = *a[i+1];    // shifting the numbers
			}
			*a[i]= r;

			j++;
		}

		int t = *a[n-nos];
		free(a[n-nos]);

		if(nos == n)
			printf("\n\nFirstly, the person at position %d is removed.\n",t);

		else if(nos == 2)
			{
				printf("Finally, the person at position %d is removed.\n",t);
				printf("\nHence the person at position %d survives. (WINNER)\n",*a[n-nos+1]);
				free(a[n-nos+1]);
			}
		else
			printf("Then person at position %d is removed.\n",t );

		nos--;
	}
	return 0;
}

