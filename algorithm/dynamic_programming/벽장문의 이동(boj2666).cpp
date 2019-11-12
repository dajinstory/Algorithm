#include <stdio.h>
#define MIN(A,B) ((A)<(B) ? (A):(B))
#define ABS(A) ((A)>(0) ? (A):-(A))
#define INF 987654321
typedef long long ll;

int dp[21][21][21];
int arr[21];
int N, M, a, b, ans=INF;


int main(){
	scanf("%d%d%d%d",&N,&a,&b,&M);
	for(int i=1;i<=M;i++) scanf("%d",&arr[i]);
	for(int k=0;k<=M;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dp[k][i][j]=INF;
			}
		}
	}

	dp[0][a][b]=0;
	for(int k=0;k<M;k++){
		int next=arr[k+1];
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dp[k+1][next][j]=MIN(dp[k+1][next][j],dp[k][i][j]+ABS(next-i));
				dp[k+1][i][next]=MIN(dp[k+1][i][next],dp[k][i][j]+ABS(next-j));
			}
		}
	}
	for(int i=1;i<=N;i++){
		ans=MIN(ans, dp[M][i][arr[M]]);
		ans=MIN(ans, dp[M][arr[M]][i]);
	}

	printf("%d",ans);
	return 0;
}