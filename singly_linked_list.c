#include <stdio.h>
#include <stdlib.h>

struct node{
	int i;
	struct node *link;
}*first,*n,*ptr,*tptr;

void infront(void){
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter Element : ");
	scanf("%d",&ptr->i);
	ptr->link=first;
	first = ptr;
}

void inrear(void){
	n = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter Element : ");
	scanf("%d",&n->i);
	n->link = NULL;
	ptr = first;
	while(ptr->link!=NULL){
		ptr = ptr->link;
	}
	ptr->link = n;
}

void inany(void){
	int k;
	n = (struct node*)malloc(sizeof(struct node));
	printf("\n Eneter KEY : ");
	scanf("%d",&k);
	ptr = first;
	while(ptr!=NULL&&ptr->i!=k){
		ptr=ptr->link;
	}

	if(ptr==NULL){
		printf("\nKEY NOT FOUND ");
	}
	else{
		printf("\n Enter Element : ");
		scanf("%d",&n->i);
		n->link = ptr->link;
		ptr->link = n;		
	}
	
}

void disp(void){
	ptr = first;
	if(first == NULL){
		printf("\nERROR\n LINK IS EMPTY !\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->i);
			ptr = ptr->link;
		}
	}
}

void delfront(void){
	ptr = first;
	if(first == NULL){
		printf("\nERROR LINK IS EMPTY !\n");
	}
	else{
		first = first->link;
		free(ptr);
		printf("\nITEM DELED SUCCESSFULLY\n");
	}
}

void delrear(void){
	ptr = first;
	if(first == NULL){
           printf("\nERROR LINK IS EMPTY !\n");
	}
	else{
			while(ptr->link!=NULL){
				tptr = ptr;
				ptr = ptr->link;
			}
			if(ptr==first){
				free(first);
				first = NULL;
			}
			else{
				tptr->link = NULL;
				free(ptr);
				printf("\nITEM DELTED SUCCESSFULLY");
			}
	}

}

void delany(void){
	int k;
	printf("\nKEY : ");
	scanf("%d",&k);
	ptr = first;
	while(ptr!=NULL&&ptr->i!=k){
		tptr = ptr;
		ptr=ptr->link;
	}

	if(ptr==NULL){
		printf("\nKey NOT FOUND ");
	}
	else{
		if(ptr==first){
				free(first);
				first = NULL;
			}
			else{
				tptr->link = ptr->link;
				free(ptr);
				printf("\nITEM DELTED SUCCESSFULLY");
			}		
	}
}

void menu(void){
	int c;
	printf("\nPRESS 1 for insert at front");
	printf("\nPRESS 2 for insert at rear");
	printf("\nPRESS 3 for insert at any position");
	printf("\nPRESS 4 for delete at front");
	printf("\nPRESS 5 for delete at rear");
	printf("\nPRESS 6 for delete at any position");
	printf("\nPRESS 7 for disply");
	printf("\nPRESS 8 for exit");
		printf("\nChoice : ");
	scanf("%d",&c);
	switch(c){

		case 1:
			infront();
			menu();
		break;
		case 2:
			inrear();
			menu();
		break;
		case 3:
		 	inany();
		 	menu();
		break;
		case 4:
			delfront();
			menu();
		break;
		case 5:
			delrear();
			menu();
		break;
		case 6:
			delany();
			menu();
		break;
		break;
		case 7:
			disp();
			menu();
		break;
		case 8:
			return ;
		default:
		printf("\nINVALID INPUT\n");
		menu();
	}
}

int main(){
	menu();
	return 0;
}
