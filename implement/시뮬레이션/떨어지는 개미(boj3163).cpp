#include <stdio.h>
#include <algorithm>
#include <vector>
#define MIN(A,B)((A)<(B)?(A):(B))
using namespace std;

vector<int> candidate;
pair<int, int> arr[100001];
int position[100001];

int main(){
	int T, N, L, K;
	scanf("%d", &T);
	while (T--){
		int pos, id;
		scanf("%d%d%d", &N, &L, &K);
		for (int i = 0; i < N; i++){
			scanf("%d%d", &pos, &id);
			position[i] = id;
			if (id > 0){
				arr[i] = make_pair(L - pos, id);
			}
			else{
				arr[i] = make_pair(pos, id);
			}
		}
		sort(arr, arr + N);
		int s = 0, e = N - 1, cnt, dist;
		dist = arr[K - 1].first;
		for (cnt = 0; dist != arr[cnt].first; cnt++){
			if (arr[cnt].second < 0){
				s++;
			}
			else{
				e--;
			}
		}
		for (int i = cnt; dist == arr[i].first; i++){
			if (arr[i].second < 0){
				candidate.push_back(position[s]);
				s++;
			}
			else{
				candidate.push_back(position[e]);
				e--;
			}
		}
		sort(candidate.begin(), candidate.end());
		printf("%d\n", candidate[K-cnt-1]);
		candidate.clear();
	}
	return 0;
}