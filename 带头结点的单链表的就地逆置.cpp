#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;   //һ��βָ�룬һ��ָ���½ڵ��ָ��
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //�Ƚ���һ����ͷ���ĵ�����
    rearPtr=L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for (int i=1;i<=n;i++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr=(LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);//����Ԫ��ֵ
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    curPtr->next=NULL;  //���һ���ڵ��next����
    return OK;
}
void ListReverse_L(LinkList &L);
void ListPrint_L(LinkList &L){
//���������
    LNode *p=L->next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
          if(p->next!=NULL)
               printf("%d ",p->data);
          else
               printf("%d",p->data);
          p=p->next;
    }
}
int main()
{
    LinkList L;
    int n;
    scanf("%d",&n);
    if(ListCreate_L(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
    ListReverse_L(L);
    ListPrint_L(L);
    return 0;
}

void ListReverse_L(LinkList &L)
{
	int i = 0,j,k,x;
	LNode *p,*s;
	p = L->next;
	for(;NULL != p;p = p->next)
	{
		i++;
	}
	p = L;
	for(j=0;j<(i/2);j++)
	{
		p = p->next;
		s = L;
		for(k = 0;k<i-j;++k)
		{
			s = s->next; 
		}
		x = p->data;
		p->data = s->data;
		s->data = x;
	}
	
}
