#include <stdio.h>
using namespace std;

int arr[10004];
int T, M;

int search(int sum, int idx);

int main(){
	int sum, subSum, min_avg;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &M);
		sum = 0;
		for (int i = 0; i < M; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		subSum = 0;
		for (int i = 0; i < M; i++){
			subSum += arr[i];
			if (sum%subSum == 0){
				if (search(subSum, i + 1)){
					printf("%d\n", subSum);
					break;
				}
			}
		}
	}
	return 0;
}

int search(int subSum, int idx){
	int sum = 0;
	for (int i = idx; i < M; i++){
		sum += arr[i];
		if (sum > subSum){
			return 0;
		}
		else if (sum == subSum){
			sum -= subSum;
		}
	}
	return 1;
}