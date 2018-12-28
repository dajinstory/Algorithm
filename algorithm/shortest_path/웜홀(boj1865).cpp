#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct node{
	int e;
	int cost;
}node;

vector<node>adj[501];
ll dist[501];

vector<int> minus_node;
int check[501];

int findPath(int now){
	int re = 0;
	if (now == 1)return 1;
	for (int k = 0; k < adj[now].size(); k++){
		int next = adj[now][k].e;
		if (!check[next]){
			check[next] = 1;
			re += findPath(next);
		}
	}
	if (re > 0)return 1;
	else return 0;
}
int main(){
	int TC, N, M, W, s, e, t;
	const ll INF = 250000000;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 0; i < M; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e, t });
			adj[e].push_back({ s, t });
		}
		for (int i = 0; i < W; i++){
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e, -t });
		}
		for (int i = 1; i <= N; i++){
			dist[i] = INF;
		}
		dist[1] = 0;
		for (int k = 0; k < N; k++){
			for (int i = 1; i <= N; i++){
				for (int j = 0; j < adj[i].size(); j++){
					s = i;
					e = adj[s][j].e;
					t = adj[s][j].cost;
					if (dist[s] != INF && dist[s]+t<dist[e]){
						dist[e] = dist[s] + t;
						if (k == N - 1){
							minus_node.push_back(e);
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < minus_node.size(); i++){
		//	printf("(%d)", minus_node[i]);
			if (findPath(minus_node[i])){
				ans = 1;
			}
		}
		if (ans)printf("YES\n");
		else printf("NO\n");
		for (int i = 1; i <= N; i++){
			adj[i].clear();
			check[i] = 0;
		}
		minus_node.clear();
	}
	return 0;
}