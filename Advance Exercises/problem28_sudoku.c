#include <stdio.h>
int safe(int b[9][9],int r,int c,int num){
    for(int x=0;x<9;x++) if(b[r][x]==num) return 0;
    for(int x=0;x<9;x++) if(b[x][c]==num) return 0;
    int sr=r-r%3, sc=c-c%3;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(b[sr+i][sc+j]==num) return 0;
    return 1;
}
int solve(int b[9][9]){
    for(int r=0;r<9;r++) for(int c=0;c<9;c++) if(b[r][c]==0){
        for(int num=1;num<=9;num++) if(safe(b,r,c,num)){
            b[r][c]=num;
            if(solve(b)) return 1;
            b[r][c]=0;
        }
        return 0;
    }
    return 1;
}
int main(){
    int b[9][9];
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) scanf("%d",&b[i][j]);
    if(solve(b)){
        for(int i=0;i<9;i++){ for(int j=0;j<9;j++){ printf("%d",b[i][j]); if(j<8) printf(" "); } printf("\n"); }
    } else printf("NO SOLUTION\n");
    return 0;
}