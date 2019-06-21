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

typedef char  ElemType; 



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

void	DestroyList_CL(LinkList &CL);

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

	DestroyList_CL(CL);//�ͷ�����

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
	getchar();  //��ȡn����Ļس���

	p = CL;

	for(i = 0;i < n;++i)//����Ԫ��

	{

		tail = (LinkList) malloc (sizeof (LNode));

		if(tail == NULL) exit(OVERFLOW);//��Ե����

		if(i==0)scanf("%c",&tail->data );
		else scanf(" %c",&tail->data );
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

	int count = 0;

	if(CL==CL->next)printf("OUTPUTERROR!\n");//�жϸ�Ԫ���Ƿ����

	LNode *p=CL->next;  //pָ����Ԫ�ؽ��
	count=1;
	while(p!=CL && count < n){
        p=p->next; count++;
	}
	if(p==CL)printf("OUTPUTERROR!\n");//�жϸ�Ԫ���Ƿ����
	else
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



void ListInSert(LinkList &CL,int n,char c)

{

	int count;

	LNode *p,*postp;

	LNode *s;

	s = (LNode *) malloc (sizeof (LNode));
	s->data = c;

	if(CL->next==CL && n!=1 ){printf("InSert ERROR!\n");return;}
	else if(CL->next==CL && n==1) {
        CL->next=s; s->next=CL;
        return ;
	}
	p = CL->next;  //��p����λ��i-1��Ԫ�ؽڵ�
	count = 1;
	while(p!=CL && count<n-1){
        p=p->next; count++;
	}
	if(p==CL ){printf("InSert ERROR!\n");return;}
	else{
        postp=p->next;
        p->next=s; s->next=postp;
	}
}



void ListDelete_CL(LinkList &CL,int n)

{

	LNode *p,*postp;

	int count;

	if(CL->next == CL)

	{

		printf("Empty List,Can't delet!\n");

		return;

	}
	p = CL->next;  //��p����λ��i-1��Ԫ�ؽڵ�
	count = 1;
	while(p!=CL && count<n-1){
        p=p->next; count++;
	}
	if(p==CL || p->next==CL){printf("ListLength ERROR,Can't delet!\n");return;}
	else{
        postp=p->next;
        p->next=postp->next;
        free(postp);
	}

}



int ListLength(LinkList &CL)

{

	int i = 0;

	LNode *p;



	if(CL->next == CL)//�߽���������Ϊ��

		return 0;
    p = CL; i=0;
	while(p->next != CL )

	{

		p = p->next ;

		++i;

	}

	return i;

}

void DestroyList_CL(LinkList &CL)//�ͷ�����
{
    LNode *p=CL,*postp=CL->next;
    while(postp!=CL)
    {
        p->next=postp->next;
        free(postp);
        postp=p->next;
    }
    free(CL);
    CL=NULL;
}
