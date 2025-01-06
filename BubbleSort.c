#include <stdio.h>
#include <stdlib.h>

int main()
{  int n;
   printf("Enter array size: ");
   scanf("%d",&n);
   int data[n];
   printf("\nInitial Array: \n");
   for(int i=0;i<n;i++)
   {
    data[i] = rand()%100;
    printf("%d  ",data[i]);
   }
   int temp;
   for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-1-i;j++)
    {
        if(data[j]>data[j+1])
        {
            temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
        }
    }
   }
   printf("\nNew Array after sorting: \n");
   for(int i=0;i<n;i++)
   {
    printf("%d  ",data[i]);
   }
    return 0;
}