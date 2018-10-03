#include <stdio.h>
#include <queue>
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;

priority_queue<pair<int, pair<int, int> > > myQ;
int map[1004][1004][5];
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, 1, 0, -1 };
int N, M, H, sum;

void getInput(void);
void init(void);
void bfs(void);

int main(){
	getInput();
	init();
	for (int i = 1; i <= N; i++){
		if (map[i][1][3] != -1){
			myQ.push(make_pair(-map[i][1][3], make_pair(i, 1)));
		}
		if (map[i][M][1] != -1){
			myQ.push(make_pair(-map[i][M][1], make_pair(i, M)));
		}
	}
	for (int j = 1; j <= M; j++){
		if (map[1][j][2] != -1){
			myQ.push(make_pair(-map[1][j][2], make_pair(1, j)));
		}
		if (map[N][j][0] != -1){
			myQ.push(make_pair(-map[N][j][0], make_pair(N, j)));
		}
	}
	bfs();
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (map[i][j][4] == -1){
				sum += H;
			}
			else{
				sum += map[i][j][4];
			}
		}
	}
	printf("%d", sum);
	return 0;
}

void getInput(void){
	scanf("%d%d%d", &N, &M, &H);
	for (int i = 1; i <= N + 1; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &map[i][j][2]);
			map[i - 1][j][0] = map[i][j][2];
		}
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M + 1; j++){
			scanf("%d", &map[i][j][3]);
			map[i][j - 1][1] = map[i][j][3];
		}
	}
}

void init(void){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			map[i][j][4] = -1;
		}
	}
}

void bfs(){
	int x, y, c;
	while (!myQ.empty()){
		x = myQ.top().second.first;
		y = myQ.top().second.second;
		c = -myQ.top().first;
		myQ.pop();

		if (map[x][y][4] != -1){
			continue;
		}
		map[x][y][4] = c;

		for (int k = 0; k < 4; k++){
			int nx, ny, nc;
			nx = x + xx[k];
			ny = y + yy[k];
			nc = map[x][y][k];
			if (nc != -1){
				myQ.push(make_pair(-MAX(nc,c), make_pair(nx, ny)));
			}
		}
	}
}
