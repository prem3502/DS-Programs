#include<stdio.h>
#include<string.h>

int stringlen(char S[20])
{
int i;
for(i=0;S[i]!='\0';i++);
return i;
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
void compareStrings(char* x, char* y)
{
    int flag = 0;
 
    while (*x != '\0' || *y != '\0') {
        if (*x == *y) {
            x++;
            y++;
        }
        else if ((*x == '\0' && *y != '\0')
                 || (*x != '\0' && *y == '\0')
                 || *x != *y) {
            flag = 1;
            printf("Uequal Strings\n");
            break;
        }
    }
 
    if (flag == 0) {
        printf("Equal Strings\n");
    } }
   
 char stringreverse(char str[50])
{
  char  temp;
   int i, j = 0;
 
   i = 0;
   j = strlen(str) - 1;
 
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
 
   printf("\nReverse string is :%s", str);
   return (0);
}


int main()
{
char  str[50],str1[20],str2[20];

printf ("Program to demonstrate string length and string concatinate and String copy function\n");
printf("Enter String 1\n");
scanf("%s",str1);
printf("Enter String 2\n");
scanf("%s",str2);
compareStrings(str1,str2);

stringcat(str1,str2);
printf("\nConcatinated String is: %s\n",str1);
printf("\nconcetenated string length=%d",stringlen(str1));
stringreverse(str1);
stringcopy(str1,str2);
printf("\nCopied from String2 to String1: %s\n",str1);

return 0;
}
