#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    int freq;
};
int top=-1;
struct node data[100];

void update_data(int n)
{
    int i;
    for(i=0;i<=top;i++)
        if(data[i].num==n)
            {
                data[i].freq++;
                printf("Node updated\n");
                return;
            }

        top++;
        data[top].num=n;
        data[top].freq=0;
        printf("New Node created\n");

}
int main()
{
    int n,i,max=0;
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
            max=a[i];
    }
    for(i=0;i<n;i++)
        update_data(a[i]);
    for(i=0;i<=top;i++)
        printf("%d %d\n",data[i].num, data[i].freq);
printf("\n");

    for(i=1;i<=max;i++)
    {
        int j=i-1;
        int temp1, temp2, temp3;
        temp1=data[i].freq;
        //temp2=data[i].index;
        temp3=data[i].num;
        while(j>=0&&data[j].freq<temp1)
        {
            //data[j+1].index=data[j].index;
            data[j+1].freq=data[j].freq;
            data[j+1].num=data[j].num;
            j--;
        }
        j++;
        data[j].freq=temp1;
        //data[j].index=temp2;
        data[j].num=temp3;
    }

      for(i=0;i<=top;i++)
            printf("%d %d\n", data[i].num,data[i].freq);



}
