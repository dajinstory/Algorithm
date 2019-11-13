#include <stdio.h>
#define MIN(A,B)((A)<(B)?(A):(B))

int T,N,W;
int arr[10004][2];
int dp[4][10004][4];



void solve(){
	scanf("%d%d",&N,&W);
	for(int i=1;i<=N;i++)scanf("%d",&arr[i][0]);
	for(int i=1;i<=N;i++)scanf("%d",&arr[i][1]);
	
	dp[0][1][1]=1;
	dp[0][1][2]=1;
	dp[0][1][3]=2-(arr[1][0]+arr[1][1]<=W);
	
	dp[1][0][3]=987654321;
	dp[1][1][1]=1;
	dp[1][1][2]=987654321;
	dp[1][1][3]=2;
	
	dp[2][0][3]=987654321;
	dp[2][1][1]=987654321;
	dp[2][1][2]=1;
	dp[2][1][3]=2;

	dp[3][0][3]=987654321;
	dp[3][1][1]=987654321;
	dp[3][1][2]=987654321;
	dp[3][1][3]=2;

	for(int k=0;k<4;k++){
		for(int i=2;i<=N;i++){
			// 1
			dp[k][i][1]=dp[k][i-1][3]+1;
			if(arr[i][0]+arr[i-1][0]<=W){
				dp[k][i][1]=MIN(dp[k][i][1], dp[k][i-1][2]+1);
			}
			// 2
			dp[k][i][2]=dp[k][i-1][3]+1;
			if(arr[i][1]+arr[i-1][1]<=W){
				dp[k][i][2]=MIN(dp[k][i][2], dp[k][i-1][1]+1);
			}
			// 3
			dp[k][i][3]=MIN(dp[k][i][1],dp[k][i][2])+1;
			if(arr[i][0]+arr[i-1][0]<=W && arr[i][1]+arr[i-1][1]<=W){
				dp[k][i][3]=MIN(dp[k][i][3],dp[k][i-2][3]+2);
			}
			if(arr[i][0]+arr[i][1]<=W){
				dp[k][i][3]=MIN(dp[k][i][3],dp[k][i-1][3]+1);
			}
		}	
	}

	int ans=dp[0][N][3];
	if(arr[1][0]+arr[N][0]<=W)ans=MIN(ans,dp[1][N][2]);
	if(arr[1][1]+arr[N][1]<=W)ans=MIN(ans,dp[2][N][1]);
	if(arr[1][0]+arr[N][0]<=W && arr[1][1]+arr[N][1]<=W) ans=MIN(ans,dp[3][N-1][3]);
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}