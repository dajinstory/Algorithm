#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;

vector<pair<int, int> > link[100004];
queue<pair<int, int> > myQ;
int visit[100004][3];

int main(){
	int N, s, e, a, b, cost, now, re = 0, bp = 0;
	scanf("%d%d%d", &N, &s, &e);
	
	for (int i = 0; i < N - 1; i++){
		scanf("%d%d%d", &a, &b, &cost);
		link[a].push_back(make_pair(b, cost));
		link[b].push_back(make_pair(a, cost));
	}

	visit[s][0] = 1;
	visit[s][1] = 0;
	visit[s][2] = 0;
	myQ.push(make_pair(s, 0));
	while (!myQ.empty()){
		now = myQ.front().first;
		cost = myQ.front().second;
		myQ.pop();
		for (int i = 0; i < link[now].size(); i++){
			int next = link[now][i].first;
			int next_c = link[now][i].second;
			if (!visit[next][0]){
				visit[next][0] = 1;
				visit[next][1] = MAX(visit[now][1], next_c);
				visit[next][2] = visit[now][2] + next_c;
				myQ.push(make_pair(next, cost + next_c));
			}
			if (next == e){
				bp = 1;
				break;
			}
		}
		if (bp){
			break;
		}
	}
	printf("%d", visit[e][2] - visit[e][1]);
	return 0;
}