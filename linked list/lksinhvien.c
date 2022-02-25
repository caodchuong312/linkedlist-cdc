#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct sinhvien
{
    char masv[30];
    char ten[30];
    char lop[30];
    int tuoi;
    float diem;
}sinhvien;
typedef struct Node
{
    sinhvien data;
    struct Node *pnext;
}Node;
typedef struct  List
{
    Node *phead;
    Node *ptail;
}List;
Node *getNode(sinhvien x){
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
void indanhsach(List l,sinhvien x){
    Node *k;
    k=l.phead;
    printf("\ndanh sach sinh vien tren 7 diem :\n");
    printf("%s\t\t %s\t\t %s\t\t %d\t\t%f\n","ma sv","ho ten","lop","tuoi","diem");
    while (k!=NULL)
    {
        if(k->data.diem>7){
            printf("%s\t\t %s\t\t %s\t\t %d\t\t%f\n",k->data.masv,k->data.ten,k->data.lop,k->data.tuoi,k->data.diem);
        }
        k=k->pnext;
    }
}
int main(){
    List l;
    sinhvien x;
    init(&l);
    int i;
    for(i=1;i<=3;i++)
    {
        printf("nhap ma sinh vien : ");
        gets(x.masv);
        printf("nhap ten sinh vien: ");
        gets(x.ten);
        printf("nhap lop: ");
        gets(x.lop);
        printf("nhap tuoi: ");
        scanf("%d",&x.tuoi);
        fflush(stdin);
        printf("nhap diem: ");
        scanf("%f",&x.diem);
        fflush(stdin);
        Node *p=getNode(x);
        insert_last(&l,p);
    }
    indanhsach(l,x);
}
