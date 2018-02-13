#include <stdio.h>
#include <stdlib.h>
int binsearch(int *a, int low, int high, int x)
{
    if(low>high)
        return;

    int mid=(low+high)>>1;
    if(a[mid]==x)
        return mid;
    else if(a[mid]<x)
        high=mid-1;
    else if(a[mid]>x)
        low=mid+1;

    return -1;
}
int main()
{
    int n,i,x;
    scanf("%d %d",&n,&x);
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>x)
            continue;
        if(binsearch(a,0,n-1,x-a[i])!=-1&&binsearch(a,0,n-1,x-a[i])!=i)
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO");

}
