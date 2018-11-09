#include <stdio.h>
#define MAX(A,B)((A)>(B)?(A):(B))
int map[100][100];
int xx[4] = { 0, -1, 0, 1 }, yy[4] = { 1, 0, -1, 0 };
int r1, c1, r2, c2, max_n = 0, len = 0;

void init(void);
void pp(int num, int len);
int main(){
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	init();

	max_n = map[0][0];
	max_n = MAX(max_n, map[0][c2-c1]);
	max_n = MAX(max_n, map[r2-r1][0]);
	max_n = MAX(max_n, map[r2-r1][c2-c1]);
	while (max_n){
		len++;
		max_n /= 10;
	}

	for (int i = r1; i <= r2; i++){
		for (int j = c1; j <= c2; j++){
			pp(map[i - r1][j - c1], len);
			printf("%d ", map[i - r1][j - c1]);
		}
		printf("\n");
	}
	return 0;
}
void init(void){
	int dir=0, num = 2;
	if (r1 <= 0 && r2 >= 0 && c1 <= 0 && c2 >= 0)map[-r1][-c1] = 1;

	for (int i = 0, j = 0, lev = 2; num <= 10001 * 10001; lev++){
		for (int k = 0; k < lev / 2; k++){
			i += xx[dir];
			j += yy[dir];
			if ((i >= r1)&&(i <= r2)&&(j >= c1)&&(j <= c2)){
				map[i - r1][j - c1] = num;
			}
			num++;
		}
		dir = (dir + 1) % 4;
	}
}
void pp(int num, int len){
	while (num){
		num /= 10;
		len--;
	}
	for (int i = 0; i < len; i++){
		printf(" ");
	}
}