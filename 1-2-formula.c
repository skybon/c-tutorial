#include <stdio.h>

void main(){

	//a*((a%(a-b)) + (a/b))

	int a=100;
	int b=50;
	int c;
	int step1;
	int step2;
	int step3;
	int step4;

	//c=a*((a%(a-b)) + (a/b));

	step1=a-b;
	printf("%i \n", step1);

	step2=a%step1;
	printf("%i \n", step2);

	step3=step2+(a/b);
	printf("%i \n", step3);

	step4=a*step3;
	printf("%i \n", step4);
}
