#include <stdio.h>
void matIn(int mat[][5],int m,int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", (*(mat + i) + j));
        
}
void matP(int mat[][5],int m,int n)
{  
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
void matAdd(int m1[][5], int m2[][5], int res[][5],int m,int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(*(res + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
        }
    }
}
int main()
{
    int m1[5][5], m2[5][5], res[5][5],m,n;
    printf("Enter the order of the matrix\n");
    scanf("%d%d",&m,&n);

    printf("Enter elements of first matrix \n");
    matIn(m1,m,n);

    printf("Enter elemetns of second matrix\n");
    matIn(m2,m,n);

    matAdd(m1, m2, res,m,n);

    printf("\nSum of first and second matrix: \n");
    matP(res,m,n);   
}

