//Implementation of stack using data structures//

#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct stack
{
    int data[max];
    int top;
}stack;

void push(stack *s)
{
    if(s->top==max-1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		printf("Enter element to push:");
		scanf("%d",&s->data[++s->top]);
		
	}
}
void pop(stack *s)
{
    if(s->top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nDeleted element is %d",s->data[s->top]);
		s->top--;
	}
}
void display(stack *s)
{
    int i;
	if(s->top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nStack is...\n");
		for(i=s->top;i>=0;i--)
			printf("%d\n",s->data[i]);
	}
}

void main()
{
    stack s;
    int ch,x;
    s.top=-1;


while(1)
{
    printf("\n*** Stack Menu ***");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
	printf("\n\nEnter your choice(1-4):");
	scanf("%d",&ch);
		
	switch(ch)
    {
        case 1:push(&s);
               break;
        case 2:pop(&s);
               break;
        case 3:display(&s);
               break;
        case 4: exit(0);
			
		default: printf("\nWrong Choice!!");
    }
}

}



