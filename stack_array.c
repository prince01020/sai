#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack
{
	int stack[MAX];
	int top;
}s;
void push()
{
	int n;
	if(s.top==MAX-1)
	printf("stack overflow\n");
	else
	{
		printf("enter the element into the stack\n");
		scanf("%d",&n);
		s.top++;
		s.stack[s.top]=n;
	}
}
void pop()
{
	int x;
if(s.top==-1)
printf("stack overflow\n");
else
{
	x=s.stack[s.top];
	s.top--;
	printf("\n removed element:%d",x);
	}	
}
void display()
{
	if(s.top==-1)
	printf("stack overflow\n");
	else
	{
		int i;
		for(i=s.top;i>=0;i--)
		printf("%d\n",s.stack[i]);
	}
}
int main()
{
	s.top=-1;
	int ch;
	do
	{
		printf("\n enter your choice \n 1.push\n 2.pop\n 3.display\n 4.exit\n");
		scanf("%d\n",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(1);
			defalut:printf("enter the valid option\n");
		}
	}
	while(ch!=4);
	return 0;
}
