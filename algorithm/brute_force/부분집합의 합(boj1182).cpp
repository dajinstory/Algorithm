#include <stdio.h>
#define MAX_N 20

int arr[MAX_N];
int N, S;

int getSum(int now, int select, int sum);
int main(){
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	printf("%d", getSum(0, 0, 0));
	return 0;
}
int getSum(int now, int select, int sum){
	if (now == N){
		if (sum == S && select > 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	return getSum(now + 1, select + 1, sum + arr[now]) + getSum(now + 1, select, sum);
}
