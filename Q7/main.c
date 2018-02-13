#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,temp;
  scanf("%d", &n);
  int *a= (int *)malloc(n*sizeof(int));
  int i,j;
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);



        i=-1;
        for(j=0;j<n-1;j++)
        {
            if(a[j]%2==0)
            {
                i++;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;

            }
        }
        i++;
        temp=a[n-1];
        a[n-1]=a[i];
        a[i]=temp;



    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

}
