#include <stdio.h>
#define MAX(A,B)((A)>(B)?(A):(B))

int dp[10004];
int memory[104];
int N,M, cost, cost_sum;

int main(){
	scanf("%d%d",&N,&M);

	for(int i=1;i<=N;i++)scanf("%d",&memory[i]);
	for(int i=1;i<=N;i++){
		scanf("%d",&cost);
		for(int c = cost_sum;c>=0;c--){
			dp[c+cost]=MAX(dp[c+cost], dp[c]+memory[i]);
		}
		cost_sum+=cost;
	}
	for(int c=0;c<=cost_sum;c++){
		if(dp[c]>=M){
			printf("%d", c);
			break;
		}
	}
	return 0;
}