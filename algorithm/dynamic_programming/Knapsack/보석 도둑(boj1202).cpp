#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int>myQ;
pair<int, int> pdt[300001];
int weight[300001];

int main(){
	int N, K, idx = 0;
	long long re = 0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &pdt[i].first, &pdt[i].second);
	}
	for (int i = 0; i < K; i++){
		scanf("%d", &weight[i]);
	}
	sort(pdt, pdt + N);
	sort(weight, weight + K);
	
	for (int i = 0; i < K; i++){
		while (idx<N && pdt[idx].first <= weight[i]){
			myQ.push(pdt[idx].second);
			idx++;
		}
		if (!myQ.empty()){
			re += myQ.top();
			myQ.pop();
		}
	}
	printf("%lld", re);
	return 0;
}