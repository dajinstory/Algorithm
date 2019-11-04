#include <stdio.h>
typedef long long ll;

int arr[104];
ll dp[104][41];
int N;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}

	dp[1][10+arr[1]]=1;
	for(int i=2;i<N;i++){
		for(int j=10;j<=30;j++){
			if(dp[i-1][j]!=0){
				dp[i][j+arr[i]] += dp[i-1][j];
				dp[i][j-arr[i]] += dp[i-1][j];
			}
		}
	}

	printf("%lld", dp[N-1][10+arr[N]]);
	return 0;
}