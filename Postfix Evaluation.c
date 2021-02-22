//EVALUATION OF POSTFIX EXPRESSION
#include<stdio.h>
#include<ctype.h>

#define MAX 20    
#define PSIZE 20  

int stack[MAX];
int top = -1 ;             
 
void push(int item)
{
	if(top >= MAX -1)
	{
		printf("stack over flow");
		return;
	}
	else
	{
		top = top + 1 ;
		stack[top]= item;
	}
}

int pop()
{
	int item;
	if(top <0)
	{
	    printf("stack under flow");
	}
	else
	{
	    item = stack[top];
		top = top - 1;
		return item;
	}
}

void EvalPostfix(char postfix[])
{
	int i ;
	char ch;
	int val;
	int A, B ;
	for (i = 0 ; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];
		if (isdigit(ch))
		{
			push(ch - '0');
		} 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			A = pop();
			B = pop();
			switch (ch)
			{
				case '*':val = B * A;
						 break;
				case '/':val = B / A;
						 break;
				case '+':val = B + A;
						 break;
				case '-':val = B - A;
						 break;
			}
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
}

int main()
{
	int i ;
	char postfix[PSIZE];
	printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");	
	printf( " \nEnter postfix expression\n");
	scanf("%s",postfix);
	
	EvalPostfix(postfix);
	return 0;
}

