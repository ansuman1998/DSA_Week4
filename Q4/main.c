#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int *lower=(int *)malloc(n*sizeof(int));
    int *higher=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&lower[i]);
    int maxhour=-1;
    for(i=0;i<n;i++)
    {
         scanf("%d",&higher[i]);
         if(higher[i]>maxhour)
            maxhour=higher[i];
    }
    printf("%d\n",maxhour);
    int *hours=(int *)malloc((maxhour+1)*sizeof(int));
    for(i=0;i<=maxhour;i++)
        hours[i]=0;
    for(i=0;i<n;i++)
    {
        for(j=lower[i];j<=higher[i];j++)
            hours[j]++;
    }
    int max=hours[0];
    int maxi=0;
    for(i=0;i<=maxhour;i++)
        {   //printf("%d ",hours[i]);
            if(hours[i]>max)
            {
                max=hours[i];
                maxi=i;
            }
        }
    printf("\n");
    printf("%d\n",maxi);
}
