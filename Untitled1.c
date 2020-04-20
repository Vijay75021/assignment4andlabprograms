#include<stdio.h>

char v[20];
int top=-1;

void push(char);
void pop();

void push(char v1)
{
	v[++top]=v1;
}

void pop()
{
	printf("%c",v[top--]);
}

void main()
{
	char input[20];
	printf("\n enter string:");
	scanf("%v",input);
	
	int k=0;
	while (input[k]!='\0')
	{
		push(input[k]);
		k++;
	}
	
	printf("\n");
	while(top!=-1)
	{
		pop();
	}
}
