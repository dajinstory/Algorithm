#include <stdio.h>

int arr[2004];
int dp[2004][2004];
int visit[2004][2004];
int N, M;

int getDP(int s, int e){
	if(visit[s][e])return dp[s][e];
	visit[s][e]=1;

	if(arr[s]!=arr[e]) return 0;

	if(e-s<=1)dp[s][e]=1;
	else if(getDP(s+1, e-1)){
		dp[s][e]=1;
	}
	return dp[s][e];
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",&arr[i]);
	scanf("%d",&M);
	while(M--){
		int s,e;
		scanf("%d%d",&s, &e);
		printf("%d\n", getDP(s,e));
	}
	return 0;
}