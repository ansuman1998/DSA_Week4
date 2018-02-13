#include <stdio.h>
#include <stdlib.h>
void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void merge_sort(int *a, int *temp, int low, int high)
{
    if(low>=high)
        return;

    int mid=(low+high)>>1;
    merge_sort(a,temp,low,mid);
    merge_sort(a,temp,mid+1,high);

    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=temp[i];
}

void rev_merge_sort(int *a, int *temp, int low, int high)
{
    if(low>=high)
        return;

    int mid=(low+high)>>1;
    rev_merge_sort(a,temp,low,mid);
    rev_merge_sort(a,temp,mid+1,high);

    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
        if(a[i]>a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=temp[i];
}
int main()
{
    int n,i,j,k,temp;
    int *odd,*even,*tempo,*tempe;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    if(n%2==0)
    {
        odd=(int *)malloc(n/2*sizeof(int));
        even=(int *)malloc(n/2*sizeof(int));
        tempo=(int *)malloc(n/2*sizeof(int));
        tempe=(int *)malloc(n/2*sizeof(int));
    }
    else
    {
        odd=(int *)malloc(n/2*sizeof(int));
        even=(int *)malloc((n/2+1)*sizeof(int));
        tempo=(int *)malloc(n/2*sizeof(int));
        tempe=(int *)malloc((n/2+1)*sizeof(int));
    }

    i=0;
    j=0;
    k=0;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
            even[k++]=a[i];
        else
            odd[j++]=a[i];
    }
    print(even,k);
    print(odd,j);
    merge_sort(even,tempe,0,k-1);
    rev_merge_sort(odd,tempo,0,j-1);
    print(even,k);
    print(odd,j);

    i=0;
    while(i<k)
        {
            a[i]=even[i];
            i++;
        }
    i=0;
    while(i<j)
        {
            a[i+k]=odd[i];
            i++;
        }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

}
