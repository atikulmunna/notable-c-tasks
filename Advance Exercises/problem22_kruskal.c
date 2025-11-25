#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    int wa=((int*)a)[2], wb=((int*)b)[2];
    return wa-wb;
}
int findp(int *p,int x){ return p[x]==x?x:p[x]=findp(p,p[x]); }
int main(){
    int n,m;
    if(scanf("%d %d",&n,&m)!=2) return 0;
    int edges[m][3];
    for(int i=0;i<m;i++) scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
    qsort(edges,m,3*sizeof(int),cmp);
    int p[n];
    for(int i=0;i<n;i++) p[i]=i;
    int cnt=0, total=0;
    for(int i=0;i<m && cnt<n-1;i++){
        int u=edges[i][0], v=edges[i][1], w=edges[i][2];
        int pu=findp(p,u), pv=findp(p,v);
        if(pu!=pv){ p[pu]=pv; total+=w; cnt++; }
    }
    if(cnt==n-1) printf("%d\n",total);
    else printf("NO MST\n");
    return 0;
}