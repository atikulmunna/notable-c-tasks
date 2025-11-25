#include <stdio.h>
#include <string.h>
int bfs(int n,int rcap[n][n],int s,int t,int parent[]){
    int vis[n]; memset(vis,0,sizeof(vis));
    int q[n], head=0, tail=0;
    q[tail++]=s; vis[s]=1; parent[s]=-1;
    while(head<tail){
        int u=q[head++];
        for(int v=0;v<n;v++) if(!vis[v] && rcap[u][v]>0){
            q[tail++]=v; parent[v]=u; vis[v]=1;
        }
    }
    return vis[t];
}
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int cap[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&cap[i][j]);
    int s,t; scanf("%d %d",&s,&t);
    int rcap[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) rcap[i][j]=cap[i][j];
    int parent[n];
    int maxflow=0;
    while(bfs(n,rcap,s,t,parent)){
        int pathflow=1<<30;
        int v=t;
        while(v!=s){ int u=parent[v]; if(rcap[u][v]<pathflow) pathflow=rcap[u][v]; v=u; }
        v=t;
        while(v!=s){ int u=parent[v]; rcap[u][v]-=pathflow; rcap[v][u]+=pathflow; v=u; }
        maxflow+=pathflow;
    }
    printf("%d\n",maxflow);
    return 0;
}