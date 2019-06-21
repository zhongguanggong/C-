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
}LNode,*LinkList; //ѭ�����������Ͷ����뵥��������ͬ��������β�ڵ�nextȡֵ

Status ListCreate_CL(LinkList &CL); //������ 

void ListDelete_CL(LinkList &CL,int n);//����Ԫ��ɾ��

void ListPrint_CL_n(LinkList &CL,int n);//�������ָ��λ��Ԫ��

void ListPrint_CL_char_PO(LinkList &CL,char n);//�������ָ��Ԫ������λ��

void ListInSert(LinkList &CL,int n,char s);//��ָ��λ�ò���Ԫ��

int ListLength(LinkList &CL);//�����

void ListPrint_CL(LinkList &CL);//�������

int main() 
{  
    LinkList CL;
	LNode *p;
	int i;
    if(ListCreate_CL(CL)!= OK) //������
    {
       printf("ѭ��������ʧ�ܣ�����\n");
       return -1;
    }   
    ListPrint_CL(CL);//�������
	i = ListLength(CL);
	printf("%d\n",i);//�����
	p = CL->next ;
	if(p == CL)
		printf("yes\n");
	else printf("no\n");//�ж������Ƿ�Ϊ��
	ListPrint_CL_n(CL,3);//���������Ԫ��
	ListPrint_CL_char_PO(CL,'a');//���a����λ��
	ListInSert(CL,4,'w');//�ڵ�4λ����w
	ListPrint_CL(CL);//�������
	ListDelete_CL(CL,5);//ɾ����5��Ԫ��
	ListPrint_CL(CL);//�������
	free(CL);//�ͷ�����
    return 0;
}

Status ListCreate_CL(LinkList &CL)
{
	int n,i;
	LNode *p,*tail;
	CL = (LinkList) malloc (sizeof (LNode));
	if(CL == NULL) exit(OVERFLOW);//��Ե���
	CL->next = CL;//��ʼ��		
	if(CL->next == CL) printf("1\n");
	else printf("0\n");//�ж��߼�
	scanf("%d",&n);
	p = CL;
	for(i = 0;i < n;++i)//����Ԫ��
	{
		tail = (LinkList) malloc (sizeof (LNode));
		if(tail == NULL) exit(OVERFLOW);//��Ե����
		//if(i == 0) scanf("%c",&tail->data );//����֮��Ľ��
		//else 
		scanf(" %c",&tail->data );
		p ->next = tail;
		p = tail;
	}

	p ->next = CL;
	
	return OK;
}

void ListPrint_CL(LinkList &CL)
{
	LNode *p=CL->next;  //pָ���һ��Ԫ�ؽ��
    if(p==CL){
      printf("Empty List!\n");
      return;
    }
    while(p!=CL)  //���
    {   
        if(p->next!=CL)
            printf("%c ",p->data);   
        else
            printf("%c\n",p->data); 
        p=p->next; 
    }
}
void ListPrint_CL_n(LinkList &CL,int n)
{
	int i = 0;
	LNode *p=CL;  //pָ���һ��Ԫ�ؽ��
    for(i = 0;i<n;++i)
	{
		if(p->next  == CL)
		{
			printf("OUTPUTERROR!\n");//�жϸ�Ԫ���Ƿ����
			return;
		}
		else p = p->next;
	}
	printf("%c\n",p->data );
}

void ListPrint_CL_char_PO(LinkList &CL,char n)//���ָ��Ԫ�ص�λ��
{
	int i = 1;
	LNode *p;
	p = CL->next ;
	while(p != CL)
	{
		if(p->data == n)
		{
			printf("%d\n",i);
			return;
		}
		else
		{
			p = p->next ;
			++i;
		}

	}
	printf("Can't seach this char!\n");
}

void ListInSert(LinkList &CL,int n,char s)
{
	int i;
	LNode *p;
	LinkList CL1;
	CL1 = (LinkList) malloc (sizeof (LNode));
	CL1->data = s;
	p = CL->next ;
	if(p == CL) printf("Empty List!\n");
	for(i = 0;i<n-2;++i)
	{
		p = p->next ;
		if(p == CL) printf("InSert ERROR!\n");//�жϲ���λ���Ƿ���ȷ
	}
	if(p->next ==CL) printf("InSert ERROR!\n");
	else
	{
		CL1->next = p->next ;
		p->next = CL1;
	}
}

void ListDelete_CL(LinkList &CL,int n)
{
	LNode *p;
	int i;
	p = CL->next ;
	if(p == CL)
	{
		printf("Empty List,Can't delet!\n");
		return;
	}
	for(i = 0;i<n-2;++i)
	{
		p = p->next ;
		if(p == CL)
		{
			printf("ListLength ERROR,Can't delet!\n");//�ж�ɾ����Ԫ���Ƿ����
			return;
		}
	}
	if(p->next == CL)
	{
		printf("ListLength ERROR,Can't delet!\n");
		return;
	}
	p->next = p->next ->next ;
}

int ListLength(LinkList &CL)
{
	int i = 0;
	LNode *p;
	p = CL->next ;
	if(p == CL)//�߽���������Ϊ��
		return 0;
	while(p != CL)
	{
		p = p->next ;
		++i;
	}
	return i;
}