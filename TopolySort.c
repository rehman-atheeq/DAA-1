#include<stdio.h>
int main()
{
    int a[10][10],Inedg[10],s[10],i,j,n,top=-1;
    printf("Enter the no of nodes\n");
    scanf("%d",&n);

    printf("Enter the Elements of Matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(i=0; i<n; i++)
        Inedg[i]=0;

    for(j=0; j<n; j++)
        for(i=0; i<n; i++)
            if(a[i][j]==1)
                Inedg[j]++;

    for(i=0; i<n; i++)
        if(Inedg[i]==0)
            s[++top]=i;

    for(i=0; i<=top; i++)
        printf("%d\t",s[i]);

    int node;
    while (top != -1)
    {
        node = s[top--];
        printf("%d ", node);
        for(i=0; i<n; i++)
        {
            if (a[node][i] == 1)
            {
                Inedg[i]--;
                if (Inedg[i] == 0)
                    s[++top] = i;
            }
        }
    }

    return 0;
}


