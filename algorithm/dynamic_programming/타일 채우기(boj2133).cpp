#include <stdio.h>

int N;
int dp[34];

int getDP(int idx){
	if(dp[idx]!=0) return dp[idx];
	dp[idx]=getDP(idx-2)*3;
	for(int i=4;i<=idx;i+=2){
		dp[idx]+=2*getDP(idx-i);
	}
	return dp[idx];
}

int main(){
	scanf("%d",&N);
	if(N%2){
		printf("0");
	}
	else{
		dp[0]=1;
		printf("%d", getDP(N));
	}
	return 0;
}