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


struct node * Create(struct node *head)
{
	int i;
	head = NULL;
	for(;;)
	{
		cout<<"[1]Enter Data \n[2]Exit: ";
		cin>>i;
		if(i==1)
		{
			head = InsertFront(head);
		}
		else
		{
			display(head);
			return head;
		}
	}
}

struct node * Merge()
{
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	head1 = Create(head1);
	cout<<"Now For Linked List 2 \n";
	
	head2 = Create(head2);
	struct node * temp;
	temp = head1;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = head2;
	return head1;
}

struct node * Sort()
{
	struct node *head = NULL;
	head = Create(head);
	struct node *fixed;
	struct node *var;
	fixed = head;
	var = head->next;
	while(fixed->next!=NULL)
	{
		while(var!=NULL)
		{
			if(fixed->data > var->data)
			{
				int temp = fixed->data;
				fixed->data = var->data;
				var->data = temp;
			}
			var = var->next;
		}
		fixed = fixed->next;
		var = fixed->next;	
	}
	return head;
}

struct node * Reverse()
{
	struct node * head = NULL;
	head = Create(head);
	struct node *back=NULL;
	struct node *newhead, *curr;
	newhead = head;
	
	head = NULL;
	while(newhead!=NULL)
	{
		curr = newhead;
		newhead = newhead->next;
		curr->next = back;
		head=curr;
		back = curr;
	}
	return head;
}
		
		
	

int main()
{
	struct node *head =NULL;
	int i;
	for(;;)
	{
		cout<<"[1]Merge \n[2]Sort \n[3]Reverse \n[4]Exit: ";
		cin>>i;
		if(i==1)
		{
			head = Merge();
			display(head);
		}
		else if(i==2)
		{
			head = Sort();
			display(head);
		}
		else if(i==3)
		{
			head = Reverse();
			display(head);
		}
		else return 0;
	}
}
			
	


