#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[20];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
    {
        return 0;
    }
    else
    {
        return stack[--top];
    }
}

int priority(char x)
{
    if(x==')')
    return 0;
    if(x=='+' || x=='-')
    return 1;
    if(x=='*' || x=='/')
    return 2;
}

void main()
{
    char exp[20],postfix[20],x,temp,*e;
    int i=-1,j;
    printf("Enter infix Expression\n");
    scanf("%s",exp);
    j=strlen(exp)-1;
    for(i=0;i<j;i++,j--)
    {
        temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
        
    }
printf("infix To Prefix\n");
while(*e!='\0')
    {
        if(isalnum(*e))
        postfix[++i]=*e;
        else if (*e==')')
        push(*e);
        else if (*e=='(')
        {
            while(x=pop()!=')')
            postfix[++i]=x;
        }
    else 
        {
            while(priority(stack[top])>priority(*e))
            postfix[++i]=pop();
            push(*e);
        }
    }
    e++;
    while(top!=-1)
    {
    	postfix[++i]=pop();
	}
	postfix[++i]='\0';
	j=strlen(postfix)-1;
	for(i=0;i<j;i++,j--)
	{
	    temp=postfix[i];
        postfix[i]=postfix[j];
        postfix[j]=temp;
	}
	printf("Prefix Expression is %s \n",postfix);
}
