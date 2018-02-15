#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int i,j,n,count;
    scanf("%s", s);
    n = strlen(s);
    count=0;
///////////////////////// CASE 1 //////////////////////////
    for(i=0;i<n;i++)
    {
        if(s[i]=='9')
            count++;
    }
    if(count==n)
    {
        printf("1");
        for(i=0;i<n-1;i++)
            printf("0");
        printf("1");
        return;
    }
///////////////////////// CASE 2 ///////////////////////////
    int *a = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        a[i]=s[i]-48;


        i=(n-1)/2;
        j=n/2;


    while(i>=0&&j<n&&a[i]==a[j])
    {
        i--;
        j++;
    }
    if(i==-1 && j==n)
     {

        printf("Already a palindrome");
        printf("\n");

        i=(n-1)/2;
        j=n/2;
        int carry=1;
        for(i=(n-1)/2;i>=0,j<n;i--,j++)
        {
            a[i]=a[i]+carry;
            carry=a[i]/10;
            a[i]=a[i]%10;
            a[j]=a[i];
        }

    for(i=0;i<n;i++)
        printf("%d", a[i]);
    printf("\n");

    }
    ////////////////////////// CASE 3 /////////////////////////////////
    else{

        if(a[i]>a[j])
        {   while(i>=0 && j<n)
            {
                a[j]=a[i];
                i--;
                j++;
            }
        }
        else
        {   i=(n-1)/2;
            j=n/2;
            int carry=1;
            while(i>=0 && j<n)
            {
                a[i]+=carry;
                carry=a[i]/10;
                a[i]=a[i]%10;
                a[j]=a[i];
                i--;
                j++;
            }
        }
        for(i=0;i<n;i++)
            printf("%d", a[i]);
        printf("\n");
    }



}
