#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<pair<int, int> >myQ;
vector<int> num;
int check[10];
int visit[1000001];

int getMin(int a, int b){
	if (a < b)return a;
	return b;
}
int getDist(int a, int b){
	if (a > b)return a - b;
	return b - a;
}
int main(){
	int N, M, minCost;
	scanf("%d%d", &N, &M);
	minCost = getDist(100, N);
	while (M--){
		int digit;
		scanf("%d", &digit);
		check[digit] = 1;
	}
	for (int i = 0; i < 10; i++){
		if (!check[i]){
			num.push_back(i);
			myQ.push(make_pair(i, 1));
			visit[i] = 1;
		}
	}
	while (!myQ.empty()){
		int now, cost, next;
		now = myQ.front().first;
		cost = myQ.front().second;
		myQ.pop();
		for (int i = 0; i < num.size(); i++){
			next = now * 10 + num[i];
			if (next > 1000000 || visit[next])continue;
			visit[next] = 1;
			myQ.push(make_pair(next, cost + 1));
		}
		minCost = getMin(minCost, cost + getDist(now, N));
	//	printf("%d %d %d\n", now, cost, minCost);
	}
	printf("%d", minCost);
	return 0;
}