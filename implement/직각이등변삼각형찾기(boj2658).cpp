#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int map[14][14];
pair<int, int> ans[3];
vector<int> xx[11];
vector<int> yy[11];

int main(){
	int min_x, min_y, max_x, max_y, left, right, first = 1;
	int check, top, bot = -1, idx = 0;

	for (int i = 1; i <= 10; i++){
		check = 0;
		for (int j = 1; j <= 10; j++){
			scanf("%1d", &map[i][j]);
			check += map[i][j];
			if (map[i][j] == 1){
				xx[i].push_back(j);
				yy[j].push_back(i);
			}
		}
		if (check){
			if (bot == -1){
				bot = i;
			}
			top = i;
		}
	}
	for (int j = 1; j <= 10; j++){
		if (map[bot][j] == 1 && map[bot][j - 1] == 0){
			ans[idx] = make_pair(bot, j);
			idx++;
		}
		else if (map[bot][j] == 1 && map[bot][j + 1] == 0){
			ans[idx] = make_pair(bot, j);
			idx++;
		}
	}
	for (int j = 1; j <= 10; j++){
		if (map[top][j] == 1 && map[top][j - 1] == 0){
			ans[idx] = make_pair(top, j);
			idx++;
		}
		else if (map[top][j] == 1 && map[top][j + 1] == 0){
			ans[idx] = make_pair(top, j);
			idx++;
		}
	}
	if (idx == 2){
		ans[2] = ans[1];
		for (int j = 1; j <= 10; j++){
			if (map[(bot + top) / 2][j] == 1){
				ans[1] = make_pair((bot + top) / 2, j);
				if (j == ans[0].second){
					ans[1].second = j + (top - bot) / 2;
				}
				break;
			}
		}
	}
	for (int k = 1; k <= 10; k++){
		if (xx[k].size() > 0 && xx[k][xx[k].size() - 1] - xx[k][0] + 1 != xx[k].size()){
			printf("0");
			return 0;
		}
		if (yy[k].size() > 0 && yy[k][yy[k].size() - 1] - yy[k][0] + 1 != yy[k].size()){
			printf("0");
			return 0;
		}
	}

	for (int i = 0; i < 3; i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}