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
typedef char  ElemType; //假设线性表中的元素均为整型

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
    L->next=NULL; //先建立一个带头结点的单链表
	//p = L->next;
	
    rearPtr=L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    for (int i=1;i<=n;i++){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr=(LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr)exit(OVERFLOW);
        scanf(" %c",&curPtr->data);//输入元素值
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
	printf("0\n");
    curPtr->next=NULL;  //最后一个节点的next赋空
    return OK;
}
void ListPrint_L(LinkList &L){
//输出单链表
    LNode *p=L->next;  //p指向第一个元素结点
    while(p!=NULL)
    {
          if(p->next!=NULL)
               printf("%c ",p->data);
          else
               printf("%c",p->data);
          p=p->next;
    }
}


int main()
{
    int i = 0;
	LinkList L,L1;
	LNode *p,*s;
    int n;
    scanf("%d",&n);
    if(ListCreate_L(L,n)!= OK) {
          printf("表创建失败！！！\n");
          return -1;
    }
    ListPrint_L(L);
	printf("\n%d\n",n);
	if(L == NULL) printf("yes\n");
	else printf("no\n");
	p=L;
	while(i<3)
	{
		p = p->next ;
		++i;
	}
	printf("%c\n",p->data);
	i = 0;
	for(p = L;p != NULL;p=p->next )
	{
		if(p->data == 'a')
			break;
		++i;
	}
	printf("%d\n",i);
	p = L;
	s = L;
	L1 = (LNode*)malloc(sizeof (LNode));
	L1->data = 'x';
	for(i = 0;i<4;++i)
	{
		p = p->next ;
	}
	for(i = 0;i<3;++i)
	{
		s = s->next ;
	}
	L1->next = p;
	s->next = L1;
	ListPrint_L(L);
	s = L;
	for(i = 0;i<2;++i)
	{
		s = s->next ;
	}
	s->next = L1;
	printf("\n");
	ListPrint_L(L);
	free(L);

    return 0;
}


	

