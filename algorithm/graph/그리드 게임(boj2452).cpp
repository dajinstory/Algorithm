#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int> > myQ;
vector<int> graph[104];
int gg[104][104];
int visit[104];
int map[104][104];
int team[104][104];
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, 1, 0, -1 };
int re;

int bfs(int now);
int main(){
	int M, N, num = 0, color;
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0){
				map[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			if (team[i][j] == 0){
				num++;
				color = map[i][j];
				myQ.push(make_pair(i, j));
				while (!myQ.empty()){
					int x = myQ.front().first;
					int y = myQ.front().second;
					myQ.pop();
					team[x][y] = num;
					for (int k = 0; k < 4; k++){
						int nx = x + xx[k];
						int ny = y + yy[k];
						if (map[nx][ny] == color){
							if (team[nx][ny] == 0){
								myQ.push(make_pair(nx, ny));
							}
						}
						else if (team[nx][ny] != 0 && gg[num][team[nx][ny]] == 0){
							graph[num].push_back(team[nx][ny]);
							graph[team[nx][ny]].push_back(num);
							gg[num][team[nx][ny]] = 1;
							gg[team[nx][ny]][num] = 1;
						}
					}
				}
			}
		}
	}
	printf("\n");
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			printf("%d ", team[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= num; i++){
		printf("%d: ", i);
		for (int j = 0; j < graph[i].size(); j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	int start = bfs(1);
	bfs(start);
	printf("%d", re/2);
	return 0;
}

int bfs(int now){
	re = 1;
	myQ.push(make_pair(now, re));
	for (int i = 1; i < 104; i++){
		visit[i] = -1;
	}
	while (!myQ.empty()){
		now = myQ.front().first;
		re = myQ.front().second;
		myQ.pop();
		visit[now] = 1;
		for (int k = 0; k < graph[now].size(); k++){
			int next = graph[now][k];
			if (visit[next] == -1){
				myQ.push(make_pair(next, re + 1));
			}
		}
	}
	return now;
}