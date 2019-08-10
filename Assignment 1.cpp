#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student 
{
	char name[20], email[20], USN[10];
} stud[10];

int Top = -1;

int IsFull()
{
	if(Top == 9)
		return 1;
	else
		return 2;
}

void Display()
{
	int i;
	for(i = Top; i>=0; i--)
	{
		printf("\n %s, %s, %s ",stud[i].name,stud[i].email,stud[i].USN);
	}
	printf("\n");
}

int IsEmpty()
{
	if(Top == -1)
		return 1;
	else
		return 2;
}

void Push (struct student sample)
{
	if(IsFull()==1)
		printf("Overflow");
	else
	{
	Top++;
	strcpy(stud[Top].name , sample.name);
	strcpy(stud[Top].email, sample.email);
	strcpy(stud[Top].USN, sample.USN);
	Display();
	}
		
}

void Pop()
{
	if(IsEmpty()==1)
		printf("Underflow");
	else
	{
		Top--;
		Display();
	}
		
}





int main()
{
	for(;;)
	{
		printf("Press 1 to Push \nPress 2 to Pop \nPress 3 to Display \nPress 4 to exit");
		int i;
		struct student sample;
		scanf("%d", &i);
		if(i==1)
		{
			printf("Enter Name, Email and USN: ");
			gets(sample.name);
			gets(sample.email);
			gets(sample.USN);
			Push(sample);
		}
		else if(i==2)
		{
			Pop();
		}
		else if(i==3)
		{
			Display();
		}
		else
		
			return 1;
	}
}
