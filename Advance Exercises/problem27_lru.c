#include <stdio.h>
#include <stdlib.h>
struct Node{int k,v; struct Node*prev; struct Node*next;};
struct Cache{int cap,size; struct Node*head; struct Node*tail; struct Node** map; int mapSize;};
struct Node* nn(int k,int v){ struct Node* n=malloc(sizeof(struct Node)); n->k=k;n->v=v;n->prev=n->next=NULL; return n;}
struct Cache* create(int cap){
    struct Cache* c=malloc(sizeof(struct Cache)); c->cap=cap; c->size=0; c->head=c->tail=NULL; c->mapSize=10007; c->map=calloc(c->mapSize,sizeof(struct Node*)); return c;
}
int h(int key,int m){ return (key>=0?key: -key)%m; }
struct Node* mapGet(struct Cache* c,int key){ int idx=h(key,c->mapSize); int start=idx;
    while(c->map[idx]){ if(c->map[idx]->k==key) return c->map[idx]; idx=(idx+1)%c->mapSize; if(idx==start) break; } return NULL;
}
void mapPut(struct Cache* c, struct Node* node){
    int idx=h(node->k,c->mapSize);
    while(c->map[idx]) idx=(idx+1)%c->mapSize;
    c->map[idx]=node;
}
void removeNode(struct Cache* c, struct Node* n){
    if(n->prev) n->prev->next=n->next; else c->head=n->next;
    if(n->next) n->next->prev=n->prev; else c->tail=n->prev;
}
void addFront(struct Cache* c, struct Node* n){
    n->next=c->head; n->prev=NULL;
    if(c->head) c->head->prev=n; c->head=n;
    if(!c->tail) c->tail=n;
}
int getVal(struct Cache* c,int key){
    struct Node* node=mapGet(c,key);
    if(!node) return -1;
    removeNode(c,node); addFront(c,node);
    return node->v;
}
void putVal(struct Cache* c,int key,int val){
    struct Node* node=mapGet(c,key);
    if(node){ node->v=val; removeNode(c,node); addFront(c,node); return; }
    if(c->size==c->cap){ struct Node* lru=c->tail; removeNode(c,lru); c->size--; int idx=h(lru->k,c->mapSize); while(c->map[idx] && c->map[idx]->k!=lru->k) idx=(idx+1)%c->mapSize; c->map[idx]=NULL; }
    struct Node* nnod=nn(key,val); addFront(c,nnod); mapPut(c,nnod); c->size++;
}
int main(){
    int cap,q; if(scanf("%d %d",&cap,&q)!=2) return 0;
    struct Cache* c=create(cap);
    for(int i=0;i<q;i++){
        char op[10]; scanf("%s",op);
        if(op[0]=='G'){ int key; scanf("%d",&key); int v=getVal(c,key); if(v==-1) printf("-1\n"); else printf("%d\n",v); }
        else { int k,v; scanf("%d %d",&k,&v); putVal(c,k,v); }
    }
    struct Node* cur=c->head;
    while(cur){ printf("%d:%d",cur->k,cur->v); if(cur->next) printf(" "); cur=cur->next; }
    printf("\n");
    return 0;
}