#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long n;

int main(int argc, char *argv[])
{
	if (argc<2)
	{
		printf("Введите число!");
		return 0;
	}
	n=atoi(argv[1]);
	while(n!=1)
	{
		if(n%2!=0)
		{
			n=n*3+1;
		}
		else
		{
			n=n/2;
		}
		printf("%lld\n",n);
	}
}
