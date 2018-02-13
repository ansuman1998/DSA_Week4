#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void asc_merge_sort(int *a, int *temp, int low, int high)
{
	if(low>=high)
		return;
	int mid=(high+low)>>1;
	asc_merge_sort(a,temp,low,mid);
	asc_merge_sort(a,temp,mid+1,high);
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
void desc_merge_sort(int *a, int *temp, int low, int high)
{
	if(low>=high)
		return;
	int mid=(high+low)>>1;
	desc_merge_sort(a,temp,low,mid);
	desc_merge_sort(a,temp,mid+1,high);
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
int search(int *a, int n, int x)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==x)
			break;

	return i;

}
int main()
{
	int n,i,max=-1,cycle,totalasc=0,totaldesc=0,init;
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));		// input
	int *b=(int *)malloc(n*sizeof(int));        //copy of input to be sorted in ascending
	int *c=(int *)malloc(n*sizeof(int));		// copy of input to be sorted in descending
	int *temp=(int *)malloc(n*sizeof(int));		// for merge sort
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
			c[i]=a[i];

			if(a[i]>max)
			max=a[i];
		}
	int *visited=(int *)malloc((max+1)*sizeof(int)); //size of visited array is to be max+1 for obvious reasons
	for(i=0;i<=max;i++)
		visited[i]=-1;
    for(i=0;i<n;i++)
        visited[a[i]]=0;
	asc_merge_sort(b,temp,0,n-1);
	desc_merge_sort(c,temp,0,n-1);

	print(a,n); //Debugger
	print(b,n); //Debugger
	print(c,n); //Debugger
	init=0;  //Initial point of the first cycle
	cycle=0; //Length of cycle at present
	for(i=0;i<n;)
	{
		if(init==i&&cycle!=0)   //Case activated when a cycle completes
		{
			totalasc+=(cycle-1);   //total-ascending is updated
			cycle=0;            //cycle length is made zero to start again
			int j;
			for(j=i+1;j<n;j++)
				if(visited[a[j]]==0)
					break;

			i=j;                 //We should visit the next visited node only. Or else we will be caught in a loop
			init=j;          //Updating the initial point of the next cycle
		}

		else{


		visited[a[i]]=1;     //Mark node as visited
		//printf("%d\n",i); //Debugger
		i=search(b,n,a[i]);  //Position where a[i] SHOULD occur in the Ascending array
		cycle++;
		//printf("i = %d cycle = %d init = %d\n",i,cycle,init); //Debugger
		}

	}


	init=0;
	cycle=0;
	for(i=0;i<=max;i++)
		visited[i]=-1;
    for(i=0;i<n;i++)
        visited[a[i]]=0;

	for(i=0;i<n;)
	{
		if(init==i&&cycle!=0)   //Case activated when a cycle completes
		{
			totaldesc+=(cycle-1);   //total-descending is updated
			cycle=0;            //cycle length is made zero to start again
			int j;
			for(j=i+1;j<n;j++)
				if(visited[a[j]]==0)
					break;

			i=j;                 //We should visit the next visited node only. Or else we will be caught in a loop
			init=j;               //Updating the initial point of the next cycle
		}
		else{
		visited[a[i]]=1;     //Mark node as visited
		// printf("%d\n",i); //Debugger
		i=search(c,n,a[i]);  //Position where a[i] SHOULD occur in the Descending array
		cycle++;
		//printf("%d %d\n",i,cycle); //Debugger

	}}


	printf("Minimum Swaps in Descending = %d and Ascending = %d\n",totaldesc, totalasc);

}

