#include<stdio.h>
#include<malloc.h>
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
Node *getNode(int x){
    Node *p;
    p=(Node*)malloc(sizeof(Node));//Cấp phát bộ nhớ động
    if(p==NULL)
    {
        printf("loi cap phat bo nho dong");
    }  
    p->Data=x;//Lưu x vào Data
    p->pNext=NULL;//khởi tạo mối liên kết
}
void AddHead(List *l,Node *p){                  //thêm Node p vào đầu danh sách
    if(l->pHead==NULL){//danh sách rỗng thì p vừa đầu vừa cuối
        l->pHead=p;
        l->pTail=p;
    }
    else{
        p->pNext=l->pHead;//p tham gia ds
        l->pHead=p;//p đứng đầu ds
    }
}
void AddTail(List *l,Node *p)       //thêm Node p vào cuối danh sách
{            
    if(l->pHead==NULL){//danh sách rỗng thì p vừa đầu vừa cuối
        l->pHead=p;
        l->pTail=p;
    }
    else{
        l->pTail=p;// l.Tail quăng dây nối với p
        l->pTail=p;
    }
}
void AddMid(List *l,Node *p)
{
    int a,b;
    printf("\nnhap not q  : ");
    scanf("%d",&a);
    
    Node *q=getNode(a);
    

    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else{
        //thêm Node p sau Node q
        // if(q->pNext!=NULL)
        //     {
        //        p->pNext=q->pNext;
        //        q->pNext=p;
        //        if(q==l->pTail)
        //        {
        //            l->pTail=q;
        //        }
        //     }
            Node *k;
            for(k=l->pHead;k!=NULL;k=k->pNext)
            {
                if(k->Data==a)
                {
                    p->pNext=k->pNext;
                    k->pNext=p;
                    if(k==l->pTail)
                    {
                        l->pTail=k;
                    }
                }
            }
    }      
}
void them_node_p_truoc_node_q(List *l,Node *p)

{
    int a;
    printf("nhap gia tri node q: ");
    scanf("%d",&a);
    Node *q=getNode(a);
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else{
        Node *k;
        Node *g;
        g=(Node*)malloc(sizeof(Node));
        for(k=l->pHead;k!=NULL;k=k->pNext)
        {
            
            if(k->Data==a)
            {
                p->pNext=k;
                g->pNext=p;
            }
            g=k;
        }
    }

}
void xoaNodeDau(List *l){
    
    if(l->pHead==NULL)
    {
        // l->pHead=p;
        // l->pTail=p;
        return;
    }
    else
    {
        Node *p=l->pHead;
        l->pHead=p;
        l->pHead=l->pHead->pNext;
        free(p);
    }
}
void xoaNodeCuoi(List *l){
    if(l->pHead==NULL)
    {
        // l->pHead=p;
        // l->pTail=p;
        return;
    }
    else
    {   
        Node *k,*p;
        for(k=l->pHead;k!=NULL;k=k->pNext)
        {
            if(k->pNext==NULL)
            {
                free(k);
                p->pNext=NULL;
                break;
                
            }
            p=k;
        }
    }
}
void xoaNodepsauNodeq(List *l)
{
    int a;
    printf("\nnhap gia tri Node q truoc Node p can xoa: ");
    scanf("%d",&a);
    Node *q=getNode(a);
    if(l->pHead==NULL)
    {
        printf("ko co Node nao");
        return ;
    }
    else{
        Node *k;
        for(k=l->pHead;k!=NULL;k=k->pNext)
        {
            if(k->Data==a)
            {
                Node *g;        //tạo Node g là Node phía sau Node q   (q->p->g)
                g=k->pNext;     
                k->pNext=g->pNext;
                free(g);
                break;
            }
        }
    }
}
void input(List *l){
    int i,n,x;
    printf("nhap so luong can them : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("nhap so nguyen can them : ");
        scanf("%d",&x);
        Node *p= getNode (x);
        AddHead(l,p);    
    }
}
void output(List l){
    Node *p;
    printf("\n----In danh sach lien ket-----\n");
    for( p=l.pHead;p!=NULL;p=p->pNext){
        printf("%5d",p->Data);
    }
}
int main(){
    int x;
    List l;
    init(&l);
    printf("nhap list: \n");
    input(&l);
    output(l);
    // int b;
    // xoaNodeDau(&l);
    // xoaNodeCuoi(&l);
    xoaNodepsauNodeq(&l);
    // printf("\nnhap not p can them sau not q: ");
    // scanf("%d",&b);
    // AddMid(&l,p);
    // printf("\nnhap not p can them truoc not q: ");
    // scanf("%d",&b);
    // Node *p=getNode(b);
    // them_node_p_truoc_node_q(&l,p);
    output(l);
}


