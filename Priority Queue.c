//Priority Queue
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
int pq[MAX];
int pos;
int f = -1,r = -1;
 
void enq(int data)
{
    if (r >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    else
    {
        pos=r;
        r++;
        while(pos>=0 && pq[pos]>=data)
        {
            pq[pos+1]=pq[pos];
            pos--;
        }
        pq[pos+1] = data;
        if(f==-1)
            f++;
    }    
}

void deq()
{
    if ((f==-1) && (r==-1))
    {
        printf("\nQueue is empty no elements to delete\n");
        return;
    }
    else if(r==f)
    {
        printf("\nElement deleted is %d\n",pq[f]);
        f=-1; r=-1;
    }
    else
    {
        printf("\nElement deleted is %d\n",pq[f]);
        f++;
    }
}

void display()
{
    int i;
    if(f==-1 && r==-1)
        printf("\nQueue is EMPTY\n");
    else
    {
        for(i=f;i<r+1;i++)
            printf("%d\t",pq[i]);
        printf("\n");
    }
}

int main()
{
    int n, ch;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
 
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:printf("\nEnter value to be inserted : ");
               scanf("%d",&n);
               enq(n);
               break;
        case 2:deq(n);
               break;
        case 3:display();
               break;
        case 4:exit(0);
        default:printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}


 
