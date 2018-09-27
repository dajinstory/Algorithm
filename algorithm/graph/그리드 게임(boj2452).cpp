#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
//#include <queue>
#define MIN(A,B) ((A)<(B)? (A):(B))
#define MAX_N 104
#define QSIZE 1000004
using namespace std;

class QUEUE{
public:
	void push(pair<int, int> t){
		arr[end] = make_pair(t.first, t.second);
		end = (end + 1) % QSIZE;
	}
	void pop(void){
		start = (start + 1) % QSIZE;
	}
	int empty(void){
		if (end - start == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	pair<int, int> front(void){
		return arr[start];
	}
private:
	pair<int, int> arr[QSIZE];
	int start;
	int end;
};

//queue<pair<int, int> > myQ;
QUEUE myQ;
int map[MAX_N][MAX_N];
vector<int> link[MAX_N * MAX_N];
unordered_set<int> set[MAX_N * MAX_N];
int visit[MAX_N * MAX_N];
int check[MAX_N * MAX_N];
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, 1, 0, -1 };
int N, M, num;

void bfs_mapping(void);
pair<int, int> bfs_tree_level(int start);
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
	for (int i = 1; i <= num; i++){
		if (!check[i]){
			int re = bfs_checking(i, answer);
			answer = MIN(answer, re);
			check[i] = 1;
		}
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

				//set zero field for checking overlapped color
				//for (int k = 0; k < MAX_N * MAX_N; k++){
				//	visit[k] = 0;
				//}

				map[i][j] = num;
				//visit[num] = 1;
				set[num].insert(int(num));
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
						else if (map[nx][ny]>0){// && !visit[map[nx][ny]]){
							auto itr = set[num].find(map[nx][ny]);
							if (itr != set[num].end())continue;
							//visit[map[nx][ny]] = 1;
							set[num].insert(int(map[nx][ny]));
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
	int now;
	int dist;
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
