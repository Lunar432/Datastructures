#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n;
   printf("Enter array size: ");
   scanf("%d",&n);
   int data[n];
   for(int i=0;i<n;i++)
   {
    data[i] = rand()%100;
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
   printf("\nArray: \n");
   for(int i=0;i<n;i++)
   {
    printf("%d  ",data[i]);
   }
    int item,loc;
    int beg=0,end = n-1 ,mid=(beg+end)/2;
    printf("\nEnter item to search: ");
    scanf("%d",&item);
    while(beg<=end && data[mid]!=item)
    {
        if(data[mid]>item)
         end = mid-1;
        else
         beg = mid+1;

     mid=(beg+end)/2;
    }

    if(data[mid]==item)
    {
        loc = mid;
        printf("Found at %d",loc);
    }
    else
    //loc = NULL;
     printf("Not Found");

    return 0;
}