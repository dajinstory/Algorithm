#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node{
	int to;
	int cost;
	int time;
}node;

int dist[101][10001];
vector<node> adj[101];
priority_queue<pair<pair<int, int>, int> > myQ;
int main(){
	int T, N, M, K;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 1; i <= N; i++){
			adj[i].clear();
			for (int j = 0; j <= M; j++){
				dist[i][j] = 987654321;
			}
		}
		for (int i = 0; i < K; i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			adj[a].push_back({ b, c, d });
		}
		
		dist[1][0] = 0;
		myQ.push(make_pair(make_pair(0, 0), 1));
		while (!myQ.empty()){
			int now, cost, time;
			now = myQ.top().second;
			time = -myQ.top().first.first;
			cost = -myQ.top().first.second;
			myQ.pop();
			if (time > dist[now][cost])continue;

			for (int k = 0; k < adj[now].size(); k++){
				int next, cost_n, time_n;
				next = adj[now][k].to;
				cost_n = cost + adj[now][k].cost;
				time_n = time + adj[now][k].time;
				if (cost_n > M)continue;
				if (dist[next][cost_n] > time_n){
					dist[next][cost_n] = time_n;
					myQ.push(make_pair(make_pair(-time_n, -cost_n), next));
				}
			}
		}
		int ans = 987654321;
		for (int i = 0; i <= M; i++){
			if (dist[N][i] < ans)ans = dist[N][i];
		}
		if (ans == 987654321)printf("Poor KCM\n");
		else printf("%d\n", ans);
	}
	return 0;
}