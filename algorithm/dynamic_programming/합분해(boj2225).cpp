#include <stdio.h>
#define MOD 1000000000
int dp[204][204];

int solve(int k, int n);
int main(){
	int N, K;
	scanf("%d%d", &N, &K);
	dp[0][0] = 1;
	printf("%d", solve(K, N));
	return 0;
}

int solve(int k, int n){
	if (dp[k][n] != 0)return dp[k][n];
	if (k == 1)return dp[k][n] = 1;;
	for (int i = 0; i <= n; i++){
		dp[k][n] += solve(k - 1, n - i);
		dp[k][n] %= MOD;
	}
//	printf("k=%d n=%d: %d\n", k, n, dp[k][n]);
	return dp[k][n];
}