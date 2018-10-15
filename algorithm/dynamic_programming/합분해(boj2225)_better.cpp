#include <stdio.h>
#define MOD 1000000000
int dp[201];
int main(){
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= 200; i++){
		dp[i] = 1;
	}
	for (int k = 2; k <= K; k++){
		dp[1] = k;
		for (int i = 2; i <= N; i++){
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}
	}
	printf("%d", dp[N]);
}