#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100004];

int main(){
	int N, M, tmp, idx;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	scanf("%d", &M);
	while (M--){
		scanf("%d", &tmp);
		idx = lower_bound(arr, arr + N, tmp) - arr;
		if (idx < N && arr[idx] == tmp){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
}