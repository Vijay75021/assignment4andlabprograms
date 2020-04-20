#include<stdio.h>
#define s 50

char stack[s];
int top=-1;

void push(char v1)
{
	if(top>=s-1)
	printf("\n stack oerflow,push not possible \n");
	else
	{
		top++;
		stack[top]=v1;
	}
}
char pop()
{
	char v1;
	v1=stack[top];
	top--;
	return(v1);
}
int is_operator(char string)
{
	if(string=='^'||string=='*'||string=='/'||string=='+'||string=='-')
	return 1;
	else
	return 0;
	
}
int precedence(char string)
{
	if(string=='^')
	return 3;
	else if(string=='*'|| string=='/')
	return 2;
	else if(string=='+'||string=='-')
	return 1;
	else
	return 0;
	
	
}
int main()
{
	char infix[s],postfix[s],v1,temp;
	int i=0,j=0;
	printf("\n enter the arthimatic notation in infix notation:");
	gets(infix);
	while(infix[i]!='\0')
	{
		v1=infix[i];
		if(v1=='(')
		{
			push(v1);
		}
		else if(v1>='A' && v1<='Z' || v1>='a' && v1<='z')
		{
			postfix[j]=v1;
			j++;
		}
		else if(is_operator(v1)==1)
		{
			temp=pop();
			while(is_operator(temp)==1 && precedence(temp)>=precedence(v1))
			{
				postfix[j]=temp;
				j++;
				temp=pop();
				
			}
			push(temp);
			push(v1);
		}
		else if(v1==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j]=temp;
				j++;
				temp=pop();
				
			}
		}
		else
		{
			printf("\n The arthimatic expression is not valid.\n");
			getch();
		    exit(0);
			
			
			
		}
		i++;
	}
	while(top>-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
	
	getch();
	return 0;
}
