#include <stdio.h>
#include <stdlib.h>
int n,countasc=0,countdesc=0;
void print(int *a, int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=1;i<n;i++)
        sum+=abs(a[i]-a[i-1]);
    printf("%d\n",sum);
    printf("\n");
}
void swapasc(int *a, int *b)
{   //printf("%d %d swapped\n",*a,*b);
    int temp=*b;
    *b=*a;
    *a=temp;
    countasc++;
}
void swapdesc(int *a, int *b)
{//printf("%d %d swapped\n",*a,*b);
    int temp=*b;
    *b=*a;
    *a=temp;
    countdesc++;
}
/*
void permute(int *a, int l, int r)
     {
        int i;
        if (l == r)
            print(a,n);

        else
        {
            for (i = l; i <= r; i++)
            {
                swap((a+l), (a+i));
                permute(a, l+1, r);
                swap((a+l), (a+i)); //backtrack
            }
        }
    }
*/
int main()
{
   int i;
   scanf("%d", &n);
   int *a=(int *)malloc(n*sizeof(int));
   int *b=(int *)malloc(n*sizeof(int));
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   for(i=0;i<n;i++)
    b[i]=a[i];

    int j,max,maxj;
    for(i=0;i<n;i++)
    {
        max=a[i];
        maxj=i;
        for(j=i+1;j<n;j++)
            if(a[j]>max)
            {
                max=a[j];
                maxj=j;
            }
            if(i!=maxj)
            swapdesc(a+i,a+maxj);

    }
     print(a,n);
    for(i=0;i<n;i++)
    {
        max=b[i];
        maxj=i;
        for(j=i+1;j<n;j++)
            if(b[j]<max)
            {
                max=b[j];
                maxj=j;
            }
            if(i!=maxj)
            swapasc(b+i,b+maxj);


    }
    print(b,n);

    printf("%d %d\n",countdesc,countasc);




}
