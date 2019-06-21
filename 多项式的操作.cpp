#include <stdio.h>  
#include <stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0 
#define OVERFLOW   -2 
    
typedef struct PolyNode // 多项式结点设计  
{  
    int coef; // 系数  
    int expon; // 指数  
    PolyNode *next; // 指向下一项的指针  
}Term;

typedef Term * Polynomial;
typedef Term ElemType;
  
  
// 比较两个数  
int compare(int a, int b)  
{  
    return (a == b) ? 0 : (a > b ? 1: -1);  
}

Polynomial Polynomial_Creat()
{
	int n,i = 0;
	Polynomial PL;
	ElemType *p,*tail;
	PL = (Polynomial) malloc (sizeof(ElemType));
	if(!PL)exit(OVERFLOW);
	PL->next = NULL;
	p = PL;
	scanf("%d",&n);
	while(i<n)
	{
		tail = (Polynomial) malloc (sizeof(ElemType));
		if(!tail)exit(OVERFLOW);
		scanf("%d%d",&tail->coef,&tail->expon);
		p->next = tail;
		p = tail;
		++i;
	}
	p->next = NULL;
	return PL;
}

Polynomial Polynomial_Add(Polynomial PL1,Polynomial PL2)
{
	Polynomial PL;
	ElemType *p1,*p2,*p3,*tail;
	PL = (Polynomial) malloc (sizeof(ElemType));
	if(!PL)exit(OVERFLOW);
	PL->next = NULL;
	p1 = PL1->next ;
	p2 = PL2->next;
	p3 = PL;
	while(p1&&p2)
	{
		if(p1->expon>p2->expon)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next ;
		}
		else if(p1->expon<p2->expon)
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
		else
		{
			tail = (Polynomial) malloc (sizeof(ElemType));
			if(!PL)exit(OVERFLOW);
			tail->coef = p1->coef+p2->coef;
			if(tail->coef == 0)
			{
				tail->expon = 0;
				p3->next = tail;
				p3 = tail;
			}
			else
			{
				tail->expon = p1->expon ;
				p3->next = tail;
				p3 = tail;
			}
			p1 = p1->next;
			p2 = p2->next ;
		}

	}
	while(p1)
	{
		p3->next = p1;
		p3 = p1;
		p1 = p1->next ;
	}
	while(p2)
	{
		p3->next = p2;
		p3 = p2;
		p2 = p2->next ;
	}
	p3->next = NULL;
	return PL;
}

Polynomial Polynomial_Multi(Polynomial PL1,Polynomial PL2)
{
	Polynomial PL;
	ElemType *p1,*p2,*p3,*tail;
	PL = (Polynomial) malloc (sizeof(ElemType));
	if(!PL)exit(OVERFLOW);
	PL->next = NULL;
	p1 = PL1->next ;
	p2 = PL2->next;
	p3 = PL;
	while(p2)
	{
		while(p1)
		{
			tail = (Polynomial) malloc (sizeof(ElemType));
			if(!tail)exit(OVERFLOW);
			tail->coef = p1->coef * p2->coef ;
			tail->expon = p1->expon + p2->expon ;
			p3->next = tail;
			p3 = tail;
			p1 = p1->next ;
		}
		p1 = PL1->next ;
		p2 = p2->next ;
	}
	p3->next = NULL;
	return PL;
}

void Polynomial_Prin(Polynomial PL)
{
	ElemType *p;
	p = PL->next;
	while(p->next != NULL)
	{
		printf("%d %d ",p->coef ,p->expon );
		p = p->next ;
	}
	printf("%d %d\n",p->coef ,p->expon );
}

int main()
{
	Polynomial PL1,PL2,PLA,PLM;
	PL1 = Polynomial_Creat();
	PL2 = Polynomial_Creat();
	if(!PL1||!PL2)
	{
		printf("多项式链表创建失败！\n");
		return -1;
	}
	PLM = Polynomial_Multi(PL1,PL2);
	Polynomial_Prin(PLM);
	PLA = Polynomial_Add(PL1,PL2);
	Polynomial_Prin(PLA);
	return 0;
}