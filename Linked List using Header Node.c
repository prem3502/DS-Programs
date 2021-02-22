#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


NODE* create_hll(NODE *); //Function to create a Linked List with Header Node
NODE* display(NODE *);        // Function to display the contenets of the list

int main()
{
	NODE *head = NULL;
	int option;
	do
	{
		printf("\n\n -----Main Menu-----");
		printf("\n 1. Create a list\n 2. Display the list\n 3. Exit\n");
		
		printf("\n Enter your choice : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			head = create_hll(head);
			printf("\nNo of nodes in the List are:%d\n",head->data);
			break;
			case 2:
			head = display(head);
			break;
		}
	}while(option != 3);
	return 0;
}
struct node* create_hll(struct node *head)
{
	NODE *new_node, *cur;
	int num;
	
	do
	{
		printf("\n Enter the data :");
		scanf("%d", &num);
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		new_node -> next = NULL;
		if(head == NULL)
		{
			head = (struct node*)malloc(sizeof(struct node));
			head -> next = new_node;
			head ->data = 1;
		}
		else
		{
			cur = head;
			while(cur -> next != NULL)
				cur = cur -> next;
			cur -> next = new_node;
			head->data = head->data + 1;
		}
		printf("\n Do you want to continue Entering vlues to the List?\n Enter 1 to continue or -1 to Stop\n");
		scanf("%d", &num);
	}while(num != -1);
	printf("\n Header Linked List Created Successfully\n");

	return head;
}
struct node* display(struct node *head)
{
	struct node *ptr;
	ptr = head;
	ptr = ptr -> next;
	while(ptr != NULL)
	{
	printf("%d\t",ptr -> data);
	ptr = ptr -> next;
	}
	return head;
}
