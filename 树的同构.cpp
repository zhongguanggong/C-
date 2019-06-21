#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct BiTNode 
{
    char  data;
    struct BiTNode  *l, *r;
} BiTNode, *BiTree;

    BiTNode* noptr  = (BiTNode*)malloc(sizeof(BiTNode));

void add(BiTree &node,char a[100][10] ,int i){
    node  = (BiTNode*)malloc(sizeof(BiTNode));
    node->data = a[i][0];
    if(a[i][1] != '-')
	{
        add(node->l,a,a[i][1]-'0');
    }
    else{
        node->l = noptr;
    }
    if(a[i][2] != '-')
	{
        add(node->r,a,a[i][2]-'0');
    }
    else{
        node->r = noptr;
    }
}

BiTree build(){
    int n = 0,i;//先找到根节点是最重要的
    char a[100][10] ;
    int f[100] ;
    int rootnum = -1;
    scanf("%d",&n);
    if(n==0) return noptr;
    scanf("\n");//不加换行符回车会被下一个字符%c吃掉
    for(i=0;i<n;i++){
        if(i==n-1)
            scanf("%c %c %c",&a[i][0],&a[i][1],&a[i][2]);
        else
            scanf("%c %c %c\n",&a[i][0],&a[i][1],&a[i][2]);
        f[i] = 0;
    }

    for(i=0;i<n;i++){
        for(int j=0;j<3;j++){
            f[a[i][j]-'0'] = 1;
        }
    }
    for(i=0;i<n;i++){
        if(f[i]!=1)
            rootnum = i;
    }
    BiTree T;
    add(T,a,rootnum);
    return T;
}

int compare(BiTree t1,BiTree t2){
    if(t1==noptr&&t2==noptr)
        return 1;
    if(t1->data == t2->data){
        if(t1->l->data==t2->r->data && t1->r->data==t2->l->data){
           return (compare(t1->l,t2->r)&&compare(t1->r,t2->l));
        }
        if(t1->l->data==t2->l->data && t1->r->data==t2->r->data){
            return (compare(t1->l,t2->l)&&compare(t1->r,t2->r));

        }
        return 0;
    }
    else
        return 0;
}

int main(){
    noptr->data = 0;
    noptr->r = NULL;
    noptr->l = NULL;
    BiTree T1 = build();
    BiTree T2 = build();
    int b = compare(T1,T2);
    if(b == 1)
        printf("Yes\n");
    else
        printf("No\n");


    return 0;
}
