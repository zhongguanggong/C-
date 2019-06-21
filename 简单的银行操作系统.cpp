#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status; 

typedef struct QNode{
	struct QNode *next;
	ElemType data;
}*QueuePrt,QNode;

typedef struct{
	QueuePrt front;
	QueuePrt rear;
}LinkQueue;

Status init(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,int e);
Status OutQueue(LinkQueue &Q,int &e);
//Status LookNext(LinkQueue Q,int &e);
Status QEmpty(LinkQueue Q);
Status work(LinkQueue &A,LinkQueue &B);

int main()
{
	LinkQueue A,B;
	int customer,i,j;
	scanf("%d",&customer);
	if(!init(A)){
	printf("队列初始化失败！\n");
	return -1;
	}
	if(!init(B)){
	printf("队列初始化失败！\n");
	return -1;
	}
	for(i = 0;i<customer;i++){
		scanf("%d",&j);
		if((j%2 == 0))
			EnQueue(B,j);
		else
			EnQueue(A,j);
	}
	work(A,B);
	return 0;
}

Status init(LinkQueue &Q){
	Q.front = Q.rear =(QueuePrt) malloc (sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.rear ->next =NULL;
	return OK;
}

Status EnQueue(LinkQueue &Q,int e){
	QNode *p;
	p = (QNode *) malloc (sizeof(QNode)); 
	if(!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear ->next = p;
	Q.rear = p;
	return OK;
}

Status OutQueue(LinkQueue &Q,int &e){
	QNode *p;
	if(Q.front == Q.rear) return ERROR;
	p = Q.front ->next ;
	e = p->data ;
	Q.front = Q.front ->next ;
	if(Q.rear == p)
		Q.rear = Q.front ;
//	free(p);
	return OK;
}


Status QEmpty(LinkQueue Q)
{
	if(Q.rear == Q.front) return OK;
	else return FALSE;
}

Status work(LinkQueue &A,LinkQueue &B){
	int e,i = 1;
	if(QEmpty(A) && QEmpty(B)) return ERROR;
	while(!QEmpty(A) && !QEmpty(B))
	{
		if(i%3 == 0)
		{
			OutQueue(B,e);	
			printf("%d ",e);
			++i;
		}
		else
		{
			OutQueue(A,e);
			printf("%d ",e);
			++i;
		}
	}
	while(!QEmpty(A))
	{
		if(A.front ->next != A.rear)
		{
			OutQueue(A,e);
			printf("%d ",e);
		}
		else
		{
			OutQueue(A,e);
			printf("%d",e);	
		}
	}
	while(!QEmpty(B))
	{
		if(B.front ->next != B.rear)
		{
			OutQueue(B,e);
			printf("%d ",e);
		}
		else
		{
			OutQueue(B,e);
			printf("%d",e);	
		}
	}
	return OK;
}
