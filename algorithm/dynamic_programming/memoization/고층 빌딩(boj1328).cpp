#include <stdio.h>
#define MOD 1000000007
typedef long long ll;

int dp[104][104][104];
int N,L,R;

ll getDP(int n, int l, int r){
	if(l+r-1>n || l<1 || r<1 || n<1)return 0;
	if(dp[n][l][r]) return dp[n][l][r];
	return dp[n][l][r]=(getDP(n-1,l,r)*(n-2)%MOD+getDP(n-1,l-1,r)+getDP(n-1,l,r-1))%MOD;
}

int main(){
	scanf("%d%d%d",&N,&L,&R);
	dp[1][1][1]=1;
	printf("%lld",getDP(N,L,R));
	return 0;
}