#include <stdio.h>
#define MAX_SIZE 246913

//int Nsosu 하면 4ms, bool Nsosu하면 0ms. bool 이 비트단위여서 더 빠르다.
bool Nsosu[MAX_SIZE];
int sum[MAX_SIZE];
int main(){
	for (int i = 2; i < MAX_SIZE; i++){
		sum[i] += sum[i - 1];
		if (!Nsosu[i]){
			sum[i]++;
			for (int j = i << 1; j < MAX_SIZE; j += i){
				Nsosu[j] = true;
			}
		}
	}
	int N;
	while (scanf("%d", &N)){
		if (N == 0)break;
		printf("%d\n", sum[2 * N] - sum[N]);
	}
	return 0;
}