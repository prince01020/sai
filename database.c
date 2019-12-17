#include<stdio.h>
struct student
{
	char name[50];
	int roll;
	float marks;
}s[10];
int main()
{
	int i;
	printf("\n enter the data for students");
	for(i=0;i<10;i++)
	{
		s[i].roll=i+1;
		printf("\n for roll number %d\n",s[i].roll);
		printf("\n name of the student");
		scanf("%s",s[i].name);
		printf("\n enter the marks\n");
		scanf("%f",&s[i].marks);
	}
	printf("\n displaying information");
	printf("\n roll number:%d\n",i+1);
	printf("name: is %s",s[i].name);
	printf("marks is %f\n",s[i].marks);
	printf("\n");
    return 0;
}

