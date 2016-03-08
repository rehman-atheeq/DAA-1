#include<stdio.h>
int v[100][100],c[100],w[100];
int max(int i,int j)
{
    if(i>j)
        return i;
    return j;
}


int knapscak(int i,int j)
{
    if(v[i][j]!=0)
    {
        if(j<w[i])
            v[i][j]=knapscak(i-1,j);
        else
        {
            v[i][j]=max(knapscak(i-1,j),(knapscak(i-1,j-w[i])+c[i]));
        }
    }
    return v[i][j];
}

int main()
{
    int max_cap,n,i,j;

    printf("Enter the no of Items:\n");
    scanf("%d",&n);

    printf("Enter the Cost & Weight of %d items:\n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%d  %d",&c[i],&w[i]);
    }

    printf("Enter the Max Capacity of Sack:\n");
    scanf("%d",&max_cap);

    for(i=0; i<=n; i++)
        for(j=0; j<=max_cap; j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else
                v[i][j]=-1;
        }

    printf("Max value of sack is %d\n", knapscak(n, max_cap));

    i=n;
    j=max_cap;
    while(i>0&&j>0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            printf("Included %d\t",i);
            j=j-w[i];
        }
            i=i-1;
    }
    return 0;
}
