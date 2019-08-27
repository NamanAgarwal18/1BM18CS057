#include<iostream>
using namespace std;

const int MAXSIZE = 10;									//Max size of the array

void Display(int front, int rear, int Arr[MAXSIZE]) 					//To Display
{
	for(int i = front; i<=rear; i++)
		cout<<Arr[i]<<" ";
	cout<<endl;
}

void enqueue(int data, int *rear, int *front,int Arr[MAXSIZE])				//To push in the queue at the rear end
{
	int c = MAXSIZE -1;
	if(*rear == c)
	{
		cout<<"Queue is Full \n";
	}
	else
	{
		*rear=  *rear + 1;
		Arr[*rear] = data;
		Display(*front,*rear,Arr);
	}
}


void dequeue(int *front, int *rear, int Arr[MAXSIZE])					//To Pop at the front end
{
	if(*rear == *front)
	{	
		cout<<"Queue is Empty \n" ;
	}
	else
	{
		for(int i = (*front); i< *rear; i++)					//Pushing every element to i-1 position
		{
			Arr[i] = Arr[i+1];
		}
		*rear= *rear -1;
		Display(*front,*rear,Arr);
	}
}



int main()
{
	int a;
	int rear = -1, front = 0, Arr[MAXSIZE];
	for(;;)
	{
		cout<<"Enter 1 to add in the queue \nEnter 2 to delete \nEnter 3 to Display \nEnter 4 to Exit : \n";
		cin>>a;
		if(a==1)
		{
			cout<<"Enter the data:  ";
			int data; 
			cin>>data;
			enqueue(data,&rear,&front,Arr);
		}
		else if(a==2)
			dequeue(&front,&rear,Arr);
		else if(a==3)
			Display(front,rear,Arr);
		else
			return 0;
	}
}

		












	
