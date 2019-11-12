#include <stdio.h>
typedef long long ll;

ll dp[1004][1004];
int N, K;
ll MOD=1000000003;

int main(){
	scanf("%d%d",&N,&K);
	dp[0][0]=1;
	dp[1][0]=1;
	dp[1][1]=1;
	for(int n=2;n<=N;n++){
		for(int s=0;s<=n;s++){
			dp[n][s]=(dp[n-1][s]+dp[n-2][s-1])%MOD;
		}
	}
	printf("%d", (dp[N-3][K-1]+dp[N-1][K])%MOD);
	return 0;
}