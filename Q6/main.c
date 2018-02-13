#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *ch, int low, int high)
{
    int mid=(low+high)>>1;
    char temp;
    int i=low,j=high;
    while(i<=j)
    {
        temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;
        i++;
        j--;
    }
}
int main()
{
    char ch[1000];
    scanf("%[^\n]s", ch);
    int n=strlen(ch);
    int i,j;
    reverse(ch,0,n-1);
    printf("%s\n",ch);
    for(i=0;i<n;)
    {
        for(j=i;j<n;j++)
            if(ch[j]==' '||ch[j]=='\n')
                break;
        printf("%d %d\n",i,j);
        reverse(ch,i,j-1);
        i=j+1;

    }
    printf("%s\n",ch);

}
