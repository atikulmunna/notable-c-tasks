#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    if(scanf("%d %d",&n,&m)!=2) return 0;
    int *deg=calloc(n,sizeof(int));
    int **adj=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) adj[i]=calloc(n,sizeof(int));
    for(int i=0;i<m;i++){ int u,v; scanf("%d %d",&u,&v); adj[u][v]=1; deg[v]++; }
    int *q=malloc(n*sizeof(int)); int head=0,tail=0;
    for(int i=0;i<n;i++) if(deg[i]==0) q[tail++]=i;
    int cnt=0, order[n];
    while(head<tail){
        int u=q[head++]; order[cnt++]=u;
        for(int v=0;v<n;v++) if(adj[u][v]){
            deg[v]--;
            if(deg[v]==0) q[tail++]=v;
        }
    }
    if(cnt!=n){ printf("CYCLIC\n"); return 0; }
    for(int i=0;i<n;i++){ printf("%d",order[i]); if(i<n-1) printf(" "); }
    printf("\n");
    return 0;
}