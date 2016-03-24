#include<stdio.h>
int main()
{
    int c[10][10],i,j,n,ne=1,visited[10],mincst=0,min,a,b;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    printf("Enter the adj matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0)
                c[i][j]=999;
        }

    for(i=0; i<n; i++)
        visited[i] = 0;

    visited[0]=1;
    while(ne<n)
    {
        min=999;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(visited[i]!=0)
                {
                    if(c[i][j]<min)
                    {
                        min=c[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        printf("Smallest now is edge from %d to %d with cost %d\n", a, b, min);
        if(visited[a]==1 && visited[b]==0)
        {
            printf("%d\t edges (%d, %d)=%d\n",ne++,a,b,min);
            mincst+=min;
            visited[b]=1;
        }
        else
        {
            printf("Why ne is %d????\n", ne);
        }
        c[a][b]=c[b][a]=999;
    }
    printf("Mincost %d\n",mincst);

    return 0;
}


