#include<stdio.h>
#include<stdlib.h>
#define max 100
#define infinity 999
int tspdp(int c[][max],int tour[],int start,int n);
int appr(int c[][max],int source,int n);
int main()
{
  int n;
  float e;
  int i,j,c[max][max];
  int tour[max],cost,sum;
  printf("Travelling sles person problem using DP\n");
  printf("Enter the number of cities to traverse:\t");
  scanf("%d",&n);
  printf("Enter the cost matrix:\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
    scanf("%d",&c[i][j]);
    if(c[i][j]==0)
     c[i][j]=999;
  }
  for(i=0;i<n;i++)
  tour[i]=i;
  cost=tspdp(c,tour,0,n);
  printf("Minimum cost:%d\n",cost);
  printf("Tour:\n");
  for(i=0;i<n;i++)
  printf("%d-",tour[i]+1);
  printf("1\n");
  printf("\nApproximation method:\n");
  sum=appr(c,0,n);
  printf("Approximated sum =%d\n",sum);
  e=(((float)sum-cost)/(float)sum)*100.0;
  printf("\nError in approximation is %f%",e);
  return 0;
}
int tspdp(int c[][max],int tour[],int start,int n)
{
  int i,j,temp[max],mintour[max];
  int mincost,ccost,k;
  if(start==(n-2))
   return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];
  mincost=infinity;
  for(i=start+1;i<n;i++)
  {
   for(j=0;j<n;j++)
   temp[j]=tour[j];
   temp[start+1]=tour[i];
   temp[i]=tour[start+1];
   if(c[tour[start]][tour[i]]+(ccost=tspdp(c,temp,start+1,n))<mincost)
   {
     mincost=c[tour[start]][tour[i]]+ccost;
     for(k=0;k<n;k++)
     mintour[k]=temp[k];
    }
   }
   for(i=0;i<n;i++)
    tour[i]=mintour[i];
   return mincost;
}
int appr(int c[][max],int source,int n)
{
  int i,j,u,v,sum=0,visited[10],d[10],s,min;
  for(i=0;i<n;i++)
  {
    visited[i]=0;
    d[i]=c[source][i];
  }
  visited[source]=1;
  printf("\nApproximated tree is %d",source+1);
  for(i=1;i<n-1;i++)
  {
    min=infinity;
    for(j=0;j<n;j++)
    if(!visited[j]&&d[j]<min)
    {
     min=d[j];
     u=j;
     }
     visited[u]=1;
     sum=sum+d[u];
     printf("->%d",u+1);
     for(v=0;v<n;v++)
     if(!visited[v])
     {
      d[v]=c[u][v];
     }
    }
    printf("->%d",source+1);
    sum=sum+c[u][source];
    return sum;
}

