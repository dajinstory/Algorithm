#include <stdio.h>

int arr[2][1004];//i번 전봇대는 앞에서부터 몇번째 전봇대인지.
int map[1004][1004];//앞에서부터 i번째 전봇대와 j번째 전봇대가 연결되어있는지.
int DP[1004][1004];
int N, M, K, x, y;

int getMax(int a, int b) {
	if (a > b)return a;
	return b;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &x);
		arr[0][x] = i;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &y);
		arr[1][y] = i;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &x, &y);
		map[arr[0][x]][arr[1][y]] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				DP[i][j] = DP[i-1][j-1] + 1;
			}
			else {
				DP[i][j] = getMax(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	printf("%d", K - DP[N][M]);
	return 0;
}