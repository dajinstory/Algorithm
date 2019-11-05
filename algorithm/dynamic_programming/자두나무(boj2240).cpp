#include <stdio.h>
#define MIN(A,B)((A)<(B)?(A):(B))
#define MAX(A,B)((A)>(B)?(A):(B))

int arr[1004];
int dp[1004][34];
int T,W,ans;

int main(){
	scanf("%d%d",&T,&W);
	for(int i=1;i<=T;i++) scanf("%d",&arr[i]);

	for(int i=1;i<=T;i++){
		int swap = MIN(i,W);
		dp[i][0]=dp[i-1][0]+(arr[i]==1);
		for(int j=1;j<=swap;j++){
			dp[i][j]=MAX(dp[i-1][j], dp[i-1][j-1])+(arr[i]%2==(j+1)%2);
		}
	}

	for(int i=0;i<=W;i++){
		ans=MAX(ans, dp[T][i]);
	}
	printf("%d",ans);
	return 0;
}