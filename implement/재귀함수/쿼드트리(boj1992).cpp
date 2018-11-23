#include <stdio.h>
int map[64][64];
char input[65];
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
		printf("%d", pattern);
		return;
	}
	printf("(");
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			solve(x + (l / 2)*i, y + (l / 2)*j, l / 2);
		}
	}
	printf(")");
}
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf(" %s", input);
		for (int j = 0; j < N; j++){
			map[i][j] = input[j] - '0';
		}
	}
	solve(0, 0, N);
	return 0;
}