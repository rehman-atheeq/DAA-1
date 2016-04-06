#include<stdio.h>
int n,cost[10][10],i,j,cnt=1,visited[10],v;
void dfs(int v)
{
    for(i=1; i<=n; i++)
    {
        if(cost[v][i]&&visited[i]==0)
        {
            visited[i]=1;
            cnt++;
            printf("%d node visited\n",i);
            dfs(i);
        }
    }
}
int main()
{


    printf("Enter the no of nodes\n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&cost[i][j]);

    for(i=1; i<=n; i++)
        visited[i]=0;

    visited[1] = 1;
    cnt = 1;
    dfs(1);
    if(cnt==n)
    {
        printf("Connected\n");
    }
    else
    {
        printf("Not connected\n");
    }
    return 0;
}
