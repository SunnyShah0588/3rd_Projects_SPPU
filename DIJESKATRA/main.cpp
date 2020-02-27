#include <stdio.h>
#define inf 999;

void shortest(int n,int G[10][10],int u)
{
    int i;
    int v,visited[20],dist[10],count;
    int min=99;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=G[u][i];
    }
    count=2;
    visited[u]=1;
    while(count<n)
    {
        for(i=0;i<n;i++)
        {
            if(dist[i]<min && visited[i]==0)
            {
                min=dist[i];
                v=i;
            }

        }
        visited[v]=1;
        count++;
        for(i=0;i<n;i++)
        {
            if((dist[v]+G[v][i])<dist[i] && visited[i]==0)
            {
                dist[i]=dist[v]+G[v][i];
            }
        }
    }
    printf("\n Enter the End POINT(Destination): ");
    scanf("%d", &v);
    for(i=0;i<n;i++)
    {
        if(i==v)
        {
            printf("Distance From Vertex %d to %d: %d",u,v,dist[v]);
        }
    }
}
int main()
{
    int G[10][10],u,n;
    int i,j;
    printf("\nEnter the No, of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nEnter the Distance between vertex %d and %d:",i,j);
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
                G[i][j]=inf;
        }
    }
    printf("\nEnter the Starting Point(source): ");
    scanf("%d",&u);
    shortest(n,G,u);
    return 0;

}

