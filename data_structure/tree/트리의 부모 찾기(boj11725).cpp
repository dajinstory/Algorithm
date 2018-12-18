#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int>adj[100001];
int root[100001];
queue<int>myQ;
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	myQ.push(1);
	root[1] = -1;
	while (!myQ.empty()){
		int now = myQ.front();
		myQ.pop();
		for (int i = 0; i < adj[now].size(); i++){
			int next = adj[now][i];
			if (root[next] == 0){
				myQ.push(next);
				root[next] = now;
			}
		}
	}
	for (int i = 2; i <= N; i++)printf("%d\n", root[i]);
	return 0;
}