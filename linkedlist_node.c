#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Node
{
    int Data;
    struct Node *pNext;
}Node;
typedef struct List
{
    Node *pHead;
    Node *pTail;
}List;
void init(List *l)
{
    l->pHead=NULL;
    l->pTail=NULL;
}
Node *getNode(int x)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        return NULL;
    }
    else{
    p->Data=x;  //luu x vao data
    p->pNext=NULL;
    }
}
void AddHead(List *l)
{
    Node *p;
    int x;
    printf("\nnhap gia tri Node them vao dau : ");
    scanf("%d",&x);
    p=getNode(x);
    if(l->pHead==NULL)
    {   //node p them vao cung la head va tail
        l->pHead=p;
        l->pTail=p;
    }
    else{
        p->pNext=l->pHead;
        l->pHead=p;
    }
}
void AddTail(List *l)
{
    Node *p;
    int x;
    printf("\nnhap gia tri Node them vao cuoi : ");
    scanf("%d",&x);
    p=getNode(x);
    if(l->pHead==NULL)
    {   //node p them vao cung la head va tail
        l->pHead=p;
        l->pTail=p;
    }
    else{
        l->pTail->pNext=p;
        l->pTail=p;
    }
}
void AddMid_phiasau(List *l)    //them nut p sau node q;
{
    Node *p,*q;
    int x,y;
    printf("\nnhap gia tri Node p can them: ");
    scanf("%d",&x);
    p=getNode(x);
    printf("\nnhap gia tri Node q truoc node can them : ");
    scanf("%d",&y);
    q=getNode(y);
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }else{
        // if(q!=NULL)
        {
            Node *k;
            for(k=l->pHead;k!=NULL;k=k->pNext){
                if(k->Data==y)
                {
                    p->pNext=k->pNext;
                    k->pNext=p;
                }
            }
        }
    }
}
void AddMid_phiatruoc(List *l)
{
    Node *p,*q;
    int x,y;
    printf("\nnhap gia tri Node p can them: ");
    scanf("%d",&x);
    p=getNode(x);
    printf("\nnhap gia tri Node q sau node can them : ");
    scanf("%d",&y);
    q=getNode(y);
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else{
        if(l->pHead->Data==y){
            p->pNext=l->pHead;
            l->pHead=p;
        }
        else if (l->pTail->Data==y)
        {
            l->pTail->pNext=p;
            l->pTail=p;
        }
        
        else
        { Node *k,*g;
            for(k=l->pHead;k!=NULL;k=k->pNext){
                if(k->Data==y)
                {
                    p->pNext=k;
                    g->pNext=p;
                    break;
                }
                g=k;
            }
        }
    }
}
void Delete_Head(List *l){
    if(l->pHead==NULL){
        printf("danh sach trong!!!");
    }
    else
    {
        Node *p=l->pHead;
        l->pHead=p;
        l->pHead=l->pHead->pNext;
        free(p);
    }
}
void Delete_Tail(List *l){
    if(l->pHead==NULL){
        printf("danh sach trong!!!");
    }
    else{
        Node *p,*q;
        for(p=l->pHead;p!=NULL;p=p->pNext)
        {
            if(p==l->pTail)
            {
                free(l->pTail);
                l->pTail=q;
                q->pNext=NULL;
                break;
            }
            q=p;
        }
    }
}
void Delete_phiasau(List *l)
{
    Node *q;
    int a;
    printf("\nnhap gia tri node phia truoc node can xoa: ");
    scanf("%d",&a);
    q=getNode(a);
    if(l->pHead==NULL)
    {
        printf("danh sach trong");
    }
   
    else{
        Node *k,*g;
        if(q->pNext==NULL){
            printf("ko co node phia sau");
        }
        else{
        for(k=l->pHead;k!=NULL;k=k->pNext)
        {
            if(a==k->Data){
                g=k->pNext;
                k->pNext=g->pNext;
                free(g);
            }
        }
        }
    }
}
void Delete_khoak(List *l){
    int a;
    printf("\nnhap gia tri node can xoa : ");
    scanf("%d",&a);
    Node *p=getNode(a);
    Node *k,*q;
    if(a==l->pHead->Data)
        {
            p=l->pHead;
            l->pHead=p;
            l->pHead=l->pHead->pNext;
            free(p);
        }
        else{
            for(k=l->pHead;k!=NULL;k=k->pNext)
            {
                
                if(a==k->Data){
                    q->pNext=k->pNext;
                    free(p);
                    break;
                }
                q=k;
            }
            }
}
void sapxeptangdan(List *l)
{
    Node *p,*q;
    for(p=l->pHead;p!=NULL;p=p->pNext){
        for(q=p->pNext;q!=NULL;q=q->pNext){
            if(p->Data>q->Data){
                int temp=p->Data;
                p->Data=q->Data;
                q->Data=temp;
            }
        }
    }
}
int timMax(List *l){
    Node *p;
    int max=l->pHead->Data;
    for(p=l->pHead;p!=NULL;p=p->pNext){
        if(p->Data>max){
            max=p->Data;
        }
    }
    return max;
}
void indanhsach(List l)
{
    Node *k;
    k=l.pHead;
    printf("\n\t\t------------Danh Sach Lien Ket------------\n\t\t");
    while (k!=NULL)
    {   
        printf("%d\t",k->Data);
        k=k->pNext;
    }
    printf("\nnhan phim bat ki de tiep tuc\n");
    getch();
}
int main(){
    List l;
    Node *p;
    init(&l);
    int luachon;
    while (1)
    {
        printf("\n\t\t1: them node vao dau danh sach ");
        printf("\n\t\t2: them node vao cuoi danh sach ");
        printf("\n\t\t3: them node moi vao phia sau node q");
        printf("\n\t\t4: them node moi vao phia truoc node q");
        printf("\n\t\t5: xoa node dau danh sach ");
        printf("\n\t\t6: xoa node cuoi danh sach ");
        printf("\n\t\t7: xoa node phia sau node q ");
        printf("\n\t\t8: xoa node chi dinh ");
        printf("\n\t\t9: sap xep ");
        printf("\n\t\t10: tim gia tri lon nhat ");
        printf("\n\t\t11: thoat chuong trinh ");
        do
        {printf("\n\n\t\tnhap lua chon (1-11) : ");
        scanf("%d",&luachon);
        if(luachon<1||luachon>11){
            printf("nhap lai !");}
        }while(luachon<1||luachon>11);

        if(luachon==1){
            int n,i;
            printf("\nnhap so node can themvao dau ds: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                AddHead(&l);
            }
            indanhsach(l);
        }
        else if (luachon==2)
        {
           int n,i;
            printf("\nnhap so node can them vao cuoi ds: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                AddTail(&l);
            }
            indanhsach(l);
        }
        else if (luachon==3)
        {
            AddMid_phiasau(&l);
            indanhsach(l);
        }
        else if (luachon==4)
        {
            AddMid_phiatruoc(&l);
            indanhsach(l);
        }
        else if (luachon==5)
        {
            Delete_Head(&l);
            indanhsach(l);
        }
        else if (luachon==6)
        {
            Delete_Tail(&l);
            indanhsach(l);
        }
        else if (luachon==7)
        {
            Delete_phiasau(&l);
            indanhsach(l);
        }
        else if (luachon==8)
        {
            Delete_khoak(&l);
            indanhsach(l);
        }
        else if (luachon==9)
        {
            sapxeptangdan(&l);
            indanhsach(l);
        }
        else if (luachon==10)
        {
            int max=timMax(&l);
            printf("\ngia tri lon nhat la %d",max);
            indanhsach(l);
        }
        else{
            printf("chuong trinh ket thuc ! ");
            indanhsach(l);
            getch();
            break;
        }
    }
}


