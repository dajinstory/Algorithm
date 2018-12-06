#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

vector<pair<int, int> > adj[10001];
ll dist[10001][21];
priority_queue<pair<ll, pair<int, int> > >pq;
int main(){
	int N, M, K;
	ll re = 900000000001;

	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++){
		int s, e, c;
		scanf("%d%d%d", &s, &e, &c);
		adj[s].push_back(make_pair(e, c));
		adj[e].push_back(make_pair(s, c));
	}
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= K; j++){
			dist[i][j] = -1;
		}
	}

	pq.push(make_pair(0, make_pair(0, 1)));
	while (!pq.empty()){
		int now = pq.top().second.second;
		ll cost = -pq.top().first;
		int road = -pq.top().second.first;
		pq.pop();

		if (dist[now][road] != -1){
			continue;
		}
		dist[now][road] = cost;

		for (int k = 0; k < adj[now].size(); k++){
			int next = adj[now][k].first;
			ll next_c = cost + adj[now][k].second;
			if (dist[next][road] == -1){
				pq.push(make_pair(-next_c, make_pair(-road, next)));
			}
			if (road < K && dist[next][road+1]==-1){
				pq.push(make_pair(-cost, make_pair(-(road + 1), next)));
			}
		}
	}

	for (int k = 0; k <= K; k++){
		if (dist[N][k] < re && dist[N][k] != -1){
			re = dist[N][k];
		}
	}
	printf("%lld", re);
	return 0;
}