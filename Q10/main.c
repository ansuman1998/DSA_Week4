#include <stdio.h>
#include <stdlib.h>
void reverse(int *a, int i)
{
    int mid=i>>2,j,temp;
    for(j=0;j<=mid;j++)
    {
        temp=a[j];
        a[j]=a[i-j];
        a[i-j]=temp;
    }
}

void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int n,k,j,max,maxj,temp;
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    for(k=0;k<n;k++)
        scanf("%d",&a[k]);

    for(k=n-1;k>=0;k--)
    {
        max=a[k];
        maxj=k;
        for(j=k;j>=0;j--)
        {
            if(a[j]>max)
            {
                max=a[j];
                maxj=j;
            }
        }

        reverse(a,maxj);
        reverse(a,k);

    }

    print(a,n);

}
