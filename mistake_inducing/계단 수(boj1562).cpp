#include <stdio.h>
typedef long long ll;

ll dp[2][12];
ll ans, MOD=1000000000;
int N;

ll getDP(int s, int n){
	ll sum=0;
	for(int i=0;i<12;i++) dp[0][i]=dp[1][i]=0;
	for(int i=2;i<=n;i++) dp[0][i]=1;

	for(int i=1;i<N;i++){
		for(int j=s;j<=n;j++){
			dp[i%2][j]=(dp[(i-1)%2][j-1]+dp[(i-1)%2][j+1])%MOD;
		}
		//for(int j=1;j<=n;j++)printf("%d ",dp[i%2][j]);
		//printf("\n");
	}
	for(int i=s;i<=n;i++){
		sum+=dp[(N-1)%2][i];
		sum%=MOD;
	}
	return sum;
}

int main(){
	scanf("%d", &N);
	ans=(getDP(1,10) - getDP(1,9) - getDP(2,10) + getDP(2,9)+MOD)%MOD;
	printf("%lld", ans);
	return 0;
}