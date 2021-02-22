#include<stdio.h>
#include<stdlib.h>
struct node
{
   int info;
   struct node *next;
};

struct node *p,*top,*ptr;

struct node* getnode()
{
 p=(struct node*)malloc(sizeof(struct node));
   if(p==NULL)
   {
      printf("memory out of space\n");
   }
   else
   {
      printf("enter the information\n");
      scanf("%d",&p->info);
   }
   p->next=NULL;
   
   return p;
}

void pushfront()
{
    p=getnode();
   
   if(p==NULL)
   {
      printf("memory is full\n");
   }
   else
   {
      if(top==NULL)
      {
         top=p;
      }
      else
      {
         p->next=top;
         top=p;
      }
   }
}
   
void pop()
{
   if(top==NULL)
   {
      printf("stack is empyt\n");
   }
   
   else
   {
      ptr=top;
      top=ptr->next;
      ptr->next=NULL;
      printf("node deleted succesfully\n");
      free(ptr);
   }
}

int peek()
{
   return top->info;
}

void display()
{
   if(top==NULL)
   {
      printf("understack\n");
   }
   
   else
   {
      ptr=top;
      while(ptr->next!=NULL)
      {
         printf("%d->",ptr->info);
         ptr=ptr->next;
      }
     printf("%d\t",ptr->info);
   }
}

void main()
{
   top=NULL;
   int ch;
   while(1)
   {
      printf("\nentre the choice:\n1.getnode\n2.pushfront\n3.pop\n4.peek\n5.display\n");
      scanf("%d",&ch);
   
   switch(ch)
   {
      case 1: getnode();
      break;
      case 2:pushfront();
      break;
      case 3:pop();
      break;
      case 4:printf("top element is %d",peek());
      break;
      case 5: display();
      break;
      default:printf("invlid insertiono\n");
     
   }
   
   }
}
