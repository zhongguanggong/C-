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
}LNode,*LinkList; //循环单链表类型定义与单链表定义相同，区别在尾节点next取值

Status ListCreate_CL(LinkList &CL);  

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max);

void ListPrint_CL(LinkList &CL) 
{   //输出单链表,空表时输出Empty List。 
    LNode *p=CL->next;  //p指向第一个元素结点
    if(p==CL){
      printf("Empty List");
      return;
    }
    while(p!=CL)  
    {   
        if(p->next!=CL)
            printf("%d ",p->data);   
        else
            printf("%d",p->data);      
        p=p->next; 
    } 
}    
int main() 
{  
    LinkList CL;
    ElemType min,max;
    if(ListCreate_CL(CL)!= OK) 
    {
       printf("循环链表创建失败！！！\n");
       return -1;
    }
    scanf("%d%d",&min,&max);    
    ListDelete_CL(CL,min,max);   
    ListPrint_CL(CL);  				
    return 0;
}

Status ListCreate_CL(LinkList &CL)
{
	int n,i;
	LNode *p,*tail;
	scanf("%d",&n);
	/*if (!n)
		return ERROR;*/
	//else
	//{
		CL = (LinkList) malloc (sizeof (LNode));
		if(CL == NULL) exit(OVERFLOW);
		p = CL;
		for(i = 0;i < n;++i)
		{
			tail = (LinkList) malloc (sizeof (LNode));
			if(tail == NULL) exit(OVERFLOW);
			scanf("%d",&tail->data );
			p ->next = tail;
			p = tail;
		}
	//}
	p ->next = CL;
	return OK;
}

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max)
{
	int i=0,j;
	LNode *p,*tail;
	p = CL->next ;
	while(p != CL)
	{
		if((p->data >min) && (p->data <max))
		{
			tail = CL->next ;
			for(j = 0;j<i-1;++j)
			{
				tail = tail->next ;
			}
			tail->next = p->next ;
			free(p);
			p = tail->next;
		}
		else
		{
			p = p->next;
			++i;
		}
	}
}