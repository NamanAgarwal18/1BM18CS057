#include<iostream.h>
#include<conio.h>


//No Global Declaration Done
//Call By reference by Pointer method Is Used

int Overflow(int *Top)               //Returns 1 if overflow is happening
{
	if(*Top==9)
		return 1;
	else
		return 0;
}

int Underflow(int *Top)              //Returns 2 if underflow is happening
{
	if(*Top == -1)
		return 1;
	else
		return 0;
}

void Display(int Arr[10], int *Top)  //To Display
{
	int i=0;
	for(i = *Top; i>=0; i--)
		cout<<Arr[i]<<" ";
	cout<<endl<<endl;
}

void Push(int data, int Arr[10], int *Top)       //To Push
{
	if(Overflow(Top) == 1)                   //To check if overflow is happening
		cout<<"Overflow \n\n";
	else                                     //if overflow is not happening
	{
		*Top=*Top+1;
		Arr[*Top]=data;
		Display(Arr,Top);
	}
}

void Pop(int Arr[10], int *Top)                //To Pop
{
	if(Underflow(Top) ==1)                 //to check if Underflow is happening
		cout<<"Underflow \n\n";
	else                                   //If Underflow is not happening
	{
		cout<<"Popped Element is "<<Arr[*Top]<<endl;
		*Top=*Top -1;
		Display(Arr,Top);
	}
}

void main()
{
	clrscr();
	int j=0, Data;
	int Top =-1, Arr[10];
	cout<<"Program 1 by Naman Agarwal 1BM18CS057 \n";
	for(;;)
	{
		cout<<"Enter 1 to Push \nEnter 2 to Pop \nEnter 3 to Display \nEnter 4 to exit \n";
		cin>>j;
		if(j==1)
		{
			cout<<"Enter The Data: ";
			cin>>Data;
			Push(Data,Arr,&Top);
		}
		else if(j==2)
		{
			Pop(Arr,&Top);
		}
		else if (j==3)
		{
			Display(Arr,&Top);
		}
		else
			break;
	}
		getch();
}




