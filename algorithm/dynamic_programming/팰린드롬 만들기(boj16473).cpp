#include <stdio.h>
#define MAX(A,B)((A)>(B)?(A):(B))
int arr[5004];
int dp[5004][5004];

void solve(int N);
int main(){
	int N, M, T;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}

	solve(N);

	scanf("%d", &T);
	while (T--){
		scanf("%d", &M);
		printf("%d\n", N - dp[M][M] + 1);
	}
	return 0;
}
void solve(int N){
	for (int len = N; len >= 1; len--){
		for (int start = 1; start + len - 1 <= N; start++){
			int end = start + len - 1;
			if (arr[start] == arr[end]){
				dp[start][end] = dp[start - 1][end + 1] + 2;
			}
			else{
				dp[start][end] = MAX(dp[start - 1][end], dp[start][end + 1]);
			}
		}
	}

}