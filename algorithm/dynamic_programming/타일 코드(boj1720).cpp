#include <stdio.h>
typedef long long ll;

ll dp[31];
int N;
ll ans;

ll getDP(int n){
	if(n<0)return 0;
	if(dp[n])return dp[n];
	return dp[n]=getDP(n-2)*2+getDP(n-1);
}

int main(){
	dp[0]=1;
	scanf("%d",&N);
	if(N%2){
		ans=(getDP(N)+getDP(N/2))/2;
	}
	else{
		ans=(getDP(N)+getDP(N/2)+getDP(N/2-1)*2)/2; 
	}
	printf("%lld",ans);
	return 0;
}