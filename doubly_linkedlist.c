
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int info;
	struct node *right;
};
struct node *start=NULL;
void insert_front();
void insert_end();
void insert_left();
void insert_right();
void delete_front();
void delete_end();
void delete_key();

void display();

void main()
{
	int c;
	while(1)
	{
		printf("enter your choice\n1.insert_front\n2.insert_end\n3.insert_left\n4.insert_right\n5.delete_front\n6.delete_end\n7.delete_key\n8.display\n9.exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:insert_front();
			            break;
			case 2:insert_end();
			            break;
			 case 3:insert_left();
			            break;
			case 4:insert_right();
			            break;
			 case 5:delete_front();
			            break;
			 case 6:delete_end();
			            break;
			 case 7:delete_key();
			            break;

			  case 8:display();
			            break;
			  case 9:exit(0);
			  default:printf("wrong choice\n");
	         }
	   }
}

void insert_front()
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("out of memory\n");
		return;
	}
	else
	{
		printf("enter the element\n");
		scanf("%d",&p->info);
		if(start==NULL)
		{
			p->left=NULL;
			p->right=NULL;
			start=p;
		}
		else
		{
		        start->left=p;
			p->right=start;
			p->left=NULL;
			start=p;
		}
	}
}

void insert_end()
{
	struct node *p,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("out of memory\n");
		return;
	}
	else
	{
		printf("enter the element\n");
		scanf("%d",&p->info);
		if(start==NULL)
		{
			p->left=NULL;
			p->right=NULL;
			start=p;
		}
		else
		{
			temp=start;
			while(temp->right!=NULL)
			temp=temp->right;
			temp->right=p;
			p->left=temp;
			p->right=NULL;
		}
	}
}

void insert_left()
{
	int pos,i;
	struct node *p,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("out of memory\n");
		return;
	}
	else
	{
		printf("enter the element and position\n");
		scanf("%d%d",&p->info,&pos);
		if(start==NULL)
		{
			p->left=NULL;
			p->right=NULL;
			start=p;
		}
		else if(pos==1)
		{
			start->left=p;
			p->right=start;
			p->left=NULL;
			start=p;
		}
		else
		{
			temp=start;
			for(i=1;i<=pos-1;i++)
			{
				temp=temp->right;
				if(temp==NULL)
				{
					printf("position not found\n");
					return;
				}
			}
			p->right=temp;
			p->left=temp->left;
			temp->left->right=p;
			temp->left=p;
		}
	}
}

void insert_right()
{
	int pos,i;
	struct node *p,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("out of memory\n");
		return;
	}
	else
	{
		printf("enter the element and position\n");
		scanf("%d%d",&p->info,&pos);
		if(start==NULL)
		{
			p->left=NULL;
			p->right=NULL;
			start=p;
		}

		else
		{
			temp=start;
			for(i=1;i<=pos-1;i++)
			{
				temp=temp->right;
				if(temp==NULL)
				{
					printf("position not found\n");
					return;
				}
			}
			if(temp->right==NULL)
            {
                temp->right=p;
                p->left=temp;
                p->right=NULL;
            }
            else
            {
			p->left=temp;
			p->right=temp->right;
			temp->right->left=p;
			temp->right=p;
		}
		}
	}
}

void delete_front()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		temp=start;
		if(temp->right==NULL)
		{
			start=NULL;
			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
		else
		{
			start=temp->right;
			start->left=NULL;
			temp->right=NULL;
			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
	}
}

void delete_end()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		temp=start;
		if(temp->right==NULL)
		{
			start=NULL;
			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
		else
		{
			while(temp->right!=NULL)
			temp=temp->right;
			temp->left->right=NULL;
			temp->left=NULL;
			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
	}
}

void delete_key()
{
	int key;
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		printf("enter the key\n");
		scanf("%d",&key);
		temp=start;
		if(temp->info==key)
		{
			start=temp->right;
			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
		else
		{
			while(temp->info!=key)
			{
				temp=temp->right;
				if(temp==NULL)
				{
					printf("key not found\n");
					return;
				}
			}
			if(temp->right==NULL)
			{
				temp->left->right=NULL;
				temp->left=NULL;
				printf("deleted element is %d\n",temp->info);
			  free(temp);

			}
            else
            {


			temp->left->right=temp->right;
			temp->right->left=temp->left;

			printf("deleted element is %d\n",temp->info);
			free(temp);
		}
		}
	}
}

void display()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		printf("contents of list are\n");
		temp=start;
		while(temp->right!=NULL)
		{
			printf("%d\n",temp->info);
			temp=temp->right;
		}
		printf("%d\n",temp->info);
	}
}

