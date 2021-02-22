#include <stdio.h>
#include<stdlib.h>
#include<process.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear =-1;

int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void enQueue(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}
void deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return;
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else 
		{
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return;
    }
}
void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Items in Queue\n");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
    }
}
int main()
{
	int n, ch;
 	printf("****---PROGRAM TO IMPLEMENT CIRCULAR QUEUE---****");
 	
 	while (1)
    {
    	printf("\n1 - Insert an element into queue");
    	printf("\n2 - Delete an element from queue");
    	printf("\n3 - Display queue elements");
    	printf("\n4 - Exit");
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            enQueue(n);
            break;
        case 2: 
			deQueue();
            break;
        case 3: 
            display();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
