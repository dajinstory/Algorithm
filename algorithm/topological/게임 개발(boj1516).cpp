#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<pair<int, int> > myQ;
vector<int> nextt[501];
int indegree[501];
int cost[501];
int ans[501];

int getMax(int a, int b){
	if (a > b)return a;
	return b;
}
int main(){
	int N, pre;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d%d", &cost[i], &pre);
		while (pre!=-1){
			nextt[pre].push_back(i);
			indegree[i]++;
			scanf("%d", &pre);
		}
		if (indegree[i] == 0){
			myQ.push(make_pair(i, cost[i]));
			ans[i] = cost[i];
		}
	}
	while (!myQ.empty()){
		int now = myQ.front().first;
		int time = myQ.front().second;
		myQ.pop();
		for (int k = 0; k < nextt[now].size(); k++){
			int next = nextt[now][k];
			ans[next] = getMax(ans[next], time + cost[next]);
			if (--indegree[next] == 0){
				myQ.push(make_pair(next, ans[next]));
			}
		}
	}
	for (int i = 1; i <= N; i++)printf("%d\n", ans[i]);
	return 0;
}