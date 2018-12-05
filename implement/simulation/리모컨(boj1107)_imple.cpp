#include <stdio.h>
#define MIN(A,B)((A)<(B)?(A):(B))
int block[10];
int check(int num){
	if (num == 0) return !block[0];
	while (num){
		if (block[num % 10]){
			return 0;
		}
		num /= 10;
	}
	return 1;
}
int main(){
	int N, M, re;
	scanf("%d%d", &N, &M);
	while (M--){
		int tmp;
		scanf("%d", &tmp);
		block[tmp] = 1;
	}
	re = N - 100;
	if (re < 0)re = -re;
	for (int i = N; i >= 0; i--){
		if (check(i)){
			int num = i, plus = 0;
			if (num == 0)plus = 1;
			while (num){
				num /= 10;
				plus++;
			}
			re = MIN(re, N - i + plus);
			break;
		}
	}
	for (int i = N; i <= 1000000; i++){
		if (check(i)){
			int num = i, plus = 0;
			if (num == 0)plus = 1;
			while (num){
				num /= 10;
				plus++;
			}
			re = MIN(re, i - N + plus);
			break;
		}
	}
	printf("%d", re);
	return 0;
}