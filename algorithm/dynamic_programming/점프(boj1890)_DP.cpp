#include <stdio.h>
#include <algorithm>
using namespace std;
int map[100][100];
long long cnt[100][100];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	cnt[0][0] = 1;
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			if (map[x][y]==0 || cnt[x][y] == 0)continue;
			int nx, ny;
			nx = x + map[x][y], ny = y + map[x][y];
			if (nx < N)	cnt[nx][y] += cnt[x][y];
			if (ny < N)	cnt[x][ny] += cnt[x][y];
		}
	}
	printf("%lld", cnt[N - 1][N - 1]);
	return 0;
}