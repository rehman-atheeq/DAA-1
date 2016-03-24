#include<stdio.h>
int parent[10];
int find (int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}
int iscyc(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 0;
    }
    return 1;
}
int main()
{
    int mincst=0,cost[10][10],i,j,n,ne=1,min,a,b,u,v;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    while(ne<n)
    {

        for(i=0,min=999; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(cost[i][j]<(min))
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        u=find(u);
        v=find(v);

        if(!iscyc(u,v))
        {
            printf("\n%d\t edges (%d, %d)=%d",ne++,a,b,min);
            mincst+=min;
        }
        cost[a][b]=cost[b][a]=999;

    }
    printf("\nMincost=%d\t",mincst);

return 0;
}
