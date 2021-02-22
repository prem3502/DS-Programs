#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} s[10]; //array of structure
int main()
{
	int n,i;
    printf("Enter the number of student records to be added\n");
    scanf("%d",&n);
    printf("Enter information:\n");
    for(i=0;i<n;i++)
    {
		printf("\n***Enter Student %d details***\n",i+1);
	    printf("Enter name: ");
	    scanf("%s", s[i].name);
	    printf("Enter roll number: ");
	    scanf("%d", &s[i].roll);
	    printf("Enter marks: ");
	    scanf("%f", &s[i].marks);
	}
	printf("\n***Displaying Information***\n");
	for(i=0;i<n;i++)
    {
	    printf("Name: ");
	    puts(s[i].name);
	    printf("Roll number: %d\n",s[i].roll);
	    printf("Marks: %.1f\n", s[i].marks);
	}
    return 0;
}
