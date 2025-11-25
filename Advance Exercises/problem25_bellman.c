#include <stdio.h>
#include <limits.h>
int main(){
    int n,m; if(scanf("%d %d",&n,&m)!=2) return 0;
    int edges[m][3];
    for(int i=0;i<m;i++) scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
    int src; scanf("%d",&src);
    long long dist[n];
    for(int i=0;i<n;i++) dist[i]=LLONG_MAX/4;
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0], v=edges[j][1], w=edges[j][2];
            if(dist[u]!=LLONG_MAX/4 && dist[u]+w<dist[v]) dist[v]=dist[u]+w;
        }
    }
    for(int j=0;j<m;j++){
        int u=edges[j][0], v=edges[j][1], w=edges[j][2];
        if(dist[u]!=LLONG_MAX/4 && dist[u]+w<dist[v]){ printf("NEGATIVE CYCLE\n"); return 0; }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==LLONG_MAX/4) printf("INF");
        else printf("%lld",dist[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}