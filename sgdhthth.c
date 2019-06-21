#include<stdio.h>
main()
{
	int i,j,h;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<i;j++)
			printf("        ");
		for(h=i;h<=9;h++)
		printf("%d*%d=%2d",i,h,i*h);
		printf("\n");
	}
}