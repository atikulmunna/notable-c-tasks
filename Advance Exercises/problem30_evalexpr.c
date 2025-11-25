#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
double apply(char op,double a,double b){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    if(op=='^') return pow(a,b);
    return 0;
}
int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}
int isRightAssoc(char c){ return c=='^'; }
int main(){
    char expr[1000];
    if(!fgets(expr,sizeof(expr),stdin)) return 0;
    int L=strlen(expr);
    char ops[1000]; int topo=-1;
    double vals[1000]; int topv=-1;
    for(int i=0;i<L;i++){
        if(expr[i]==' '||expr[i]=='\t'||expr[i]=='\n') continue;
        if(isdigit(expr[i])||expr[i]=='.'){
            char num[100]; int ni=0;
            while(i<L && (isdigit(expr[i])||expr[i]=='.')) num[ni++]=expr[i++];
            num[ni]=0; i--;
            vals[++topv]=atof(num);
        } else if(expr[i]=='('){ ops[++topo]=expr[i]; }
        else if(expr[i]==')'){
            while(topo!=-1 && ops[topo]!='('){
                char op=ops[topo--];
                double b=vals[topv--]; double a=vals[topv--];
                vals[++topv]=apply(op,a,b);
            }
            if(topo!=-1) topo--;
        } else {
            char cur=expr[i];
            while(topo!=-1 && ops[topo]!='(' && (prec(ops[topo])>prec(cur) || (prec(ops[topo])==prec(cur) && !isRightAssoc(cur)))){
                char op=ops[topo--];
                double b=vals[topv--]; double a=vals[topv--];
                vals[++topv]=apply(op,a,b);
            }
            ops[++topo]=cur;
        }
    }
    while(topo!=-1){
        char op=ops[topo--];
        double b=vals[topv--]; double a=vals[topv--];
        vals[++topv]=apply(op,a,b);
    }
    if(topv==0) printf("%.10g\n", vals[topv]);
    else printf("ERROR\n");
    return 0;
}