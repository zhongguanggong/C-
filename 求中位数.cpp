
//作为链表复习之一
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OVERFLOW -2
#define OK 1

typedef int elemtype;
typedef int status;

typedef struct LNODE{
	struct LNODE *next;
	elemtype data;
} *sq,SQNODE;

status CreatLink(sq &S1,sq &S2,int n)
{
	int i = 0;
//	sq S1,S2;
	SQNODE *p,*q,*cur;
	S1 = (sq) malloc (sizeof(SQNODE));
	if(!S1)exit(OVERFLOW);
	S2 = (sq) malloc (sizeof(SQNODE));
	if(!S2)exit(OVERFLOW);
	S1->next = NULL;
	S2->next = NULL;
	
	p = S1;
	q = S2;
	while(i<n)
	{
		cur = (sq) malloc (sizeof(SQNODE));
		if(!cur)exit(OVERFLOW);
	//	p = (sq) malloc (sizeof(SQNODE));
		scanf("%d",&cur->data);
		p->next = cur;
		p = cur;
		i++;
	}
	p->next = NULL;
	i = 0;
	while(i<n)
	{
		cur = (sq) malloc (sizeof(SQNODE));
		if(!cur)exit(OVERFLOW);
	//	p = (sq) malloc (sizeof(SQNODE));
		scanf("%d",&cur->data);
		q->next = cur;
		q = cur;
		i++;
	}
	q->next = NULL;
	
	return OK;
}

status Sort(sq S1,sq S2,sq &S3)
{
	SQNODE *p,*q,*s,*cur;
	S3 = (sq) malloc (sizeof(SQNODE));
	if(!S3) exit(OVERFLOW);
	s = S3;
	p = S1->next;
	q = S2->next;
	while(p&&q)
	{
		if(p->data <= q->data)
		{
			cur = (sq)malloc(sizeof(SQNODE));
			if(!cur) exit(OVERFLOW);
			cur->data = p->data;
			s->next = cur;
			s = cur;
			p = p->next;
			//	printf("asda");
		}
		else if(p->data > q->data)
		{
			cur = (sq)malloc(sizeof(SQNODE));
			if(!cur) exit(OVERFLOW);
			cur->data = q->data;
			s->next = cur;
			s = cur;
			q = q->next;
		
		}
	}
	
	while(p)
	{
		cur = (sq)malloc(sizeof(SQNODE));
		if(!cur) exit(OVERFLOW);
		cur->data = p->data;
		s->next = cur;
		s = cur;
		p = p->next;
	}
	while(q)
	{
		cur = (sq)malloc(sizeof(SQNODE));
		if(!cur) exit(OVERFLOW);
		cur->data = q->data;
		s->next = cur;
		s = cur;
		q = q->next;
	}
	s -> next = NULL;
	return OK;
}

int main()
{
	int n,i = 0;
	sq S1,S2,S3;
	SQNODE *p;
	scanf("%d",&n);
	CreatLink(S1,S2,n);
	Sort(S1,S2,S3);
	p = S3;
	while(i<(2*n+1)/2)
	{
		p = p->next;
		i++;
	}
	printf("%d",p->data);
	return 0;
}