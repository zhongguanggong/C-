#include <stdio.h>
void PrintN(long n);

int main()
{
    PrintN(66000L);
	//PrintN(5);
    return 0;
}

void PrintN(long n)
{
	if(n!=1)
		PrintN(n-1);
	printf("%ld",n);
}

