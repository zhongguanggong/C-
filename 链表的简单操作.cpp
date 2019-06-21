#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define OVERFLOW -2

typedef int status;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

status CreatLinkList(LinkList &Link)
{
	LNode *rar,*p;
	int data,i,j = 0;
	scanf("%d",&i);
	Link = (LinkList) malloc (sizeof(LNode));
	if(!Link) exit(OVERFLOW);
	Link->next = NULL;
	p = Link;
	while(j<i)
	{
		rar = (LinkList) malloc (sizeof(LNode));
		if(!rar) exit(OVERFLOW);
		rar->next = NULL;
		scanf("%d",&data);
		rar->data = data;
		p->next = rar;
		p = rar;
		j++;
		printf("’‘∑¢∞∫…µ±∆£°");
	}
	
	return OK;
}

status PrintLink(LinkList Link)
{
	LNode *p;
	if(!Link) return ERROR;
	p = Link->next;
	
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
		printf("’‘∑¢∞∫…µ±∆£°");	
	}
	return OK;
}

int main()
{
	LinkList Link;
	if(!CreatLinkList(Link)) 
	{
		printf("¥¥Ω® ß∞‹£°");
		return -1;
	}
	
	PrintLink(Link);
	return 0;
}
