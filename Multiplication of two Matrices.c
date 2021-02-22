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
void matMul(int mat1[][5], int mat2[][5], int pro[][5],int m,int n)
{
    int row, col, i, sum;
    for (row = 0; row < m; row++)
    {
        for (col = 0; col < n; col++)
        {
            sum = 0;
            for (i = 0; i < n; i++)          
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));            
            *(*(pro + row) + col) = sum;
        }
    }
}
int main()
{
    int mat1[5][5], mat2[5][5], pro[5][5],m,n;
    
    printf("Enter the order of the matrix\n");
    scanf("%d%d",&m,&n);

    printf("Enter elements of first matrix\n");
    matIn(mat1,m,n);

    printf("Enter elements of second matrix\n");
    matIn(mat2,m,n);

    matMul(mat1, mat2, pro,m,n);

    printf("Product of both matrices is : \n");
    matP(pro,m,n);
}

