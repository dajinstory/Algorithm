#include <stdio.h>
#include <string.h>
#define MAX_L 400

int num[MAX_L];
char re[MAX_L];
int main(){
	int N, M, len;
	scanf("%d%d", &N, &M);
	num[0] = 1;
	
	//mul
	for (int i = 0; i < M; i++){
		for (int j = 0; j < MAX_L-1; j++){
			num[j + 1] += num[j] / 10;
			num[j] %= 10;
			num[j] *= N - i;
		}
	}
	for (int j = 0; j < MAX_L-1; j++){
		num[j + 1] += num[j] / 10;
		num[j] %= 10;
	}

	//div
	for (int i = 2; i <= M; i++){
		for (int j = MAX_L - 1; j > 0; j--){
			num[j - 1] += num[j] % i * 10;
			num[j] /= i;
		}
		num[0] /= i;
	}
	
	
	for (int j = 0; j < MAX_L - 1; j++){
		num[j + 1] += num[j] / 10;
		num[j] %= 10;
		if (num[j] > 0)len = j;
	}
	for (int j = 0; j <= len; j++){
		re[j] = num[len - j] + '0';
	}
	printf("%s", re);
	return 0;
}