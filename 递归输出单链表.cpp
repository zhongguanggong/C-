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

Status ListCreate_L_Rec(LinkList &L,int n)
{
//�ݹ�߽磺�����ձ�ʱֻ�轫L���ռ��ɣ�
//�ݹ��ϵ�������ǿձ�ʱ���������������֣���Ԫ����ɵ��ӱ�La�� �ڶ���Ԫ�ؼ����Ԫ�ع��ɵ��ӱ�Lb��
//�ӱ�La���״���(ֻ�迪��һ���ڵ�)
//�ӱ�Lb���ڹ�ģС���Եݹ鴴����ɣ�������ѧ���ɷ��ļ��裬ֻҪС�Ķ����Խ�������ɣ�
//��������ӱ�ƴ�Ӽ��ɡ�
  LNode *La, *Lb;
  if(n==0) L=NULL;
  else{
    La=(LNode *)malloc(sizeof(LNode));  //�����ӱ�La
    if(!La) exit(OVERFLOW);
    scanf("%d",&La->data);
    ListCreate_L_Rec(Lb,n-1 ); //�ݹ鴴���ӱ�Lb
    La->next = Lb;  //�����ӱ�ƴ��
    L=La;  //��һ���ӱ�ĵ�ַ����L����˼��Ϊʲ����������ʹ���������е�Lȡ��ֵ��
  }
  return OK;
}
void ListPrint_L_Rec(LinkList L);

int main()
{
    LinkList L;
    int n;
    scanf("%d",&n);
    if(ListCreate_L_Rec(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
    ListPrint_L_Rec (L);
    return 0;
}

void ListPrint_L_Rec(LinkList L)
{
	printf(" %d",L->data);
	if( L->next )
	{
		ListPrint_L_Rec(L->next);
	}

}