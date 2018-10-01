#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

int map[10][1004];
vector<int> classroom[10];
unordered_set<int> friends[1004];
int main(){
	int N, max = 0, max_idx;
	scanf("%d", &N);
	for (int j = 1; j <= N; j++){
		for (int i = 1; i <= 5; i++){
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= N; j++){
			classroom[map[i][j]].push_back(j);
		}
		for (int j = 1; j <= 9; j++){
			for (int k = 0; k < classroom[j].size(); k++){
				int now = classroom[j][k];
				for (int k2 = 0; k2 < classroom[j].size(); k2++){
					int next = classroom[j][k2];
					auto itr = friends[now].find(next);
					if (itr == friends[now].end()){
						friends[now].insert(next);
					}
				}
			}
			classroom[j].clear();
		}
	}
	for (int i = 1; i <= N; i++){
		if (friends[i].size()>max){
			max = friends[i].size();
			max_idx = i;
		}
	}
	printf("%d", max_idx);
	return 0;
}