#include <stdio.h>
#include <stdlib.h>
struct Node{int v,h; struct Node*l; struct Node*r;};
int height(struct Node* t){ return t? t->h:0; }
struct Node* newnode(int v){ struct Node* n=malloc(sizeof(struct Node)); n->v=v; n->l=n->r=NULL; n->h=1; return n;}
struct Node* rotateRight(struct Node* y){
    struct Node* x=y->l; struct Node* T2=x->r; x->r=y; y->l=T2;
    y->h=1+ (height(y->l)>height(y->r)?height(y->l):height(y->r));
    x->h=1+ (height(x->l)>height(x->r)?height(x->l):height(x->r));
    return x;
}
struct Node* rotateLeft(struct Node* x){
    struct Node* y=x->r; struct Node* T2=y->l; y->l=x; x->r=T2;
    x->h=1+ (height(x->l)>height(x->r)?height(x->l):height(x->r));
    y->h=1+ (height(y->l)>height(y->r)?height(y->l):height(y->r));
    return y;
}
int getBalance(struct Node* n){ return n? height(n->l)-height(n->r):0; }
struct Node* insert(struct Node* node,int key){
    if(!node) return newnode(key);
    if(key<node->v) node->l=insert(node->l,key);
    else node->r=insert(node->r,key);
    node->h=1+ (height(node->l)>height(node->r)?height(node->l):height(node->r));
    int balance=getBalance(node);
    if(balance>1 && key<node->l->v) return rotateRight(node);
    if(balance<-1 && key>node->r->v) return rotateLeft(node);
    if(balance>1 && key>node->l->v){ node->l=rotateLeft(node->l); return rotateRight(node); }
    if(balance<-1 && key<node->r->v){ node->r=rotateRight(node->r); return rotateLeft(node); }
    return node;
}
void inorder(struct Node* r){
    if(!r) return;
    inorder(r->l);
    printf("%d ",r->v);
    inorder(r->r);
}
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    struct Node* root=NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); root=insert(root,x); }
    inorder(root); printf("\n");
    printf("%d\n", height(root));
    return 0;
}