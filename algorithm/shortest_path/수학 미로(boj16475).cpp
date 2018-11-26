#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX_N 10004
#define MAX_P 10
using namespace std;
typedef struct Node{
	int now;
	int cost;
	int trap;
}Node;

priority_queue<Node>myQ;
int isTrap[MAX_N];
int visit[MAX_N][2 * MAX_P];
vector<pair<int, int> > link[MAX_N][3]; //0: 일반길, 1: 트랩길, 2: 트랩길반대방향

int main(){
	int N, M, K, L, T, S, E, error = 1;
	scanf("%d%d%d%d%d", &N, &M, &K, &L, &T);
	for (int i = 0; i < K; i++){
		int tmp;
		scanf("%d", &tmp);
		isTrap[tmp] = 1;
	}
	for (int i = 0; i < M - L; i++){
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		link[A][0].push_back(make_pair(B, C));
	}
	for (int i = 0; i < L; i++){
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		link[A][1].push_back(make_pair(B, C));
		link[B][2].push_back(make_pair(A, C));
	}
	scanf("%d%d", &S, &E);
	myQ.push({ S, 0, 0 });
	while (!myQ.empty()){
		int now, cost, trap;
		now = myQ.top().now;
		cost = -myQ.top().cost;
		trap = myQ.top().trap;
		myQ.pop();

		if (visit[now][trap])continue;
		visit[now][trap] = 1;

		if (now == E){
			printf("%d", cost);
			error = 0;
			break;
		}

		for (int i = 0; i < link[now][0].size(); i++){
			int next = link[now][0][i].first;
			int next_c = cost + link[now][0][i].second;
			int next_t = trap;
			if (isTrap[next]){
				next_t = (next_t + 1) % (2 * T);
			}
			if (!visit[next][next_t]){
				myQ.push({ next, -next_c, next_t });
			}
		}
		if (trap < T){
			for (int i = 0; i < link[now][1].size(); i++){
				int next = link[now][1][i].first;
				int next_c = cost + link[now][1][i].second;
				int next_t = trap;
				if (isTrap[next]){
					next_t = (next_t + 1) % (2 * T);
				}
				if (!visit[next][next_t]){
					myQ.push({ next, -next_c, next_t });
				}
			}
		}
		else{
			for (int i = 0; i < link[now][2].size(); i++){
				int next = link[now][2][i].first;
				int next_c = cost + link[now][2][i].second;
				int next_t = trap;
				if (isTrap[next]){
					next_t = (next_t + 1) % (2 * T);
				}
				if (!visit[next][next_t]){
					myQ.push({ next, -next_c, next_t });
				}
			}
		}
	}
	if (error){
		printf("-1");
	}
	return 0;
}

bool operator<(const Node& lhs, const Node& rhs)
{
	return lhs.cost < rhs.cost;
}