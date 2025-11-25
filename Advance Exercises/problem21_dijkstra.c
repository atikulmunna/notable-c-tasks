#include <stdio.h>
#include <limits.h>
int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    int i,j;
    int adj[n][n];
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&adj[i][j]);
    int src;
    scanf("%d",&src);
    int dist[n], vis[n];
    for(i=0;i<n;i++){ dist[i]=INT_MAX; vis[i]=0; }
    dist[src]=0;
    for(i=0;i<n;i++){
        int u=-1, best=INT_MAX;
        for(j=0;j<n;j++) if(!vis[j] && dist[j]<best){ best=dist[j]; u=j; }
        if(u==-1) break;
        vis[u]=1;
        for(j=0;j<n;j++) if(adj[u][j]!=-1 && !vis[j] && dist[u]!=INT_MAX){
            int nd=dist[u]+adj[u][j];
            if(nd<dist[j]) dist[j]=nd;
        }
    }
    for(i=0;i<n;i++){
        if(dist[i]==INT_MAX) printf("INF");
        else printf("%d",dist[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}