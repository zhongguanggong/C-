#include<stdio.h>
#define MAXNUM 10000

void GetLine(int a[],int b,int c)
{
	int low,high,j=b;
	if(b == c) return;
	low = b;
	high = c;
	a[0] = a[b];
	while(high>low)
	{
		if(j == low)
		{
			if(a[high]<a[0])
			{
				a[j] = a[high];
				j = high;
			}
			else high--;
		}
		else if(j == high)
		{
			if(a[low]>a[0])
			{
				a[j] = a[low];
				j = low;
			}
			else low++;
		}
	}
	a[high+1] = a[0];
	GetLine(a,b,high);
	GetLine(a,low+1,c);
}

int main()
{
	int N,M,i;
	int a[MAXNUM];
	scanf("%d%d",&N,&M);
	for(i = 1;i<=N;i++)
		scanf("%d",&a[i]);
	GetLine(a,1,N);	
	for(i = 1;i<=M;i++)
		printf("%d",a[i]);
	return 0;
}
