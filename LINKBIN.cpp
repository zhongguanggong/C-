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

Status ListCreate_L(LinkList &L)
{
    LNode *rearPtr,*curPtr;   //一个尾指针，一个指向新节点的指针
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //先建立一个带头结点的单链表
    rearPtr=L;  //初始时头结点为尾节点,rearPtr指向尾巴节点
    while(rearPtr->data != -1){  //每次循环都开辟一个新节点，并把新节点拼到尾节点后
        curPtr=(LNode*)malloc(sizeof(LNode));//生成新结点
        if(!curPtr)exit(OVERFLOW);
		rearPtr->next=curPtr;
        rearPtr=curPtr;
        scanf("%d",&rearPtr->data);//输入元素值
        
    }
    rearPtr->next=NULL;  //最后一个节点的next赋空
    return OK;
}
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
LinkList JIA(LinkList S1,LinkList S2);
int main()
{
    LinkList S1,S2,S3;
    if(!ListCreate_L(S1) ) {
          printf("表创建失败！！！\n");
          return -1;
    }
	if(!ListCreate_L(S2) ) {
          printf("表创建失败！！！\n");
          return -1;
    }
    S3 = JIA(S1,S2);
	ListPrint_L(S3);
    return 0;
}


LinkList JIA(LinkList S1,LinkList S2)
{
	LNode *p1,*p2,*p3,*p;
	LinkList S3;
	p1 = S1->next ;
	
	
	S3 = (LinkList) malloc (sizeof(LNode));
	p3 = S3;
	
	while((p1->data != -1))
	{
		p2 = S2->next ;
		for(;p2->data != -1;p2=p2->next )
		{
			if(p2->data == (p1->data))
			{
				p = (LinkList) malloc (sizeof(LNode));
				p3->next = p;
				p3 = p;
				p3->data = p1->data;
				break;
			}
		}
		p1 = p1->next;
		
	}
		
		p3->next = NULL;
		return S3;
}
