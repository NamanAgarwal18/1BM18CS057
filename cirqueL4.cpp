#include<iostream>

using namespace std;



bool isfull(int front, int rear)
{
	if(front == ((rear+1)%10))
		return true;
	else
		return false;
}

bool isempty(int front, int rear)
{
	if(front == rear)
		return true;
	else
		return false;
}

void enqueue(int data, int front, int *rear, int queue[10])
{
	if(isfull(front,*rear))
		cout<<"\nQueue is full \n\n";
	else
	{
		queue[*rear]=data;		
		*rear = ((*rear+1)%10);
		
	}
}

void dequeue(int *front, int rear)
{
	if(isempty(*front,rear))
		cout<<"\nQueue is empty \n\n";
	else
	{
		*front = (*front+1)%10;
	}
}

void display(int front, int rear, int queue[10])
{
	int i;
	for(i=front; i!=rear;)
	{
		cout<<queue[i]<<" ";
		i=((i+1)%10);
	}
	cout<<endl;
}

int main()
{
	int i, data;
	int front =0, rear = 0, queue[10];
	for(;;)
	{
		cout<<"Enter 1 to Add in Queue \nEnter 2 to remove fron the Queue \nEnter 3 to Display the Queue \nEnter 4 to exit : ";
		cin>>i;
		if(i==1)
		{
			cout<<"Enter the data: ";
			cin>>data;
			enqueue(data, front, &rear, queue);
			display(front,rear,queue);
		}
		else if(i==2)
		{
			dequeue(&front, rear);
			display(front,rear,queue);
		}
		else if(i==3)
		{
			display(front,rear,queue);
		}
		else
			return 0;
	}
}

