#include <stdio.h>
typedef long long ll;

int arr[504][2];
ll dp[504][504];
bool visit[504][504];
ll INF = 987654321987654321;
int N;

ll getMin(ll l, ll r){
	if(l<r)return l;
	return r;
}

ll getDP(int l, int r){
	if(visit[l][r])return dp[l][r];
	visit[l][r]=true;

	if(l==r) return dp[l][r]=0;

	dp[l][r]=INF;
	for(int i=l;i<r;i++){
		dp[l][r]=getMin(dp[l][r], getDP(l,i) + getDP(i+1,r) + arr[l][0]*arr[i][1]*arr[r][1]);
	}
	return dp[l][r];
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",&arr[i][0], &arr[i][1]);
	printf("%lld", getDP(0, N-1));
	return 0;
}