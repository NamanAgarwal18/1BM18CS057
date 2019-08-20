#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char stak[20], exp[20], res[20],temp;
int Top=-1;

void Push(char data)
{
	Top++;
	stak[Top]=data;
	for(int i=0; i<Top; i++)
		cout<<stak[i];
}

void Pop()
{
	temp=stak[Top];
	Top--;
}

bool precedence (char data)
{
	if(Top == -1)
		return true;
	else if(data == '+' || data == '-')
	{
		if(stak[Top]=='*' || stak[Top] == '/')
		{
			return false;
		}
		else
			return true;
	}
	else if(data ==  '*' || data == '/')
	{
		return true;
	}
}

void Postfix()
{
	int j=0;
	for(int i=0; i<strlen(exp);i++)
	{
		if(exp[i]>='a'&&exp[i]<='z'||exp[i]>='A'&&exp[i]<='Z')
		{
			res[j]= exp[i];
			j++;
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			if(precedence(exp[i]))
			{
				if(exp[i]=='*')
					Push(42);
				else if(exp[i]=='/')
					Push(47);
				else if(exp[i]=='+')
					Push(43);
				else
					Push(45);

			}
			else
			{
				Pop();
				res[j] = temp;
				j++;
				Push(exp[i]);
			}
		}
		else if(exp[i] == '(')
		{
			Push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(stak[Top]!='(')
			{
				Pop();
				res[j]=temp;
				j++;
			}
			Pop();
		}
	}
	for(;Top > -1; )
	{
		Pop();
		res[j] = temp;
		j++;
	}
	res[j] = '\0';

}


int main()
{
	cout<<"Enter The Expression: ";
	gets(exp);
	puts(exp);
	Postfix();
	cout<<"The Expression After Postfix Conversion Is: ";
	puts(res);
	cout<<strlen(res);
	return 0;
}
