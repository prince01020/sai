#include<stdio.h>
int main()
{
	int i,j, m,n,a[5][5],b[5][5],c[5][5];
	printf("enter the first matrix order");
	scanf("%d%d",&m,&n);
	printf("enter the first matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("enter the 2nd matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",(*(b+i)+j));
		}
	}
	printf("addition of matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
			printf("%d",*(*(c+i)+j));
		}
		printf("\n");
	}
}
