#include <stdio.h>

typedef long long ll;

ll dp[10][100000]; // idx: i segments, j rests. k len, value: first:maxnum, second:min 10^n(10^n>maxnum)
ll nums[11] = {0,1,2,3,4,5,6,7,8,9,11};
ll muls[11] = {10,10,10,10,10,10,10,10,10,10,100};

int main(){
	ll T, N, M;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&N,&M);
		
		// init dp array
		for(ll i=0, high10=1; i<10; i++, high10*=10){
			// dp
			int j_scope = (high10)<(M) ? (high10):(M);
			for(int j=0;j<j_scope;j++){
				
				dp[i][j]=high10/M*M+j;
				if(dp[i][j]>=high10) dp[i][j]-=M;
				if(dp[i][j]<0) dp[i][j]=-1;
			}
			for(int j=j_scope; j<M; j++){
				dp[i][j]=-1;
			}
		}		

		// solve
		for(int i=0; i<N; i++){
			for(int j=0;j<M;j++){
				if(dp[i][j]==-1) continue;
				for(int idx=0;idx<11;idx++){
					int num = nums[idx];
					int mul = muls[idx];
					ll new_val = dp[i][j]*mul + num;
					ll new_div = new_val%M;
					dp[i+1][new_div] = (dp[i+1][new_div])>(new_val) ? (dp[i+1][new_div]):(new_val);
				}
			}
		}
		printf("%lld\n", dp[N][0]);
	}
	return 0;
}