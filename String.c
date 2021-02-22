#include<stdio.h>

int stringlen(char S[20])
{
	int n;
	for(n=0;S[n]!='\0';n++);
	return n;
}

void stringcat(char s1[50],char s2[20])
{
	int l,i,j;
	l=stringlen(s1);
	i=l;j=0;
	while(s2[j]!='\0')
	{
		s1[i]=s2[j];
		i++;j++;
	}
		
}

void stringcopy(char s1[50],char s2[50])
{
	int l1,i;
	l1=stringlen(s1);
	for(i=0;i<l1;i++)
		s1[i]=s2[i];
	s1[i]='\0';
}

int main()
{
	char S[20],str1[20],str2[20];
	int n=0;
	
	printf ("Program to demonstrate string length and string concatinate and String copy function\n");
	printf("Enter String 1\n");
	scanf("%s",str1);
	printf("Enter String 2\n");
	scanf("%s",str2);
	stringcat(str1,str2);	
	printf("Concatinated String is: %s\n",str1);
	stringcopy(str1,str2);
	stringlen(str1);
	printf("The length of the string is %d",l);
	return 0;
}
