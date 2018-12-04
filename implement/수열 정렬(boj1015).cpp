#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> arr[51];
int ans[51];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int num;
		scanf("%d", &num);
		arr[i] = make_pair(num, i);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		ans[arr[i].second] = i;
	}
	for (int i = 0; i < N; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}