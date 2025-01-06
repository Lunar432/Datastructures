#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{    
    int n,i,j;

    //take input of array size 
    printf("Enter dimension of square matrix: ");
    scanf("%d",&n);

    //allocate memory for matrix
    int *** arr = malloc(n*sizeof(int**));
    for(i=0;i<n;i++)
    {
        arr[i]= calloc(n,sizeof(int*));
    }

    //generate random values of matrix
    srand(time(0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {    
            arr[i][j]= malloc(sizeof(int));
            *arr[i][j]= (rand()%5);
        }
    }

    //print matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d ",*arr[i][j]);
        }
        printf("\n");
    }

    //free allocated memory
    free(arr);
    for(i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr[i][j]);

    return 0;

}