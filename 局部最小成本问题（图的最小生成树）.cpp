#include<stdio.h>

#define OK 1
#define ERROR 0

typedef int Status ;

struct PORINFOR{
	int cost;//成本
	int status;//是否已修
} Graf[100][100];

Status InitGraf(int n)
{
	int i,j;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
		{
			Graf[i][j].cost = 10000;
			Graf[i][j].status = 1;
		}
	}
	return OK;
}

Status CreatGraf(int n)
{
	int i,j,cost,status,a,b;
	Graf[0][0].cost = 10000;
	Graf[0][0].status = 1;
	for(i = 0;i<n-1;i++)
	{
		for(j = i+1;j<n;j++)
		{
			scanf("%d%d",&a,&b);
			//if((a-1 == i)&&(b-1 == j))
			//{
				scanf("%d%d",&cost,&status);
				Graf[i][j].cost = cost;
				Graf[i][j].status = status;
		//	}
		}
	}
	for(j = 0;j<n-1;j++)
	{
		for(i = j;j<n;j++)
		{
			if(i == j)
			{
				Graf[i][j].cost = 10000;
				Graf[i][j].status = 1;
			}
			else
			{
				Graf[i][j].cost = Graf[j][i].cost;
				Graf[i][j].status = Graf[j][i].status;
		
			}
		}
	}

	return OK;
}

Status Judge(int n,int k,int j)
{
	int i;
	for(i = 0;i<n;i++)
	{
		if(Graf[k][i] == 1)
		{
			if(Graf[i][j] == 1)
			{
				Graf[k][j] = 1;
			    return 1;
			}
			else{ 
				if(Judge(n,i,j))
				{
					Graf[k][j] = 1;
					return 1;
				}
			}
		}
	}
	return 0;
}

void JudgeMin()
{

}

int MinCost(int n)
{
	int i,j,k,l;
	for(i = 0;i<n;i++)
	{
		for(j = i+1;j<n;j++)
		{
			if(!Graf[i][j].status)
			{
				if(Judge(n,i,j))
				{
					Graf[i][j].status = 1;	
				}
				else 
			}
		}
	}

}



int main()
{
	int n;
	scanf("%d",&n);
	InitGraf(n);
	CreatGraf(n);
	return 0;
}
