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
typedef char  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

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
    L->next=NULL; //�Ƚ���һ����ͷ���ĵ�����
	//p = L->next;
	
    rearPtr=L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for (int i=1;i<=n;i++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr=(LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr)exit(OVERFLOW);
        scanf(" %c",&curPtr->data);//����Ԫ��ֵ
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
	printf("0\n");
    curPtr->next=NULL;  //���һ���ڵ��next����
    return OK;
}
void ListPrint_L(LinkList &L){
//���������
    LNode *p=L->next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
          if(p->next!=NULL)
               printf("%c ",p->data);
          else
               printf("%c",p->data);
          p=p->next;
    }
}


int main()
{
    int i = 0;
	LinkList L,L1;
	LNode *p,*s;
    int n;
    scanf("%d",&n);
    if(ListCreate_L(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
    ListPrint_L(L);
	printf("\n%d\n",n);
	if(L == NULL) printf("yes\n");
	else printf("no\n");
	p=L;
	while(i<3)
	{
		p = p->next ;
		++i;
	}
	printf("%c\n",p->data);
	i = 0;
	for(p = L;p != NULL;p=p->next )
	{
		if(p->data == 'a')
			break;
		++i;
	}
	printf("%d\n",i);
	p = L;
	s = L;
	L1 = (LNode*)malloc(sizeof (LNode));
	L1->data = 'x';
	for(i = 0;i<4;++i)
	{
		p = p->next ;
	}
	for(i = 0;i<3;++i)
	{
		s = s->next ;
	}
	L1->next = p;
	s->next = L1;
	ListPrint_L(L);
	s = L;
	for(i = 0;i<2;++i)
	{
		s = s->next ;
	}
	s->next = L1;
	printf("\n");
	ListPrint_L(L);
	free(L);

    return 0;
}


	

