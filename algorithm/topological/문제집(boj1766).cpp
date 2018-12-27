#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> nextt[32001];
int indegree[32001];
priority_queue<int>myQ;

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	while (M--){
		int a, b;
		scanf("%d%d", &a, &b);
		nextt[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= N; i++){
		if (indegree[i] == 0)myQ.push(-i);
	}
	while (!myQ.empty()){
		int now = -myQ.top();
		myQ.pop();
		printf("%d ", now);
		for (int k = 0; k < nextt[now].size(); k++){
			int next = nextt[now][k];
			if (--indegree[next] == 0){
				myQ.push(-next);
			}
		}
	}
	return 0;
}