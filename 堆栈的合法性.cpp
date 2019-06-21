#include <cstdio>
#include <cstring>
#include <cstdlib>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define OVERFLOW   -2

#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10

typedef int  status;
typedef char SElemType;//栈元素类型
typedef struct{
    SElemType *base; //栈底指针
    SElemType *top;  //栈顶指针
    int stacksize; //栈容量
}SqStack;

status StackInit(SqStack &S);
status StackEmpty(SqStack S);
status StackPut(SqStack &S,char e);
status StackPop(SqStack &S);

int main()
{
	int M,N,i = 0,j,k,l = 1;
	SqStack S;
	StackInit(S);
	scanf("%d %d",&M,&N);
	while(i<N)
	{
		char s[100];
		getchar();
		gets(s);
		j = strlen(s);
		printf("%d",j);
		for(k = 0;k<j;k++)
		{
			if(s[k] == 's')
			{
				StackPut(S,s[k]);
			}
			
			else
			{
				if(S.base == S.top)
				{
					l = 0;
					printf("NO");
					break;
				}
				else
				{
					StackPop(S);
				}
			}
		}
		if(l)
		{
			if(StackEmpty(S) == TRUE)
			{
				printf("YES");
			}
			else 
				printf("NO");
		}
		l = 1;
		++i;
	}
	return 0; 
}

status StackInit(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);
	S.top = S.base ;
	S.stacksize = STACK_INIT_SIZE;	
	return OK;
}

status StackEmpty(SqStack S)
{
	if(S.base == S.top)
		return TRUE;
	else return FALSE;
}

status StackPut(SqStack &S,char e)
{
	if(S.top - S.base == S.stacksize)
	{
		printf("堆栈空间已满！\n");
		return ERROR;
	}
	*S.top ++ = e;
	return OK;
}

status StackPop(SqStack &S)
{
	if(S.top == S.base) return ERROR;
	S.top = S.top-1;
	return OK;
}

