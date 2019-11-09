#include <stdio.h>
typedef long long ll;

ll dp[64][10];
int T,N;
int main(){
	for(int j=0;j<10;j++)dp[0][j]=10-j;
	for(int i=1;i<64;i++){
		dp[i][9]=dp[i-1][9];
		for(int j=8;j>=0;j--){
			dp[i][j]=dp[i-1][j]+dp[i][j+1];
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",dp[N-1][0]);
	}
		return 0;
}