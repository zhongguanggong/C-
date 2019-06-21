/*�㷨��
1.��ʼ��һ�����У�������վ˳�򰴱����ӣ�
2.�����˳�������
3.���ֵ��ó�վ���г���죬���ȿ�һ����û�пչ죬���У��ӿ�
���վ��ԭ������ǿչ죬��û�У����¿��ٹ����վ���¿��ٵ�
���Ϊ�չ졣
4.�����һ�л𳵵ı�Ŵ������зǿչ�������һ�л𳵵ı�ţ�
���ȿ�һ����û�пչ�������У���ͣ��չ������û�У����¿�
��һ�������
5.���ó�վ���г�����죬��Ӹù����վ�����жϸù���Ƿ�Ϊ�ա�
6.EmpNum:�չ����� MaxTrain:���й�����һ�������������һ��

*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
#define TrackMaxSize 100

typedef int ElemType;
typedef int Status; 

typedef struct{
	ElemType *TrainNum;
	int front;//��ǰ�泵�ı��
	int rear;//����泵�ı��
}Track;//���

typedef struct{
	Track *track;
	int TrackNum;
}Station;//��վ


int main()
{
	Station sta;
	int N;
	if(!InitSta(sta))
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return -1;
	}
	scanf("%d",&N);
	Dispatch(sta,N);
	return 0;
}

Status InitSta(Station sta)
{
	sta.track = (Track *) malloc (TrackMaxSize * sizeof(Track));
	if(!sta.track)exit(OVERFLOW);
	sta.TrackNum = 0;
	sta.track->TrainNum = (ElemType *) malloc (sizeof(ElemType));
	if(!sta.track->TrainNum)exit(OVERFLOW);
	sta.track->front = sta.track->rear =0;
}

Status Dispatch(Station sta,int n)
{
	int i = 0,trainnum,max;
	Track p;
	while(i<n)
	{
		scanf("%d",&trainnum);
		if(!i)
		{
			p.TrainNum = trainmum;
			p.front = p.rear = trainnum;
			(sta.track+1) = p;
			sta.TrackNum = 1;
		}
		else
		{
			TrevalSta(sta,max);
			if(trainnum == n)
			{
				
			}
		}
	}
}

Status TrevalSta(Station sta,int &e)
{
	int num=0,i;
	Track *p;
	if(sta.TrackNum == 0) return ERROR; 
	i = sta.TrackNum;
	p = sta.track+1;
	while(i != 0)
	{
		if(p->rear > num)
			num = sta.track->rear;
		++p;
		--i;		
	}
	e = num;
	return Ok;
}

Status LookEmpty(Station sta,int &i)
{
	Track *p;
	int emptynum,i;
	if(sta.TrackNum == 0)return ERROR;
	i = sta.TrackNum;
	p = sta.track +1;
	while(i)
	{
		if(p->front == p->rear == 0) ++emptynum;
		++p;
		--i;
	}
	return 0;
}
