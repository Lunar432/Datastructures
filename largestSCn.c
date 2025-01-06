
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,item;
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++)
     scanf("%d ",array[i]);
    item = array[0];
    for(i=1;i<=n;i++)
    {
        if(item < array[i])
          item = array[i];
    }
    printf("%d",item);
    return 0;
} 