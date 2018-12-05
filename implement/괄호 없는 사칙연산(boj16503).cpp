#include <stdio.h>

int calculate(int n1, int n2, char cal){
	if (cal == '+') return n1 + n2;
	else if (cal == '-') return n1 - n2;
	else if (cal == '*') return n1*n2;
	else return n1 / n2;
}
int main(){
	int n1, n2, n3, re1, re2, minus;
	char cal1, cal2;
	scanf("%d %c%d %c%d", &n1, &cal1, &n2, &cal2, &n3);
	minus = 0;
	re1 = calculate(n1, n2, cal1);
	if (cal2=='/' && re1 < 0){
		minus = 1;
		re1 = -re1;
	}
	re1 = calculate(re1, n3, cal2);
	if (minus){
		re1 = -re1;
	}

	minus = 0;
	re2 = calculate(n2, n3, cal2);
	if (cal1=='/' && re2 < 0){
		minus = 1;
		re2 = -re2;
	}
	re2 = calculate(n1, re2, cal1);
	if (minus){
		re2 = -re2;
	}
	if (re1 < re2)printf("%d\n%d\n", re1, re2);
	else printf("%d\n%d\n", re2, re1);
	return 0;
}