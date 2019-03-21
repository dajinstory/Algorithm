#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int N, M, K, adder;
int flow[2002][2002];
int parent[2002];
vector<int> adj[2002];

int network_flow(void);
int main(){
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++){
		int num, home;
		scanf("%d", &num);
		while (num--){
			scanf("%d", &home);
			flow[i][N + home] = 1;
			adj[i].push_back(N + home);
			adj[N + home].push_back(i);
		}
	}
	adder = N + M + 2;
	flow[0][adder] = K;
	adj[0].push_back(adder);
	adj[adder].push_back(0);
	for (int i = 1; i <= N; i++) {
		flow[adder][i] = 1;
		adj[adder].push_back(i);
		adj[i].push_back(adder);
		flow[0][i] = 1;
		adj[0].push_back(i);
		adj[i].push_back(0);
	}
	for (int i = N + 1; i <= N + M; i++){
		flow[i][N + M + 1] = 1;
		adj[i].push_back(N + M + 1);
		adj[N + M + 1].push_back(i);
	}
	printf("%d", network_flow());
	return 0;
}

int network_flow(){
	int cnt = 0;
	queue<int> myQ;
	int S = 0, T = N + M + 1;
	while (true){
		for (int i = 0; i <= N + M + 2; i++){
			parent[i] = -1;
		}
		parent[0] = -2;
		myQ.push(S);
		while (!myQ.empty() && parent[T] == -1){
			int now = myQ.front();
			myQ.pop();
			for (int k = 0; k < adj[now].size(); k++){
				int next = adj[now][k];
				if (parent[next] == -1 && flow[now][next]>0){
					myQ.push(next);
					parent[next] = now;
				}
			}
		}
		while (!myQ.empty())myQ.pop();
		if (parent[T] == -1)break;
		int pos = T;
		while (pos != S){
			int b_pos = parent[pos];
			flow[b_pos][pos] -= 1;
			flow[pos][b_pos] += 1;
			pos = b_pos;
		}
		cnt++;
	}
	return cnt;
}