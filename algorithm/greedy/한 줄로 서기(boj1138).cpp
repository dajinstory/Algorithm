#include <stdio.h>
int arr[14];
int main(){
	int N, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &tmp);
		for (int j = 0;; j++){
			if (arr[j] != 0){
				tmp++;
			}
			else if (j == tmp){
				arr[j] = i;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}