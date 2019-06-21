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

Status ListCreate_L(LinkList &L)
{
    LNode *rearPtr,*curPtr;   //һ��βָ�룬һ��ָ���½ڵ��ָ��
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //�Ƚ���һ����ͷ���ĵ�����
    rearPtr=L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    while(rearPtr->data != -1){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr=(LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr)exit(OVERFLOW);
		rearPtr->next=curPtr;
        rearPtr=curPtr;
        scanf("%d",&rearPtr->data);//����Ԫ��ֵ
        
    }
    rearPtr->next=NULL;  //���һ���ڵ��next����
    return OK;
}
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
LinkList JIA(LinkList S1,LinkList S2);
int main()
{
    LinkList S1,S2,S3;
    if(!ListCreate_L(S1) ) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
	if(!ListCreate_L(S2) ) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
    S3 = JIA(S1,S2);
	ListPrint_L(S3);
    return 0;
}


LinkList JIA(LinkList S1,LinkList S2)
{
	LNode *p1,*p2,*p3,*p;
	LinkList S3;
	p1 = S1->next ;
	
	
	S3 = (LinkList) malloc (sizeof(LNode));
	p3 = S3;
	
	while((p1->data != -1))
	{
		p2 = S2->next ;
		for(;p2->data != -1;p2=p2->next )
		{
			if(p2->data == (p1->data))
			{
				p = (LinkList) malloc (sizeof(LNode));
				p3->next = p;
				p3 = p;
				p3->data = p1->data;
				break;
			}
		}
		p1 = p1->next;
		
	}
		
		p3->next = NULL;
		return S3;
}
