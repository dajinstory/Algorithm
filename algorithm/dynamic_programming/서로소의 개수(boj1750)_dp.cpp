//dp[100000]로 하고 check[100000]해도 되긴 하는데, 구현 귀찮아서 그냥 크게 잡는것두 좋다
#include <stdio.h>
int arr[101];
int dp[101][100001];
int check[101][100001];
int getGCD(int a, int b){
	while (a != 0 && b != 0){
		if (a >= b)a %= b;
		else b %= a;
	}
	return a + b;
}

int main(){
	int N;
	const int DIV = 10000003;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &arr[i]);

	check[0][0] = 1;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= 100000; j++){
			if (check[i-1][j] != 0){
				int nj = getGCD(j, arr[i]);
				check[i][j] = 1;
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= DIV;

				check[i][nj] = 1;
				dp[i][nj] += dp[i - 1][j];
				dp[i][nj] %= DIV;
			}
		}
	}
	printf("%d", dp[N][1]);
	return 0;
}