#include <stdio.h>
typedef long long ll;
ll solve(int n,int row,int cols,int diags,int anti){
    if(row==n) return 1;
    int avail = ((1<<n)-1) & ~(cols|diags|anti);
    ll cnt=0;
    while(avail){
        int bit = avail & -avail;
        avail -= bit;
        cnt += solve(n,row+1,cols|bit,(diags|bit)<<1,(anti|bit)>>1);
    }
    return cnt;
}
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    if(n<=0){ printf("0\n"); return 0; }
    if(n>31){ printf("0\n"); return 0; }
    printf("%lld\n", solve(n,0,0,0,0));
    return 0;
}