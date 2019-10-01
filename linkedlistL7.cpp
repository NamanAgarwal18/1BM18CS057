#include<iostream>
#include<stdlib.h>

using namespace std;

static int count=0;

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

struct node * InsertFront(struct node *head)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	cout<<"Enter The Data: ";
	int n;
	cin>>n;
	temp->data = n;
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

struct node * InsertAny(struct node* head,int pos)
{
	struct node *save, *tempsave;
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	if(pos<0)
		pos=0;
	
	if(pos==0 || count ==0 || pos==1)
	{
		head = InsertFront(head);
			
	}
	else if(pos>count)		
	{
		head= InsertEnd(head);
		
	}
	else
	{
		save=head;
		for(int i=0; i<(pos-2); i++)
		{
			save=save->next;
		}
		tempsave=save->next;
		cout<<"Enter the data: ";
		int i;
		cin>>i;
		temp->data=i;
		save->next=temp;
		temp->next=tempsave;
		display(head);
	}
	return head;
}
	

struct node * DeleteFront(struct node *head)
{
	if(head==NULL)
	{
		cout<<"Linked list empty \n";
		return head;
	}
	struct node* temp;
	temp = head;
	head = head->next;
	delete temp;
	return head;
}

struct node * DeleteEnd(struct node *head)
{
	if(head==NULL)
	{
		cout<<"Linked list empty \n";
		return head;
	}
	if(head->next==NULL)
	{
		head=NULL;
		return head;
	}
	struct node *temp, *save;
	save=head;
	while(save->next->next!=NULL)
	{
		save=save->next;
	}
	temp = save->next;
	save->next = NULL;
	delete temp;
	return head;
}

struct node *DeleteAny(struct node* head, int pos)
{
	if(pos<1)
	 pos=1;
	if(head==NULL)
	{
		cout<<"Linked list empty \n";
		return head;
	}
	if(count==1 || pos==1)
	{
		head = DeleteFront(head);
		return head;
	}
	else if(count<pos)
	{
		head = DeleteEnd(head);
		return head;
	}
	else 
	{
		struct node *save, *tempsave;
		save = head;
		for(int i=0; i<(pos-2); i++)
		{
			save=save->next;
		}
		tempsave=save->next;
		save->next = save->next->next;
		delete tempsave;
		return head;
	}
		
			
}

			
		





int main()
{
	struct node *head = NULL;
	int i;
	for(;;)
	{
		cout<<"[1]Insert Front \n[2]Insert Rear \n[3]Inseet At Any Position \n[4]Display \n[5]Delete Front \n[6]Delete Rear \n[7]Delete At Any Position \n[8]Exit : ";
		cin>>i;
		if(i==1)
		{
			
			head = InsertFront(head);
			count ++;
		}
		else if(i==2)
		{
			
			head = InsertEnd(head);
			count ++;
		}
		else if(i==4)
		{
			display(head);
		}
		else if(i==3)
		{
			int pos;
			cout<<"Enter the position: ";
			cin>>pos;
			head = InsertAny(head,pos);
			count++;
		}
		else if(i==5)
		{
			head = DeleteFront(head);
			display(head);
			count--;
		}
		else if(i==6)
		{
			head = DeleteEnd(head);
			display(head);
			count--;
		}
		else if(i==7)
		{
			cout<<"Enter The Position";
			int pos;
			cin>>pos;
			head = DeleteAny(head,pos);
			display(head);
			count--;
		}
		else
			return 0;
	}
}
	
	
