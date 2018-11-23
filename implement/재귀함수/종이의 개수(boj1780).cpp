#include <stdio.h>
int map[2400][2400];
int ans[2];
void solve(int x, int y, int l){
	int re = 0, pattern = map[x][y], bp = 0;
	for (int i = x; i < x + l; i++){
		for (int j = y; j < y + l; j++){
			if (pattern != map[i][j]){
				bp = 1;
				break;
			}
		}
		if (bp)break;
	}
	if (!bp){
		ans[pattern + 1]++;
		return;
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			solve(x + (l / 3)*i, y + (l / 3)*j, l / 3);
		}
	}
}
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	solve(0, 0, N);
	printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);
	return 0;
}