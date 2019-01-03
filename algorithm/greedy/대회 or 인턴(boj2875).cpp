#include <stdio.h>

int getMin(int a, int b){
	if (a < b)return a;
	return b;
}

int main(){
	int N, M, K, num;
	scanf("%d%d%d", &N, &M, &K);
	num = getMin(N / 2, M);
	if (N + M - 3 * num < K){
		num -= (K - (N + M - 3 * num) + 2) / 3;
	}
	printf("%d", num);
	return 0;
}