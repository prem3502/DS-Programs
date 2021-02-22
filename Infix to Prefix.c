#include<stdio.h>
#include<string.h>

char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x; 
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x)
{
    if(x == ')')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
main()
{
    char exp[20],postfix[20];
    char *e, x, temp;
    int i=-1,j;
    printf("Enter an infix expression :");
    scanf("%s",exp);
    j=strlen(exp)-1;
    for(i=0;i<j;i++,j--)
     {
		temp=exp[i];
    	exp[i]=exp[j];
    	exp[j]=temp;
	}	//printf("\nReversed infix is: %s\n",exp);
    e = exp;
    printf("\n****Convertion from Infix to Prefix****\n\n");
    i=-1;
    while(*e != '\0')
    {
        if(isalnum(*e))
            postfix[++i]=*e;
        else if(*e == ')')
            push(*e);
        else if(*e == '(')
        {
            while((x = pop()) != ')')
                postfix[++i]=x;
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                postfix[++i]=pop();
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        postfix[++i]=pop();
    }
    postfix[++i]='\0';
    //printf("Converted Postfix: %s\n",postfix);
    j=strlen(postfix)-1;
    for(i=0;i<j;i++,j--)
    {
		temp=postfix[i];
    	postfix[i]=postfix[j];
    	postfix[j]=temp;
	}
    printf("\nPREFIX: %s \n",postfix);
}
