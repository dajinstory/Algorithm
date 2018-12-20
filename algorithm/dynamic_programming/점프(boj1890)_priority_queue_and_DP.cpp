#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<pair<int, int> >myQ;
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
	myQ.push(make_pair(0, 0));
	cnt[0][0] = 1;
	while (!myQ.empty()){
		int x, y, nx, ny;
		x = -myQ.top().first;
		y = -myQ.top().second;
		myQ.pop();
		if (x == N - 1 && y == N - 1)break;

		nx = x + map[x][y], ny = y + map[x][y];
		if (nx < N){
			if (cnt[nx][y] == 0){
				myQ.push(make_pair(-nx, -y));
			}
			cnt[nx][y] += cnt[x][y];
		}
		if (ny < N){
			if (cnt[x][ny] == 0){
				myQ.push(make_pair(-x, -ny));
			}
			cnt[x][ny]+=cnt[x][y];
		}
	}
	printf("%lld", cnt[N - 1][N - 1]);
	return 0;
}