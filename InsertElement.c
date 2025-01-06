#include <stdio.h>
#include <stdlib.h>

int main()
{   int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int array[n];
    printf("\nInitial Array: \n");
    for(int i=0;i<n;i++)
    {
        array[i] = rand()%100;
        printf("%d  ",array[i]);
    }
    int pos,item;

    printf("\nEnter position and item: ");
    scanf("%d%d",&pos,&item);

    if((pos>=0) && (pos<n))
    {
    for(int i=n-1;i>=pos;i--)
        array[i+1] = array[i];
    array[pos] = item;
    n=n+1;
    printf("New array after inserting :");
    for(int k=0;k<n;k++)
     printf("%d  ",array[k]);
    }
    else
    printf("Invalid position.");
    return 0;
}