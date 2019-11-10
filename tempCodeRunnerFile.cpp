#include <stdio.h>
#define MAX(A,B)((A)>(B)?(A):(B))
typedef long long ll;

ll dp[8200004];
int T,N;

ll getDP(int num){
	if(num>8200004)printf("\nerror with %d", num);
	if(dp[num])return dp[num];
	int next_num = (num%2==0 ? (num/2):(num*3+1));
	return dp[num]=MAX(num, getDP(next_num));
}

int main(){
	dp[1]=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n", getDP(N));
	}
	return 0;
}