#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX(A,B) ((A)>(B)? (A):(B))
#define MIN(A,B) ((A)<(B)? (A):(B))
#define MAX_N 104
using namespace std;

queue<pair<int, int> > myQ;
int map[MAX_N][MAX_N];
vector<int> link[MAX_N * MAX_N];
vector<int> bpgraph[2];
int visit[MAX_N * MAX_N];
int check[MAX_N * MAX_N];
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, 1, 0, -1 };
int N, M, num;

void bfs_mapping(void);
int bfs_checking(int start, int ans);
int main(){
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
			map[i][j] -= 2;
		}
	}

	bfs_mapping();

	int answer = 987654321;
	int fst = 0, snd = 1;
	if (bpgraph[0].size() < bpgraph[1].size()){
		fst = 1;
		snd = 0;
	}

	for (int i = 0; i < bpgraph[fst].size(); i++){
		int now = bpgraph[fst][i];
		if (!check[now]){
			if (link[now].size() == 1){
				check[now] = 1;
				continue;
			}
			int re = bfs_checking(now, answer);
			check[now] = re;
			if (re < answer){
				bpgraph[snd].clear();
				answer = re;
				bpgraph[snd].push_back(now);
			}
			else if (re == answer){
				bpgraph[snd].push_back(now);
			}
		}
	}
	for (int i = 0; i < bpgraph[snd].size(); i++){
		int pre = bpgraph[snd][i];
		for (int j = 0; j < link[pre].size(); j++){
			int now = link[pre][j];
			if (!check[now]){
				if (link[now].size() == 1){
					check[now] = 1;
					continue;
				}
				int re = bfs_checking(now, answer);
				check[now] = re;
				if (re < answer){
					answer = re;
				}
			}
		}
	}
	if (answer == 987654321){
		answer = num - 1;
	}
	printf("%d", answer);
	return 0;
}

void bfs_mapping(){
	int color;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (map[i][j] < 0){
				num++;
				color = map[i][j];
				bpgraph[color + 2].push_back(num);

				//set zero field for checking overlapped color
				for (int k = 0; k < MAX_N * MAX_N; k++){
					visit[k] = 0;
				}

				map[i][j] = num;
				visit[num] = 1;
				myQ.push(make_pair(i, j));
				while (!myQ.empty()){
					int x = myQ.front().first;
					int y = myQ.front().second;
					myQ.pop();
					for (int k = 0; k < 4; k++){
						int nx = x + xx[k];
						int ny = y + yy[k];
						if (map[nx][ny] == color){
							map[nx][ny] = num;
							myQ.push(make_pair(nx, ny));
						}
						else if (map[nx][ny]>0 && !visit[map[nx][ny]]){
							visit[map[nx][ny]] = 1;
							link[num].push_back(map[nx][ny]);
							link[map[nx][ny]].push_back(num);
						}
					}
				}
			}
		}
	}
}

int bfs_checking(int start, int ans){
	int now, dist;
	//visit[i] = i번째 노드까지 가는데 얼마만큼 걸리나. 
	//전체개수가 num이므로 최대치는 num-1, 떄문에, num으로 초기화
	//ans보다 큰 visit[i]값을 갖는 i는 후보에서 제거
	for (int i = 1; i <= num; i++){
		visit[i] = num;
	}
	visit[start] = 0;
	myQ.push(make_pair(start, 0));
	while (!myQ.empty()){
		now = myQ.front().first;
		dist = myQ.front().second;
		myQ.pop();
		if (dist >= ans){
			for (int i = 1; i <= num; i++){
				if (visit[i] >= ans){
					check[i] = 1;
				}
			}
			while (!myQ.empty()){
				myQ.pop();
			}
			return 987654321;
		}

		for (int i = 0; i < link[now].size(); i++){
			int next = link[now][i];
			if (visit[next] == num){
				visit[next] = dist + 1;
				myQ.push(make_pair(next, dist + 1));
			}
		}
	}
	return dist;
}
 