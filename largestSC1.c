#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,k,item;
    scanf("%d",&n);
    scanf("%d",&item);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&k);
        if(item < k)
        {
           item = k;
        }
    }
    printf("\n\n%d",item);
    return 0;
}
