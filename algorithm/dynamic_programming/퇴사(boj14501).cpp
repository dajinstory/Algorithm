#include <stdio.h>
#define MAX(A,B)((A)>(B) ? (A):(B))

int days[16];
int costs[16];
int dp[16];
int N;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&days[i], &costs[i]);
	}
	
	for(int i=1;i<=N;i++){
		for(int j=i+days[i]-1;j<=N;j++){
			dp[j]=MAX(dp[j], dp[i-1]+costs[i]);
		}
	}
	printf("%d",dp[N]);
	return 0;
}