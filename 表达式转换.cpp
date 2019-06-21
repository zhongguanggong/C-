#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define STACK_INIT_LENGTH 20
#define STACK_INCREAT_LENGTH 10

typedef int Status;
typedef char SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int StackSize;
}Stack;

Status StackInit(Stack &SL);
Status StackEmpty(Stack SL);
Status StackPush(Stack &SL,char e);
Status StackPop(Stack &SL,char &e);
Status GetTop(Stack SL,char &e);
void CONVERSION(Stack SL,char a[]);

int main()
{
	Stack SL;
	char a[20];
	if(!StackInit(SL))
	{
		printf("³õÊ¼»¯Ê§°Ü£¡\n");
		return -1;
	}
	gets(a);
	CONVERSION(SL,a);
	return 0;
}



Status StackInit(Stack &SL)
{
	SL.base = (SElemType *) malloc (STACK_INIT_LENGTH*sizeof(SElemType));
	if(!SL.base)exit(OVERFLOW);
	SL.top = SL.base ;
	SL.StackSize = STACK_INIT_LENGTH;
	return OK;
}

Status StackEmpty(Stack SL)
{
	if(SL.top == SL.base )
		return TRUE;
	else return FALSE;
}

Status StackPush(Stack &SL,char e)
{
	if(SL.top - SL.base == SL.StackSize) return ERROR;
	//SL.base = (SElemType *) realloc (SL.base,(SL.StackSize+STACK_INCREAT_LENGTH)*sizeof(SElemType));
//	if(!SL.base)exit(OVERFLOW);
	//SL.StackSize = SL.StackSize+STACK_INCREAT_LENGTH;
	*SL.top++ = e;
	return OK;
}

Status StackPop(Stack &SL,char &e)
{
	if(SL.top == SL.base) return ERROR;
	e = *(--SL.top);
	return OK;
}

Status GetTop(Stack SL,char &e)
{
	if(SL.top == SL.base) return ERROR;
	e = *(SL.top-1);
	return OK;
}

void CONVERSION(Stack SL,char a[])
{
	int i = 0,k;
	char e;
	while(a[i]!='\0')
	{
		if(a[i]>=48&&a[i]<=57)
			printf("%c ",a[i]);
		else
		{
			if(StackEmpty(SL))
				StackPush(SL,a[i]);

			else
			{
			if(a[i] == '*' ||a[i] == '/' ||a[i] == 40)
				StackPush(SL,a[i]);
			if(a[i] == '+' || a[i] == '-')
			{
				k = GetTop(SL,e);
					while(e != 40 && k==1)//40->'('  41->')'
					{
						StackPop(SL,e);
						printf("%c ",e);
						k = GetTop(SL,e);
					}
					StackPush(SL,a[i]);
				
			}
			if(a[i] == 41)
			{
				//StackPop(SL,e);
				//StackPop(SL,e);
				GetTop(SL,e);
				while(e != 40 && a[i+1]!='\0')
				{
					StackPop(SL,e);
					printf("%c ",e);
					GetTop(SL,e);
				}

				while(e != 40 && a[i+1]=='\0')
				{
					if(*(SL.top - 2) == 40&&(SL.top - 2 == SL.base))
					{
						StackPop(SL,e);	
						printf("%c\n",e);
						GetTop(SL,e);
					}
					else
					{
						StackPop(SL,e);
						printf("%c ",e);
						GetTop(SL,e);
					}
				}

				StackPop(SL,e);
			}
			}

		}
		++i;
	}
	while(!StackEmpty(SL))
	{
		StackPop(SL,e);
		if(!StackEmpty(SL))
		{
			printf("%c ",e);
		}
		else 
		{
			printf("%c\n",e);
		}
	}
}
