#include <stdio.h>
#include <vector>
#define MOD 1000000
using namespace std;

int map[500][1024];
int ans[11][501];
vector<int> pre[1024];
int check[11];

void solve(int n, int m);
void getPrev(int prev, int now, vector<int> &p);

int main(){
	int N, M;
	while (1){
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0){
			break;
		}
		if (!check[N]){
			check[N] = 1;
			solve(N, 500);
		}
		printf("%d\n", ans[N][M]);
	}
}

void solve(int n, int m){
	int l = 1;
	for (int i = 0; i < n; i++){
		l = l << 1;
	}
	for (int i = 0; i < l; i++){
		pre[i].clear();
		getPrev(l - 1, i, pre[i]);
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < l; j++){
			map[i][j] = 0;
		}
	}

	map[0][0] = 1;
	for (int i = 1; i < m; i++){
		for (int j = 0; j < l; j++){
			for (int k = 0; k < pre[j].size(); k++){
				map[i][j] = (map[i][j] + map[i - 1][pre[j][k]]) % MOD;
			}
		}
		ans[n][i + 1] = map[i][l - 1];
	}
}

void getPrev(int prev, int now, vector<int> &p){
	if (now == 0) p.push_back(prev);
	else{
		//1 
		//3 4
		//5 6
		int pos_1, pos_2, pos_3, pos_4, pos_5, pos_6;
		pos_4 = now&(-now);
		pos_3 = pos_4&prev;
		pos_1 = (now>1) * (pos_4 >> 1)&prev;
		pos_5 = (pos_4 << 1)&prev;
		pos_6 = (pos_4 << 1)&now;
		if (pos_3){
			if (pos_5){
				getPrev(prev ^ (pos_3 | pos_5), now^pos_4, p);
				if (pos_6){
					getPrev(prev ^ (pos_3 | pos_5), now ^ (pos_4 | pos_6), p);
				}
			}
			if (pos_1){
				getPrev(prev ^ (pos_1 | pos_3), now^pos_4, p);
			}
			if (pos_6){
				getPrev(prev ^ pos_3, now ^ (pos_4 | pos_6), p);
			}

		}
		if (pos_5&pos_6){
			getPrev(prev ^ pos_5, now ^ (pos_4 | pos_6), p);
		}
	}
}

/*
references
https://github.com/marioyc/Online-Judge-Solutions/blob/master/Live%20Archive/4608%20-%20Mosaic.cpp
*/