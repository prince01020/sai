#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node qu;
qu *f;
qu *r;
qu* getnode()
{
 qu *p;
 p=(qu*)malloc(sizeof(qu));
 return p;
}
void ine(int x)
{
 qu *p;
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
 if(f==NULL)
 f=p;
else
 r->next=p;
 r=p;
 }
}
void delf()
{
 qu *p;
 if(f==NULL)
printf("not possible\n");
else if(f==r)
{
 printf("%d deleted\n",f->info);
 free(f);
}
else
{
 
 p=f;
 f=p->next;
 p->next=NULL;
  printf("%d deleted\n",p->info);
 free(p);
 }
}
void display()
{
 qu *p;
 p=f;
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
 printf("\nenter choice\n1.insest\n2.delete\n3.display\n4.exit\n");
 scanf("%d",&ch);
 switch(ch)
{
 case 1: printf("enter element to be inserted \n");
         scanf("%d",&x);
         ine(x);
         break;
 case 2: delf();
         break;
 case 3: display();
         break;
 case 4: exit(0);
 default: printf("wrong choice\n");
}
}
}
