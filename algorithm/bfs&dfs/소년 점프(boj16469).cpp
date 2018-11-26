#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX(A,B)((A)>(B)?(A):(B))
#define MIN(A,B)A<B?A:B
#define MAX_C 10004
using namespace std;

typedef struct node{
	int x;
	int y;
	int c;
};

int xx[4] = { 1, 0, -1, 0 }, yy[4] = { 0, 1, 0, -1 };
int map[104][104][4];
pair<int, int> start[3];
queue<node> myQ;

void solve(int sx, int sy, int start);
int main(){
	int N, M, re = MAX_C, cnt = 0;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			int tmp;
			scanf("%1d", &tmp);
			map[i][j][0] = -tmp + 1;
			map[i][j][1] = map[i][j][2] = map[i][j][3] = MAX_C;
		}
	}
	for (int i = 0; i < 3; i++){
		scanf("%d%d", &start[i].first, &start[i].second);
		solve(start[i].first, start[i].second, i + 1);
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			int tmp = MAX(map[i][j][1], MAX(map[i][j][2], map[i][j][3]));
			if (tmp == MAX_C)continue;
			if (tmp == re) cnt++;
			else if (tmp < re){
				re = tmp;
				cnt = 1;
			}
		}
	}

	if (cnt == 0)printf("-1");
	else{
		printf("%d\n%d\n", re, cnt);
	}

	return 0;
}

void solve(int sx, int sy, int start){
	map[sx][sy][start] = 0;
	myQ.push({ sx, sy, 0 });
	while (!myQ.empty()){
		int x = myQ.front().x;
		int y = myQ.front().y;
		int c = myQ.front().c;
		myQ.pop();
		for (int k = 0; k < 4; k++){
			int nx = x + xx[k];
			int ny = y + yy[k];
			if (map[nx][ny][0] && c + 1 < map[nx][ny][start]){
				map[nx][ny][start] = c + 1;
				myQ.push({ nx, ny, c + 1 });
			}
		}
	}
}