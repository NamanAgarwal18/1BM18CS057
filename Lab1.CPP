#include<stdio.h>
#include<conio.h>

struct stud
{
	char name[20], USN[10];
	int subject[9];
};

void main ()
{
	clrscr();
	struct stud s;
	int i;
	printf("Enter the Name and the USN of the student");
	gets(s.name);
	gets(s.USN);
	printf("Enter the marks in 9 subjects ");
	for(i=0;i<9; i++)
	{
		scanf("%d", &s.subject[i]);
	}
	printf("Displaying the student details \n");
	printf("Name %s and USN %s", s.name, s.USN);
	printf("\nThe Marks are: \n");
	for(i=0; i<9; i++)
	{
		printf("%d \n",s.subject[i]);
	}
	getch();
}