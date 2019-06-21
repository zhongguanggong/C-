#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType; 

typedef struct LNode{
	struct LNode *next;	
	ElemType data;
}*LinkList,Link;

LinkList Link_Creat()
{
	LinkList L;
	Link *p,*tail;
	L = (LinkList) malloc (sizeof(Link));
	if(!L)exit(OVERFLOW);
	L->next = NULL;
	p = L;
	while(p->data!=-1)
	{
		tail = (LinkList) malloc (sizeof(Link));
		if(!tail)exit(OVERFLOW);
		scanf("%d",&tail->data);
		p->next = tail;
		p = tail;
	}
	p->next = NULL;
	return L;
}

int LinkLength(LinkList L)
{
	int i = 0;
	Link *p;
	p = L->next;
	while(p)
	{
		++i;
		p = p->next;
	}
	return i;
}

void LinkPrint_n(int n,LinkList L)
{
	int length,i;
	Link *p;
	p = L;
	length = LinkLength(L);
	for(i = 0;i<length-n;++i)
	{
		p = p->next;
	}
	printf("%d\n",p->data);
}

int main()
{
	int n;
	scanf("%d",&n);
	LinkList L;
	L = Link_Creat();
	if(!L)
	{
		printf("Á´±í´´½¨Ê§°Ü£¡\n");
		return -1;
	}
	LinkPrint_n(n,L);
	return 0;
}

