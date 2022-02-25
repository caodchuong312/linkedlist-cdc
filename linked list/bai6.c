#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct sinhvien
{
    char Ho_ten[30];
    int Tuoi;
    float Diem_TB;
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
void nhapthongtinsinhvien(sinhvien *x)
{
    printf("nhap ten sinh vien: ");
    gets(x->Ho_ten);
    printf("nhap tuoi: ");
    scanf("%d",&x->Tuoi);
    printf("nhap diem: ");
    scanf("%f",&x->Diem_TB);
    fflush(stdin);
}
void nhapdssinhvien(List *l,sinhvien *x,int n){
    int i;
    for(i=1;i<=n;i++){
        printf("\nnhap sinh vien thu %d :\n",i);
        fflush(stdin);
        nhapthongtinsinhvien(x);
        Node *p=getNode(*x);
        insert_last(l,p);
    }
}
void indanhsach(List l,int n){
    Node *k;
    k=l.phead;
    printf("\n\t\tDanh sach sinh vien :\n\n");
    printf("%5s%20s%20s%20s","STT","Ho ten","Tuoi","Diem TB\n");
    int stt=1;
    while (k!=NULL)
    {
        printf("%5d %18s %16d %18.2f\n",stt,k->data.Ho_ten,k->data.Tuoi,k->data.Diem_TB);
        k=k->pnext;
        stt++;
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
Node *search(List l, char k[30]){
	Node *p=l.phead;
	while(p!=NULL){
		if(stricmp(p->data.Ho_ten, k)==0){
			return p;
		}
		p=p->pnext;
	}
	return 0;
}
void delete_mid(List *l,char t1[30]){
    Node *p=l->phead;
    Node *q=NULL;
    while (p!=NULL)
    {
        if(stricmp(t1,p->data.Ho_ten)==0){
            break;
        }
        else
        {
            q=p;
            p=p->pnext;
        } 
    }
    if(p==NULL){
        printf("ko tim ten sinh vien");
    }
    else if (p==l->phead)
    {
        l->phead=p->pnext;
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
    sinhvien x;
    init(&l);
    int n;
    printf("nhap so sinh vien: ");
    scanf("%d",&n);
    nhapdssinhvien(&l,&x,n);
    indanhsach(l,n);
    char t[30];
    printf("nhap ten sinh vien muon chen phia sau : ");
    gets(t);
    if(search(l,t)==NULL)
        {printf("ko tim thay ten sinh vien !");}
    else{
    nhapthongtinsinhvien(&x);}
    insert_mid(&l,getNode(x),search(l,t));
    indanhsach(l,n);
    char t1[30];
    printf("nhap ten sinh vien can xoa : ");
    gets(t1);
    delete_mid(&l,t1);
    indanhsach(l,n);

}