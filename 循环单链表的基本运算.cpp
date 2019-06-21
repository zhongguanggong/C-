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
}LNode,*LinkList; //循环单链表类型定义与单链表定义相同，区别在尾节点next取值

Status ListCreate_CL(LinkList &CL); //链表创建 

void ListDelete_CL(LinkList &CL,int n);//链表元素删除

void ListPrint_CL_n(LinkList &CL,int n);//输出链表指定位置元素

void ListPrint_CL_char_PO(LinkList &CL,char n);//输出链表指定元素所在位置

void ListInSert(LinkList &CL,int n,char s);//在指定位置插入元素

int ListLength(LinkList &CL);//计算表长

void ListPrint_CL(LinkList &CL);//输出链表

int main() 
{  
    LinkList CL;
	LNode *p;
	int i;
    if(ListCreate_CL(CL)!= OK) //链表创建
    {
       printf("循环链表创建失败！！！\n");
       return -1;
    }   
    ListPrint_CL(CL);//输出链表
	i = ListLength(CL);
	printf("%d\n",i);//输出表长
	p = CL->next ;
	if(p == CL)
		printf("yes\n");
	else printf("no\n");//判断链表是否为空
	ListPrint_CL_n(CL,3);//输出第三个元素
	ListPrint_CL_char_PO(CL,'a');//输出a所在位置
	ListInSert(CL,4,'w');//在第4位插入w
	ListPrint_CL(CL);//输出链表
	ListDelete_CL(CL,5);//删除第5个元素
	ListPrint_CL(CL);//输出链表
	free(CL);//释放链表
    return 0;
}

Status ListCreate_CL(LinkList &CL)
{
	int n,i;
	LNode *p,*tail;
	CL = (LinkList) malloc (sizeof (LNode));
	if(CL == NULL) exit(OVERFLOW);//边缘情况
	CL->next = CL;//初始化		
	if(CL->next == CL) printf("1\n");
	else printf("0\n");//判断逻辑
	scanf("%d",&n);
	p = CL;
	for(i = 0;i < n;++i)//输入元素
	{
		tail = (LinkList) malloc (sizeof (LNode));
		if(tail == NULL) exit(OVERFLOW);//边缘条件
		//if(i == 0) scanf("%c",&tail->data );//更改之后的结果
		//else 
		scanf(" %c",&tail->data );
		p ->next = tail;
		p = tail;
	}

	p ->next = CL;
	
	return OK;
}

void ListPrint_CL(LinkList &CL)
{
	LNode *p=CL->next;  //p指向第一个元素结点
    if(p==CL){
      printf("Empty List!\n");
      return;
    }
    while(p!=CL)  //输出
    {   
        if(p->next!=CL)
            printf("%c ",p->data);   
        else
            printf("%c\n",p->data); 
        p=p->next; 
    }
}
void ListPrint_CL_n(LinkList &CL,int n)
{
	int i = 0;
	LNode *p=CL;  //p指向第一个元素结点
    for(i = 0;i<n;++i)
	{
		if(p->next  == CL)
		{
			printf("OUTPUTERROR!\n");//判断该元素是否存在
			return;
		}
		else p = p->next;
	}
	printf("%c\n",p->data );
}

void ListPrint_CL_char_PO(LinkList &CL,char n)//输出指定元素的位置
{
	int i = 1;
	LNode *p;
	p = CL->next ;
	while(p != CL)
	{
		if(p->data == n)
		{
			printf("%d\n",i);
			return;
		}
		else
		{
			p = p->next ;
			++i;
		}

	}
	printf("Can't seach this char!\n");
}

void ListInSert(LinkList &CL,int n,char s)
{
	int i;
	LNode *p;
	LinkList CL1;
	CL1 = (LinkList) malloc (sizeof (LNode));
	CL1->data = s;
	p = CL->next ;
	if(p == CL) printf("Empty List!\n");
	for(i = 0;i<n-2;++i)
	{
		p = p->next ;
		if(p == CL) printf("InSert ERROR!\n");//判断插入位置是否正确
	}
	if(p->next ==CL) printf("InSert ERROR!\n");
	else
	{
		CL1->next = p->next ;
		p->next = CL1;
	}
}

void ListDelete_CL(LinkList &CL,int n)
{
	LNode *p;
	int i;
	p = CL->next ;
	if(p == CL)
	{
		printf("Empty List,Can't delet!\n");
		return;
	}
	for(i = 0;i<n-2;++i)
	{
		p = p->next ;
		if(p == CL)
		{
			printf("ListLength ERROR,Can't delet!\n");//判断删除的元素是否存在
			return;
		}
	}
	if(p->next == CL)
	{
		printf("ListLength ERROR,Can't delet!\n");
		return;
	}
	p->next = p->next ->next ;
}

int ListLength(LinkList &CL)
{
	int i = 0;
	LNode *p;
	p = CL->next ;
	if(p == CL)//边界条件，表长为零
		return 0;
	while(p != CL)
	{
		p = p->next ;
		++i;
	}
	return i;
}