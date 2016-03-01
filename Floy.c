#include<stdio.h>
#include<omp.h>
int minimum(int x,int y)
{
    if(x<y)
        return x;
    return y;
}
int main()
{
    int a[10][10],i,j,k,n,x,y;
    float duration,start,end;
    printf("Enter the no of nodes:\n");
    scanf("%d",&n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            a[i][j]=rand()%100;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");start=omp_get_wtime();
#pragma omp parallel
    {

        #pragma omp for
        for(k=0; k<n; k++)
        {

            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                {
                    a[i][j]=minimum(a[i][j],a[i][k]+a[k][j]);
                }
        }
    }
    end=omp_get_wtime();
    duration=(end-start);
    printf("\n%d",duration);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

