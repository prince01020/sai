#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node stk;
stk *top;
stk* getnode()
{
 stk *p;
 p=(stk*)malloc(sizeof(stk));
 return p;
}
 void push(int x)
{
  stk *p;
  p=getnode();
 if(p==NULL)
{
 printf("out of memory\n");
 return;
}
else
{
 p->info=x;
 p->next=NULL;
 if(top!=NULL)
  p->next=top;
 top=p;
 
}
}
void pop()
{
 stk *p;
 if(top==NULL)
printf("not possible\n");
else if(top->next==NULL)
{
 printf("%d deleted\n",top->info);
 free(top);
}
else
{
 
 p=top;
 top=p->next;
 p->next=NULL;
  printf("%d deleted\n",p->info);
 free(p);
 }
}
void display()
{
 stk *p;
 p=top;
 while(p!=NULL)
{
 printf("%d\t",p->info);
 p=p->next;
}
}
void main()
{
 int ch,x;
 while(1)
{
 printf("\nenter choice\n1.push\n2.pop\n3.display\n4.exit\n");
 scanf("%d",&ch);
 switch(ch)
{
 case 1:printf("enter element\n");
        scanf("%d",&x);
        push(x);
        break;
 case 2:pop();
        break;
 case 3:display();
        break;
 case 4:exit(0);
 default:printf("wrong choice\n");
 }
}
}
    





