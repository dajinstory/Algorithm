#include <stdio.h>
#include <vector>
using namespace std;
vector<int>adj[100004];
int dp[100001][20];

int getMin(int a, int b){
	if (a < b)return a;
	return b;
}

void solve(int parent, int now){
	for (int i = 0; i < adj[now].size(); i++){
		int child = adj[now][i];
		if (child == parent)continue;
		solve(now, child);
	}
	for (int select = 0; select < 20; select++){
		dp[now][select] = select + 1;
		for (int k = 0; k < adj[now].size(); k++){
			int child = adj[now][k];
			if (child == parent) continue;

			int plus = 987654321;
			for (int check = 0; check < 20; check++){
				if (check == select)continue;
				plus = getMin(plus, dp[child][check]);
			}
			dp[now][select] += plus;
		}
	}
}
int main(){
	int N, ans = 987654321;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++){
		int s, t;
		scanf("%d%d", &s, &t);
		adj[s].push_back(t);
		adj[t].push_back(s);
	}
	solve(0, 1);
	for (int i = 0; i < 20; i++){
		ans = getMin(ans, dp[1][i]);
	}
	printf("%d", ans);
	return 0;
}