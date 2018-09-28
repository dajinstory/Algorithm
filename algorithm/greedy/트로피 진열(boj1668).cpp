#include <stdio.h>

int arr[54];

int main(){
	int N, max = 0, max_idx, max_idx_2, re = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if (arr[i] > max){
			max = arr[i];
			max_idx = i;
			max_idx_2 = i;
		}
		else if (arr[i] == max){
			max_idx_2 = i;
		}
	}
	max = 0;
	for (int i = 0; i < max_idx; i++){
		if (arr[i] > max){
			max = arr[i];
			re++;
		}
	}
	printf("%d\n", re);
	re = 1, max = 0;
	for (int i = N-1; i > max_idx_2; i--){
		if (arr[i] > max){
			max = arr[i];
			re++;
		}
	}
	printf("%d", re);
	return 0;
}