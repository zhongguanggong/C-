/*算法：
1.初始化一个队列，按火车入站顺序按编号入队；
2.按入队顺序进入轨道
3.若轮到该出站的列车入轨，则先看一下有没有空轨，若有，从空
轨出站，原轨道仍是空轨，若没有，则新开辟轨道出站，新开辟的
轨道为空轨。
4.如果后一列火车的编号大于所有非空轨道上最后一列火车的编号，
则先看一下有没有空轨道，若有，则停入空轨道，若没有，则新开
辟一条轨道。
5.若该出站的列车已入轨，则从该轨道出站，并判断该轨道是否为空。
6.EmpNum:空轨数量 MaxTrain:所有轨道最后一辆车编号中最大的一个

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
	int front;//最前面车的编号
	int rear;//最后面车的编号
}Track;//轨道

typedef struct{
	Track *track;
	int TrackNum;
}Station;//车站


int main()
{
	Station sta;
	int N;
	if(!InitSta(sta))
	{
		printf("初始化失败！\n");
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
