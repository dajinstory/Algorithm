#include <stdio.h>
typedef long long ll;

ll dp[10];
ll ans[64];
int T,N;
int main(){
	for(int j=0;j<10;j++)dp[j]=10-j;
	ans[0]=dp[0];
	for(int i=1;i<64;i++){
		for(int j=1;j<10;j++){
			for(int k=0;k<j;k++){
				dp[k]+=dp[j];
			}
		}
		ans[i]=dp[0];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",ans[N-1]);
	}
		return 0;
}