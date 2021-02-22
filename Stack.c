#include<stdio.h>
int stack[10],n,top,x,i;
int main()
{
    int choice;
    top=-1;
    printf("\n Enter the size of STACK[MAX=10]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    while(1)
    {
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    
    printf("\n Enter the Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: push();
                break;
        
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: printf("\n\t EXIT POINT ");
                break;
        default:printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
                break;
                
    }
    }

return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK Over Flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top<0)
    {
         printf("\n The STACK is Empty\n");
    }
    else
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
       
    }
   
}
