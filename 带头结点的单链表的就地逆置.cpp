#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;   //一个尾指针，一个指向新节点的指针
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //先建立一个带头结点的单链表
    rearPtr=L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    for (int i=1;i<=n;i++){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr=(LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);//输入元素值
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    curPtr->next=NULL;  //最后一个节点的next赋空
    return OK;
}
void ListReverse_L(LinkList &L);
void ListPrint_L(LinkList &L){
//输出单链表
    LNode *p=L->next;  //p指向第一个元素结点
    while(p!=NULL)
    {
          if(p->next!=NULL)
               printf("%d ",p->data);
          else
               printf("%d",p->data);
          p=p->next;
    }
}
int main()
{
    LinkList L;
    int n;
    scanf("%d",&n);
    if(ListCreate_L(L,n)!= OK) {
          printf("表创建失败！！！\n");
          return -1;
    }
    ListReverse_L(L);
    ListPrint_L(L);
    return 0;
}

void ListReverse_L(LinkList &L)
{
	int i = 0,j,k,x;
	LNode *p,*s;
	p = L->next;
	for(;NULL != p;p = p->next)
	{
		i++;
	}
	p = L;
	for(j=0;j<(i/2);j++)
	{
		p = p->next;
		s = L;
		for(k = 0;k<i-j;++k)
		{
			s = s->next; 
		}
		x = p->data;
		p->data = s->data;
		s->data = x;
	}
	
}
