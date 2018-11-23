#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[5000001];
int main(){
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
//	sort(arr, arr + N);
	nth_element(arr, arr + K - 1, arr + N);
	printf("%d", arr[K - 1]);
	return 0;
}