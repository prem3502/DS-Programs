		//Linked List
	
		#include<stdio.h>
		#include<stdlib.h>
		struct node
		{
		    int data;
		    struct node *link;
		};
		struct node *head=NULL;
		
		struct node *getnode()
		{
		    struct node *temp;
		    temp=(struct node*)malloc(sizeof(struct node));
		    return temp;
		};
		
		void insert(int n)
		{
		    struct node *temp,*cur;
		    temp=getnode();
		    temp->data=n;
			   temp->link=NULL;
			   if(head==NULL)
			   {
			       head=temp;
			       printf("%d is inserted\n",temp->data);
			       return;
		       }
			cur=head;
			   while(cur->link!=NULL)
			   {
			       cur=cur->link;
			   }
			   cur->link=temp;
			   printf("%d is inserted\n",temp->data);
		}
			
		void del_front()
		{
		    struct node *cur;
		    cur=head;
		    if(head==NULL)
		    {
		       printf("List is EMPTY!!\n");
		       return;
	        }
		    else
		    {
		        printf("The deleted item is %d\n",cur->data);
		        head=head->link;
		        free(cur);
		    }
		}
			
		void del_rear()
		{
		    struct node*cur, *prev;
		    cur=head;
		    while(cur->link!=NULL)
		    {
		        prev=cur;
		        cur=cur->link;
		    }
		    printf("Value deleted is %d\n",cur->data);
		    prev->link=NULL;
		    free(cur);
		}
			
		void display()
		{
		    struct node *cur;
		    if(head==NULL)
		    {
		        printf("List is EMPTY\n");
		        return;
		    }
		    cur=head;
		    while(cur!=NULL)
		    {
			        printf("%d\t",cur->data);
			        cur=cur->link;
			    }
			    printf("\n");
			}
			
			int main()
			{
			    int ch=0,n;
			    printf("**LINKED LIST**");
			    while(1)
			    {
			        printf("\n1.Insert\n2.Delete from Front\n3.Delete from Rear\n4.Display\n5.EXIT\n");
			        printf("\nEnter your choice:");
			        scanf("%d",&ch);
			        switch(ch)
			        {
			            case 1:printf("Enter the value to be inserted\n");
			                   scanf("%d",&n);
			                   insert(n);
			                   break;
			            case 2:del_front();
			                   break;
			            case 3:del_rear();
			                   break;
			            case 4:display();
			                   break;
			            case 5:exit(0);
			            default:printf("Enter a valid choice\n");
			        }
			    }
			}
