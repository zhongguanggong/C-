#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{ 
	unsigned  int  key,get,stay;    
	int i,j,count1 = 0,count2;
	int a[8],b[4],c[4];
	FILE *pf = NULL;
	pf = fopen("E:/altera/13.0/FPGACode/TEST/test.txt","w");
	if(!pf)
	{
		printf("文件打开失败！");
		exit(1);
	}
    srand(time(NULL));    
	for( i=0 ;i<200; i++)
	{   
		key  =   rand() & 0xff;
		printf("%d_",key);
		stay = key;
		for(j=0;j<8;j++)
		{
			get = key % 2;
			a[j] = get;
			key = key / 2;
			if(!get) 
			{
				count1 ++;
				count2 = j+1;
			}
		}
		printf("%d_%d\n",count1,count2);
		for(j=0;j<4;j++)
		{
			b[j] = count1 % 2;
			count1 = count1/2;
			c[j] = count2 %2;
			count2 = count2/2;
		}
		
		for(j = 0;j<8;j++)
			fprintf(pf,"%d",a[j]); 
		fprintf(pf,"_%d",b[0]);
		for(j = 1;j<4;j++)
			fprintf(pf,"%d",b[j]);
		fprintf(pf,"_%d",c[0]);
		for(j = 1;j<3;j++)
			fprintf(pf,"%d",c[j]);
		fprintf(pf,"%d\n",c[4]);
		count1 = 0;
	}
	if(pf)
		fclose(pf);
	printf("数据已写入！");
	return 0;
}
