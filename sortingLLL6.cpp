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
	cout<<endl;
}

struct node * InsertFront(struct node *head,int n)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	
	temp->data = n;
	temp->next=head;
	head = temp;
	display(head);
	return head;
}

struct node * InsertEnd(struct node *head,int n)
{
	struct node *save;
	struct node *temp = (struct node*)malloc(sizeof(struct node*));

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

struct node * InsertAny(struct node* head,int pos,int i)
{
	struct node *save, *tempsave;
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
		save=head;
		for(int i=0; i<(pos-2); i++)
		{
			save=save->next;
		}
		tempsave=save->next;
		
		temp->data=i;
		save->next=temp;
		temp->next=tempsave;
		display(head);
	
	return head;
}

struct node * Compare(struct node *head,int data)
{
	if(head==NULL)
	{
		head = InsertFront(head,data);
		return head;
	}
	else
	{
		struct node *save;
		save  = head;
		int j=-1;
		if(save->data > data)
		{
			head = InsertFront(head,data);
			return head;
		}
		for(int i=0; save !=NULL; i++)
		{
			if(save->data > data)
			{
				j=i+1;
				head = InsertAny(head,j,data);
				return head;
			}
			save = save->next;
		}
			head = InsertEnd(head,data);
			return head;
	}
	return head;
}

int main()
{
	struct node* head = NULL;
	int i;
	for(;;)
	{
		cout<<"[1]Insert \n[2]Display \n[3]Exit : ";
		cin>>i;
		if(i==1)
		{
			cout<<"Enter the data: ";
			int data;
			cin>>data;
			head = Compare(head,data);
		}
		else if(i==2)
			display(head);
		else
			return 0;
	}
}

