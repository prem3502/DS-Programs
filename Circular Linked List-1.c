#include <stdio.h>
#include <malloc.h>
typedef struct node
{
int data;
struct node *link;
}NODE;

NODE *start = NULL;
void create_circularlinkedlist();
NODE *display(struct node *);

int main()
{
	int choice;
	do {
		printf("\n1. Create a list");
		printf("\n2. Display the list");
		printf("\n3. Exit the list");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create_circularlinkedlist();
				printf("\n Linked List Created Successfully");
				break;
			case 2:
				start = display(start);
				break;
			default:
			printf("Invalid choice try some other...");
			break;
		}
	}while(choice != 3);
	return 0;
}

void create_circularlinkedlist()
{
	NODE *new_node, *ptr;
	int num=1;
	
	
	while(num!=0)
	{
		printf("\n enter the data : ");
		scanf("%d",&num);
		
		new_node=(NODE*)malloc(sizeof(NODE));
		new_node -> data=num;
		if(start == NULL)
		{
			new_node -> link=new_node;
			start=new_node;
		}
		else {
			ptr=start;
			while(ptr -> link != start)
				ptr=ptr -> link;
			ptr -> link = new_node;
			new_node -> link = start;
		}
		
		printf("\n Do you want to add more value? (Enter 1 to continue or 0 to end");
		scanf("%d",&num);
	}
	
}

NODE* display(NODE *start)
{
	NODE *ptr;
	ptr=start;
	while(ptr -> link != start) 
	{
		printf("\t %d",ptr -> data);
		ptr=ptr -> link;
	}
	printf("\t %d", ptr -> data);
	return start;
}
NODE *insert_beg(struct node *start)
 {
	NODE *new_node,*ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d",&num);
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node -> data = num;
	ptr = start;
	while(ptr -> link !=start)
	ptr = ptr -> link;
	ptr -> link = new_node;
	new_node -> link = start;
	start = new_node;
	return start;
}
NODE *insert_end(NODE *start) 
{
	NODE *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d",&num);
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node -> data = num;
	ptr = start;
	while(ptr -> link != start)
	ptr = ptr -> link;
	ptr -> link = new_node;
	return start;
}
NODE *delete_beg(NODE *start) 
{
	NODE *ptr;
	ptr = start;
	while(ptr->link!= start)
		ptr = ptr->link;
	ptr -> link = start  -> link;
	free(start);
	start = ptr -> link;
	return start;
}
NODE *delete_end(NODE *start) 
{
	NODE *ptr,*preptr;
	ptr = start;
	while(ptr -> link != start)
	{
	preptr = ptr;
	ptr = ptr -> link;
	}
	preptr -> link = ptr -> link;
	free(ptr);
	return start;
}
NODE *delete_after(NODE *start)
{
	NODE *ptr,*preptr;
	int val;
	printf("\n Enter the value of a node after which the next node has to deleted : ");
	scanf("%d",&val);
	ptr = start;
	preptr = ptr;
	while(preptr -> data != val)
	{
	preptr = ptr;
	ptr = ptr -> link;
	}
	preptr -> link = ptr -> link;
	if(ptr == start) {
	start = preptr -> link;
	}
	free(ptr);
	return start;
}
NODE *delete_list(NODE *start) 
{
	NODE *ptr;
	ptr = start;
	while(ptr -> link != start)
	start = delete_end(start);
	free(start);
	return start;
}
