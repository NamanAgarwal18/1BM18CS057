#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void display(struct node *head)
{
	struct node *save;
	save = head;
	while(save!=NULL)
	{
		cout<<save->data<<"->";
		save=save->next;
	}
}

struct node * InsertFront(struct node *head)
{
	//struct node *save;
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	cout<<"Enter The Data: ";
	int n;
	cin>>n;
	temp->data = n;
	//save = head;
	//head  = temp;
	//temp->next = save;
	temp->next=head;
	head = temp;
	display(head);
	return head;
}

struct node * InsertEnd(struct node *head)
{
	struct node *save;
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	int n;
	cout<<"Enter The Data: ";
	cin>>n;
	save = head;
	temp->data = n;
	while(save->next!=NULL)
	{
		save=save->next;
	}
	save->next = temp;
	display(head);
	return head;
}





int main()
{
	struct node *head = NULL;
	int i;
	for(;;)
	{
		cout<<"[1]Insert Front \n[2]Insert Rear \n[3]Display \n[4]Exit : ";
		cin>>i;
		if(i==1)
		{
			head = InsertFront(head);
		}
		else if(i==2)
		{
			head = InsertEnd(head);
		}
		else if(i==3)
		{
			display(head);
		}
		else
			return 0;
	}
}
	
	
