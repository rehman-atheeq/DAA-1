#include<stdio.h>
int n,cost[10][10],i,j,cnt=1,visited[10],v,q[10],r,f;
void bfs()
{
    r=1;f=0;q[0]=1;
    visited[1]=1;
    while(f<r)
    {
        v=q[f];
        for(i=1; i<=n; i++)
        {
            if(cost[v][i]&&visited[i]==0)
            {
                visited[i]=1;
                cnt++;
                printf("%d node visited\n",i);
                q[r++]=i;
            }
        }
        f++;
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

    printf("%d is visited\n",1);
    bfs();
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
