#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 2505
using namespace std;

queue<pair<int, int> >myQ;
vector<int> link[MAX_N];
int visit[MAX_N];
char str[MAX_N];
int main(){
	int N, len;
	scanf(" %s", str);
	len = strlen(str);
	for (int c = 0; c < len; c++){
		link[c].push_back(c);
		for (int plus = 1; c + plus < len && c - plus >= 0 && str[c + plus] == str[c - plus]; plus++){
			link[c - plus].push_back(c + plus);
			link[c + plus].push_back(c - plus);
		}
		for (int plus = 0; c + plus + 1 < len && c - plus >= 0 && str[c + plus + 1] == str[c - plus]; plus++){
			link[c - plus].push_back(c + plus + 1);
			link[c + plus + 1].push_back(c - plus);
		}
	}
	myQ.push(make_pair(0, 0));
	while (!myQ.empty()){
		int now = myQ.front().first;
		int cost = myQ.front().second;
		myQ.pop();
		if (now == len){
			printf("%d", cost);
			break;
		}
		for (int i = 0; i < link[now].size(); i++){
			int next = link[now][i];
			if (!visit[next]){
				visit[next] = 1;
				myQ.push(make_pair(next + 1, cost + 1));
			}
		}
	}
	return 0;
}
