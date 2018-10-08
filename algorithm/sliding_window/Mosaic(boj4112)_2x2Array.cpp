#include <stdio.h>
#define DIV 1000000
int map[2][1024][1024];
int check[11][501];

void solve(int n, int m);

int main(){
	int N, M;

	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 500; j++){
			check[i][j] = -1;
		}
	}
	for (int i = 10; i >= 2; i--){
		solve(i, 500);
	}

	while (1){
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0){
			break;
		}
		printf("%d\n", check[N][M]);
	}
	return 0;
}

void solve(int n, int m){
	int l, now, next;

	l = 1;
	for (int i = 0; i < n; i++){
		l *= 2;
	}

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 1024; j++){
			for (int k = 0; k < 1024; k++){
				map[i][j][k] = 0;
			}
		}
	}
	map[1][0][0] = 1;
	for (int k = 1; k < m; k++){
		now = k % 2;
		next = (k + 1) % 2;
		for (int i = 0; i < l - 1; i++){
			for (int j = 0; j < l; j++){
				if (map[now][i][j] != 0){
					int tmp = -i - 1;
					int pos = tmp&-tmp;
					if (pos < l){
						if (!(j&pos)){
							//ÇÑÄ­¹Ù´ÚÀÏÀÚ
							if (pos > 1 && !(j&(pos >> 1))){
								map[now][i | pos][j | ((pos >> 1) + pos)] += map[now][i][j];
							}
							if ((pos << 1) < l && !(j&(pos << 1))){
								map[now][i | pos][j | ((pos << 1) + pos)] += map[now][i][j];
							}
						}
						if ((pos << 1) < l && !(i&(pos << 1))){
							//µÎÄ­¹Ù´Ú
							if (!(j&pos)){
								map[now][i | ((pos << 1) + pos)][j | pos] += map[now][i][j];
								if (!(j&(pos << 1))){
									map[now][i | ((pos << 1) + pos)][j | ((pos << 1) + pos)] += map[now][i][j];
								}
							}
							if (!(j&(pos << 1))){
								map[now][i | ((pos << 1) + pos)][j | (pos << 1)] += map[now][i][j];
							}
						}
					}
				}
			}
		}
		for (int j = 0; j < l; j++){
			map[next][j][0] = map[now][l - 1][j] % DIV;
			for (int i = 0; i < l; i++){
				map[now][i][j] = 0;
			}
		}
		check[n][k + 1] = map[next][l - 1][0];
	}
}