#include <stdio.h>

void main(){
	int a = 25;
	int b = 25;
	int c = 25;
	int largest;
	int smallest;

	//Finding equals
	if (a==b) {
		if (b==c) {
			printf("all vars are equal to %d \n", a);
			return 0;
		}
		else {
			printf("a=b=%d \n", a);
		}
	}
	if (b==c) {
		if (a==c) {
			printf("all vars are equal to %d \n", b);
		}
		else {
			printf("b=c=%d \n", b);
		}
	}
	if (c==a) {
		if(a==b){
			printf("all vars are equal to %d \n", b);
		}
		else {
			printf("a=c=%d \n", a);
		}
	}
	else {
		printf("no equals here \n");
	}

	if (a>=b) {
		if(b>=c) {
			largest=a;
			smallest=c;
		}
		else {
			smallest=b;
			if (a>=c) {
				largest=a;
			}
			else {
				largest=c;
			}
		}
	}
	else {
		if(b>=c) {
			largest=b;
			if (a>=c) {
				smallest=c;
			}
			else {
				smallest=a;
			}
		}

		else {
			largest=c;
		}
	}

	printf("Largest: %d \n", largest);
	printf("Smallest: %d \n", smallest);
}
