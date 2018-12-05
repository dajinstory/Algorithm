#include <stdio.h>
int main(){
	int N, num;
	long long sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++){
		scanf("%d", &num);
		sum += num;
	}
	printf("%lld", sum);
	return 0;
}