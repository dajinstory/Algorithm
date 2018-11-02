#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int arr[104];
queue<pair<int, int> >myQ;
int main(){
	int T, N, M;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
			myQ.push(make_pair(i, arr[i]));
		}
		sort(arr, arr + N);
		int idx = 1;
		while (!myQ.empty()){
			if (myQ.front().second == arr[N - idx]){
				if (myQ.front().first == M){
					printf("%d\n", idx);
				}
				idx += 1;
				myQ.pop();
			}
			else{
				myQ.push(myQ.front());
				myQ.pop();
			}
		}
	}
	return 0;
}