#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
    int data;
    struct Node *pnext;
    
    
} Node;
typedef struct  List
{
    Node *phead;
    Node *ptail;
}List;
Node *getNode(int x){
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
        printf("cap phat loi");
    else{
        p->data=x;
        p->pnext=NULL;
        return p;
    }
}

void init(List *l){
    l->phead=NULL;
    l->ptail=NULL;
}
void insert_head(List *l,Node *p){
    if(l->phead==NULL)
    {
        l->phead=p;
        l->ptail=p;
    }
    else{
        p->pnext=l->phead;
        l->phead=p;
    }
}
void insert_last(List *l,Node *p)
{
    if(l->phead==NULL){
        l->phead=p;
        l->ptail=p;
    }else{
        l->ptail->pnext=p;
        l->ptail=p;
    }
}
void insert_mid(List *l,Node *p,Node *q)
{
    if(l->phead==NULL){
        l->phead=p;
        l->ptail=p;
    }else{
        if(q!=NULL)
        {
            p->pnext=q->pnext;
            q->pnext=p;
            if(q==l->ptail){
                l->ptail=p;
            }
        }
    }
}
void delete_head(List *l)
{
    Node *p=l->phead;
    if(l->phead==NULL){
        printf("danh sach trong!");
    }
    else
    {
        l->phead=p->pnext;
        if(l->phead==NULL){
            l->ptail=NULL;
        }
        free(p);
    }   
}
void delete_mid(List *l,int k){
    Node *p=l->phead;
    Node *q=NULL;
    while (p!=NULL)
    {
        if(p->data==k){
            break;
        }
        else
        {
            q=p;
            p=p->pnext;
        } 
    }
    if(p==NULL){
        printf("ko tim thay node co gia tri k");
    }
    else{
        q->pnext=p->pnext;
        if(q->pnext==NULL){
            l->ptail= q;
        }
    }
    free(p);
}
int main(){
    List l;
    Node *p;
    insert_head(&l,getNode(500));
    insert_last(&l,getNode(200));
    // delete_head(&l);
    int x;
    printf("nhap gia tri node can xoa : ");
    scanf("%d",&x);
    delete_mid(&l,x);
    Node *k;
    k=l.phead;
    // while (k!=NULL)
    // {
    //     if(k->data==200){
    //         p=k;
    //         break;
    //     }
    //     k=k->pnext;
    // }
    // insert_mid(&l,getNode(300),p);
    // Node *t=l.phead;
    printf("\ndanh sach :\n");
    while (k!=NULL)
    {
        printf("%d\t",k->data);
        k=k->pnext;
    }
    
    
    
}