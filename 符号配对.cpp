//应该设置两个栈

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define STACK_INIT_LENGTH 100
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
Status Judge(Stack SL,Stack RSL,SElemType Code[],int &x,char &t);
int main()
{
	Stack SL，RSL;
	char Code[100],t;
	int i = 0,j = 0,k = 0,x;
	while(!j)
	{
		scanf("%c",&Code[i]);
		if(Code[i] == '.')
			k = 1;
		else if(Code[i] != '.'&&(Code[i]!=10)) k = 0;
		else if(Code[i] == 10&&k == 1)
		{
			j = 1;
		}
		else k=0;
		i++;
	}
	Code[i] = NULL;
/*	i =0;
	while(Code[i]!=NULL)
	{
		printf("%c",Code[i]);
		i++;
	}*/
	if(!StackInit(SL))
	{
		printf("初始化失败！\n");
		return -1;
	}

	if(!StackInit(RSL))
	{
		printf("初始化失败！\n");
		return -1;
	}
	if(Judge(SL,Code,x,t))
		printf("YES\n");
	else 
	{
		printf("NO\n");
		if(x == 0)
		{
			if(t == '/')
			{
				printf("?-*/\n");
			}
			else printf("?-%c\n",t);
		}
		else
		{
			if(t == '*')
			{
				printf("/*-?\n");
			}
			else printf("%c-?\n",t);
		}
	}
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
	if(SL.top - SL.base == SL.StackSize) //return ERROR;
	SL.base = (SElemType *) realloc (SL.base,(SL.StackSize+STACK_INCREAT_LENGTH)*sizeof(SElemType));
	if(!SL.base)exit(OVERFLOW);
	SL.StackSize = SL.StackSize+STACK_INCREAT_LENGTH;
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

Status Judge(Stack SL,Stack RSL,SElemType Code[],int &x,char &t)
{
	int i = 0;
	char e,s;
	while(Code[i] != NULL)
	{
		if(Code[i] == '(' || Code[i] == '{' || Code[i] == '[' || (Code[i] == '*'&&i>0&&Code[i-1] == '/'))
		{
			if(Code[i] == '*')
			{
				StackPush(SL,Code[i-1]);
				StackPush(SL,Code[i]);
			}
			else{
				StackPush(SL,Code[i]);
			}
		}
		
		if(Code[i] == ')' || Code[i] == '}' || Code[i] == ']' || (Code[i] == '/'&&i>1&&Code[i-1] == '*'&&Code[i-2]!='/'))
		{
			if(StackEmpty(SL))
			{
				x = 0;
				t = Code[i];
				return FALSE;
			}
			if(Code[i] == '/')
			{
				GetTop(SL,e);//e == '*'
				s = *(SL.top-2);
				if(e == '*' && s == '/')
				{
					StackPop(SL,e);
					StackPop(SL,e);
				}
				else
				{
					StackPush(RSL,Code[i-1]);
					StackPush(RSL,Code[i]);
				}

				
			}
			else{
				GetTop(SL,e);
				if(Code[i] == ')')
				{
					if(e == '(')
					StackPop(SL,e);
				}
				else if(Code[i] == '}')
				{
					if(e == '{')
					StackPop(SL,e);
				}
				else if(Code[i] == ']')
				{
					if(e == '[')
					StackPop(SL,e);
				}
				
				else{
					StackPush(RSL,Code[i]);
				}

			}
		}
		++i;
	}
	if(StackEmpty(SL)) return TRUE;
	else
	{
		x = 1;
	//	while(!StackEmpty(SL))
			StackPop(SL,t);
			//if(!StackEmpty(SL))
				//printf("1");
		return FALSE;
	}
}








