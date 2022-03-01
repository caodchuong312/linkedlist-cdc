#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
typedef struct sinhvien
{
    char masv[30];
    char hoten[30];
    int tuoi;
    float diem;
}sinhvien;
typedef struct Node
{
    sinhvien data;
    struct Node *pNext;
}Node;
typedef struct List
{
    Node *pHead;
    Node *pTail;
}List;
Node *getNode(sinhvien sv)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("ERROR!");
    }
    else{
        p->data=sv;
        p->pNext=NULL;
        return p;
    }
}
void init(List *l){
    l->pHead=NULL;
    l->pTail=NULL;
}
void nhapsinhvien(sinhvien *sv){
    
    printf("nhap ma sinh vien : ");
    gets(sv->masv);
    printf("nhap ho ten: ");
    gets(sv->hoten);
    printf("nhap tuoi : ");
    scanf("%d",&sv->tuoi);
    printf("nhap diem : ");
    scanf("%f",&sv->diem);
    fflush(stdin);
}
Node *Search(List l ,char ten[50])
{
    Node *p;
    for(p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(stricmp(p->data.hoten,ten)==0)
            {return p;}
    }
    return 0;
}
void insert_last(List *l,Node *p)
{
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else
    {
        l->pTail->pNext=p;
        l->pTail=p;
    }
}
void insert_head(List *l,Node *p)
{
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else{
        p->pNext=l->pHead;
        l->pHead=p;
    }
}
void insert_mid(List *l,Node *p,Node *q){
    if(l->pHead==NULL){
        l->pHead=p;
        l->pTail=p;
    }
    else{
        if(q!=NULL){
            p->pNext=q->pNext;
            q->pNext=p; 
            if(q==l->pTail){
                l->pTail=p;
            }
        }
    }
}
void insert_mid_phiatruoc(List *l){
    Node *k,*p,*q,*g;
    sinhvien sv;
    printf("nhap ten sinh vien (q) : ");
    char tenq[50];
    gets(tenq);
    if(Search(*l,tenq)==NULL){
        printf("ko tim thay ten sinh vien");
    }
    else
    {   
        nhapsinhvien(&sv);
        p=getNode(sv);
        if(stricmp(l->pHead->data.hoten,tenq)==0)
        {
            p->pNext=l->pHead;
            l->pHead=p;
        }
        else
        {    for(k=l->pHead;k!=NULL;k=k->pNext)
            {
                if(stricmp(k->data.hoten,tenq)==0)
                {
                    p->pNext=k;
                    g->pNext=p;
                    break;
                }
                g=k;
            }   }
    }
}

void themsinhvienvaosau(List *l){
    Node *p;
    sinhvien x;
    
    char tenq[50];
    printf("\nnhap ten sinh vien (q) la: ");
    gets(tenq);
    if(Search(*l,tenq)==NULL){
        printf("\nerror");
    }
    else
        {printf("\nnhap thong tin sinh vien can them: \n");
        nhapsinhvien(&x);
        insert_mid(l,getNode(x),Search(*l,tenq));}

}
void nhapdssinhvien_last(List *l,sinhvien *sv,int n){
    int i;
    
    for(i=0;i<n;i++){
        nhapsinhvien(sv);
        Node *p=getNode(*sv);
        insert_last(l,p);
        // insert_head(l,p);
        printf("\n");
    }
}
void nhapdssinhvien_head(List *l,sinhvien *sv,int n){
    int i;
    
    for(i=0;i<n;i++){
        nhapsinhvien(sv);
        Node *p=getNode(*sv);
        // insert_last(l,p);
        insert_head(l,p);
        printf("\n");
    }
}
void delete_head(List *l){
    if(l->pHead==NULL){
        printf("ERROR");
    }else{
        Node *p=l->pHead;
        l->pHead=p;
        l->pHead=l->pHead->pNext;
        free(p);
    }
}
void delete_tail(List *l){
    Node *k,*g;
    for(k=l->pHead;k!=NULL;k=k->pNext){
        if(l->pTail==k){
            free(l->pTail);
            l->pTail=g;
            g->pNext=NULL;
            break;
        }
        g=k;
    }
}
void delete_nodephiasau(List *l){
    //xoa node sau q
    Node *q;
    char ten[50];
    printf("\nnhap ten q: ");
    gets(ten);
    Node *k;
    if(Search(*l,ten)==NULL){
        printf("ko tim thay ten sv");
    }
    else 
    {   if(stricmp(l->pTail->data.hoten,ten)==0){
            printf("ko co sinh vien nao phia sau");
        }
    else
        {
            for(k=l->pHead;k!=NULL;k=k->pNext){
            if(stricmp(k->data.hoten,ten)==0){
                Node *p;
                p=k->pNext;
                k->pNext=p->pNext;
                free(p);
            }
            }
        }
    }
}
void delete_khoak(List *l){
    char ten[50];
    printf("\nnhap ten sinh vien can xoa ");
    gets(ten);
    if(Search(*l,ten)==NULL){
        printf("ko tim thay ten sinh vien!");
    }
    else{
        Node *k,*g;
        if(stricmp(l->pHead->data.hoten,ten)==0)
        {
            delete_head(l);
        }
        for(k=l->pHead;k!=NULL;k=k->pNext)
        {
            if(stricmp(k->data.hoten,ten)==0){
                g->pNext=k->pNext;
                free(k);
                break;
            }
            g=k;
        }
    }
}
void output(List l){
    Node *k;
    int stt=1;
    printf("\n\t\tDANH SACH SINH VIEN\t\t\n");
    printf("%-5s%10s%20s%15s%15s\n","STT","MA SV","HO TEN","TUOI","DIEM");
    for(k=l.pHead;k!=NULL;k=k->pNext)
    {
        printf("%-5d%10s%20s%15d%15.2f\n",stt,k->data.masv,k->data.hoten,k->data.tuoi,k->data.diem);
        stt++;
    }
}

int main(){
    List l;
    sinhvien sv;
    init(&l);
    int n;
    
    // printf("nhan phim bat ki de tiep tuc ");
    // getch();
    int luachon;
    while(69)
    {
        printf("\n1. them sinh vien vao cuoi danh sach ");
        printf("\n2. them sinh vien vao dau danh sach ");
        printf("\n3. them sinh vien vao sau 1 sinh vien khac  ");
        printf("\n4. them sinh vien vao truoc 1 sinh vien khac ");
        printf("\n5. xoa sinh vien cuoi danh sach ");
        printf("\n6. xoa 1 sinh vien dau danh sach ");
        printf("\n7. xoa 1 sinh vien sau 1 sinh vien khac ");
        printf("\n8. xoa 1 sinh vien chi dinh ");
        printf("\n9. thoat chuong tinh ");
        do
        {printf("\n\nnhap lua chon (1-9) : ");
        scanf("%d",&luachon);
        fflush(stdin);
        if(luachon<1||luachon>9){
            printf("nhap lai !");}
        }while(luachon<1||luachon>9);
        if(luachon==1){
            printf("nhap so luong sinh vien can them vao cuoi danh sach : ");
            scanf("%d",&n);
            fflush(stdin);
            nhapdssinhvien_last(&l,&sv,n);
            output(l);
        }
        else if (luachon==2)
        {
            printf("nhap so luong sinh vien can them vao dau danh sach : ");
            scanf("%d",&n);
            fflush(stdin);
            nhapdssinhvien_head(&l,&sv,n);
            output(l);
        }
        else if (luachon==3)
        {
                themsinhvienvaosau(&l);
                output(l);
        }
        else if (luachon==4)
        {
            insert_mid_phiatruoc(&l);
            output(l);
        }
        else if (luachon==5)
        {
            
            delete_tail(&l);
            printf("\nsau khi xoa :\n");
            output(l);
        }
        else if (luachon==6)
        {
            delete_head(&l);
            printf("\nsau khi xoa :\n");
            output(l);
        }
        else if (luachon==7)
        {
            delete_nodephiasau(&l);
            printf("\nsau khi xoa :\n");
            output(l);
        }
        else if (luachon==8)
        {
            delete_khoak(&l);
            printf("\nsau khi xoa :\n");
            output(l);
        }
        else{
            output(l);
            printf("ket thuc chuong trinh!");
            getch();
            break;
        }
    }
    

}

