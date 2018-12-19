#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int> >myQ;
vector <int> level[10001];
int tree[10001][2];
int parent[10001];
int ll[10001];
int cnt;
void inorder(int now){
	if (now == -1)return;
	inorder(tree[now][0]);
	ll[now] = cnt++;
	inorder(tree[now][1]);
}
int getRoot(int now){
	while (parent[now] != 0)now = parent[now];
	return now;
}
int main(){
	int N, root;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tree[a][0] = b;
		tree[a][1] = c;
		parent[b] = a;
		parent[c] = a;
	}

	root = getRoot(1);
	myQ.push(make_pair(root, 1));
	while (!myQ.empty()){
		int now = myQ.front().first;
		int lev = myQ.front().second;
		myQ.pop();
		level[lev].push_back(now);
		if (tree[now][0] != -1)myQ.push(make_pair(tree[now][0], lev + 1));
		if (tree[now][1] != -1)myQ.push(make_pair(tree[now][1], lev + 1));
	}
	inorder(root);
	int answer = -1, ans_lev;
	for (int i = 1; level[i].size()>0; i++){
		int min = 987654321, max = 0;
		for (int j = 0; j < level[i].size(); j++){
			if (ll[level[i][j]] < min)min = ll[level[i][j]];
			if (ll[level[i][j]] > max)max = ll[level[i][j]];
		}
		if (max - min > answer){
			answer = max - min;
			ans_lev = i;
		}
	}
	printf("%d %d", ans_lev, answer + 1);
	return 0;
}