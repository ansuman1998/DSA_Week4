#include <stdio.h>
#include <stdlib.h>
void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
struct node
{
    int n;
    int factors;
};
int nof(int n)
{   int count=0;
    int i;
    for(i=1;i<=n;i++)
        if(n%i==0)
        count++;
    return count;

}
int main()
{
  int n,i,j,maxfact=0;
  scanf("%d",&n);
  struct node *data=(struct node *)malloc(n*sizeof(struct node));
  struct node *sorted=(struct node *)malloc(n*sizeof(struct node));
  for(i=0;i<n;i++)
    scanf("%d",&data[i].n);
  for(i=0;i<n;i++)
    {
        data[i].factors=nof(data[i].n);
        if(data[i].factors>maxfact)
            maxfact=data[i].factors;
    }

  printf("%d\n",maxfact);
  int *c=(int *)malloc((maxfact+1)*sizeof(int));
  for(i=0;i<=maxfact;i++)
    c[i]=0;

  printf("C initialized with zeroes\n");
  print(c,maxfact+1);
  for(i=0;i<=maxfact;i++)
    c[data[i].factors]++;

  printf("C initialized with values\n");
  print(c,maxfact+1);
  for(i=maxfact-1;i>0;i--)    /* Since descending was asked, we flip the algo */
    c[i]+=c[i+1];

  printf("C modified to form C_hash\n");
  print(c,maxfact+1);
  for(i=n-1;i>=0;i--)
    {
        sorted[c[data[i].factors]-1].n=data[i].n;
        sorted[c[data[i].factors]-1].factors=data[i].factors;
        c[data[i].factors]--;
    }




  for(i=0;i<n;i++)
    printf("%d %d\n",sorted[i].n,sorted[i].factors);
}
