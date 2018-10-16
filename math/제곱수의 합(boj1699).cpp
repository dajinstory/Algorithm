#include <stdio.h>

int sum[100004];
int N;

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		sum[i] = i;
		for (int j = 1; j*j <= i; j++){
			if (sum[i - j*j] + 1 < sum[i]){
				sum[i] = sum[i - j*j] + 1;
			}
		}
	}
	printf("%d", sum[N]);

	return 0;
}
