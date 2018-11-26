#include <stdio.h>
#define MOD 100030001
typedef long long ll;

ll dp[304][304];

ll memo(int n, int l);

int main(){
	int N, L;
	scanf("%d%d", &N, &L);
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= L; j++){
			dp[i][j] = -1;
		}
	}
	printf("%lld", (memo(N, L) - memo(N, L - 1) + MOD) % MOD);
	return 0;
}

ll memo(int n, int l){
	if (dp[n][l] != -1)return dp[n][l];
	if (n == 0) return dp[n][l] = 1;
	if (l == 0)return dp[n][l] = 0;
	ll re = 0;
	for (int i = 0; i < n; i++){
		re += (memo(i, l - 1)*memo(n - i - 1, l - 1)) % MOD;
		re %= MOD;
	}
	return dp[n][l] = re;
}