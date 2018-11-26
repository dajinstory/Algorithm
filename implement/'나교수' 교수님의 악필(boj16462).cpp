#include <stdio.h>

int func(int n);
int main(){
	int N, sum = 0, score;
	double re;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &score);
		tmp = func(score);
		if (tmp > 100){
			sum += 100;
		}
		else{
			sum += tmp;
		}
	}
	re = ((double)sum) / N;
	printf("%.0lf", re);
	return 0;
}
int func(int n){
	int a, b, c;
	c = n % 10; n /= 10;
	b = n % 10; n /= 10;
	a = n;
	if (a > 0){
		if (a == 6)a = 9;
		if (b == 0 || b == 6)b = 9;
		if (c == 0 || c == 6)c = 9;
	}
	else if (b > 0){
		if (b == 6)b = 9;
		if (c == 0 || c == 6)c = 9;
	}
	else if (c == 0 || c == 6)c = 9;
	return 100 * a + 10 * b + c;
}
