#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

#define Stack_INIT_SIZE  100
#define STACKINCREMENT   10


typedef int status;
typedef int SElemType;



typedef struct {
	data *top;
	data *base;
	SElemType stacksize;
}SqStack;

status StackEmpty(SqStack S);
status StackInitial(SqStack &S);
status Push(SqStack &S,SElemType e,SElemType t);
status pop(SqStack &S,SElemType &e,SElemType &t);
void Deri(SqStack &S);

int main()
{
	SqStack S;
	data *p;
	SElemType i,j,e,t;
	if(!StackInitial(S))
	{
		printf("³õÊ¼»¯Ê§°Ü£¡\n");
		return -1;
	}
	
	//Push(S,i,j);
	
	while(scanf("%d%d",&i,&j)!=EOF)
	{
		Push(S,i,j);
		Deri(S);
	//	scanf("%d%d",&i,&j);
		//Push(S,i,j);
		//Deri(S);
	}
	++S.top ;
	
	while(!StackEmpty(S))
	{
		p = S.top -1;
		pop(S,e,t);
		if(p != S.base)
		{
			printf("%d %d ",e,t);
		}
		else
			printf("%d %d",e,t);
	}
	return 0;
}







status StackEmpty(SqStack S)
{
	if(S.base == S.top ) return TRUE;
	else return FALSE;
}

status StackInitial(SqStack &S)
{
	S.base = (data *) malloc (Stack_INIT_SIZE * sizeof(data));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;	
	S.stacksize = Stack_INIT_SIZE;
	return OK;
}

status Push(SqStack &S,SElemType e,SElemType t)
{
	if(S.top - S.base == S.stacksize)
	{
		S.base = (data *) realloc (S.base,(STACKINCREMENT+S.stacksize) * sizeof(data));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
	((S.top++)->coef) = e;
	((S.top++)->expon) = t;
	return OK;
}

status pop(SqStack &S,SElemType &e,SElemType &t)
{
	if(S.top == S.base ) return ERROR;
	e = (--S.top->coef);
	t = (--S.top->expon);
	return OK;
}

void Deri(SqStack &S)
{
	data *p;
	if(S.top->expon != 0)
	{
		S.top->coef = S.top->coef * S.top->expon;
		S.top->expon --  ;
	}
	else
	{
		p = S.top;
		S.top--;
		free(p);
		//p = NUll;
	}
}