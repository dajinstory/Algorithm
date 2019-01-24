#include <stdio.h>
typedef struct node{
	int from;
	int to;
	int cost;
}node;

node arr[6000];
long long dist[501];
int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = { a, b, c };
	}

	for (int i = 1; i <= N; i++){
		dist[i] = 987654321000;
	}
	dist[1] = 0;
	for (int i = 0; i <= N + N; i++){
		for (int k = 0; k < M; k++){
			int from, to, cost;
			from = arr[k].from;
			to = arr[k].to;
			cost = arr[k].cost;
			if (dist[from] == 987654321000)continue;
			if (i < N - 1){
				if (dist[from] + cost < dist[to])dist[to] = dist[from] + cost;
			}
			else{
				if (dist[from] == 987654321001)dist[to] = 987654321001;
				else if (dist[from] + cost < dist[to]){
					dist[to] = 987654321001;
				}
			}
		}
	}
	for (int i = 2; i <= N; i++){
		if (dist[i] == 987654321000){
			dist[i] = -1;
		}
		else if (dist[i] == 987654321001){
			printf("-1");
			return 0;
		}
	}
	for (int i = 2; i <= N; i++)printf("%lld\n", dist[i]);
	return 0;
}