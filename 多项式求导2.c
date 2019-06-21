#include <stdio.h>
#include <stdlib.h>
//#define OK 1
//#define ERROR 0
#define OVERFLOW -2

typedef struct{
    int coef;
    int expon;
}term;

typedef term ElemType;

typedef struct node{
    ElemType Poly_elem;
    struct node * next;
} PolyNode, *LinkList;

typedef LinkList Polynomial;

Polynomial Poly_Creat();
Polynomial Deri_poly(Polynomial poly);
void Poly_Print(Polynomial poly);


int main()
{
	Polynomial poly;
	poly = Poly_Creat();
	if(!poly)
	{
		printf("多项式创建失败！\n");
		return -1;
	}
	
	poly = Deri_poly(poly);
	
	Poly_Print(poly);

	return 0;
}

Polynomial Poly_Creat()
{

	Polynomial poly;
	PolyNode *p,*tail;
	poly = (Polynomial) malloc (sizeof(PolyNode));
	if(!poly)exit(OVERFLOW);
	poly->next = NULL;
	p = poly;
	tail = (Polynomial) malloc (sizeof(PolyNode));
	if(!tail)exit(OVERFLOW);
	while(scanf("%d",&(tail->Poly_elem.coef))!=EOF)
	{
		
		scanf("%d",&(tail->Poly_elem.expon));
		p->next = tail;
		p = tail;
		tail = (Polynomial) malloc (sizeof(PolyNode));
		if(!tail)exit(OVERFLOW);
	
	}
	p->next = NULL;
	free(tail);
	tail = NULL;
	return poly;
}

Polynomial Deri_poly(Polynomial poly)
{
	PolyNode *p,*prep;
	p = poly->next;
	prep = poly;
	
	while(!p)
	{
		if(p->Poly_elem.expon != 0)
		{
			p->Poly_elem.coef = (p->Poly_elem.coef) * (p->Poly_elem.expon);
			--(p->Poly_elem.expon);
			p = p->next;
			prep = prep->next;
		}
		else
		{
			prep->next = p->next;
			free(p);
			p = NULL;
			p = prep->next;
		}
	}

	return poly;
}

void Poly_Print(Polynomial poly)
{
	PolyNode *p;
	p = poly->next;
		
	if(!p)
	{
		printf("%d %d",p->Poly_elem.coef,p->Poly_elem.expon);
			printf("多项式创建失败！\n");
		p = p->next;
	}
	while(!p)
	{
		printf(" %d %d",p->Poly_elem.coef,p->Poly_elem.expon);
		p = p->next;
	}
}