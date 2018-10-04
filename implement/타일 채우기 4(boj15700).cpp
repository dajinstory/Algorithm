#include <stdio.h>
int main(){
	long long N, M;
	scanf("%lld%lld", &N, &M);
	if (N % 2 == 0){
		printf("%lld", N / 2 * M);
	}
	else if (M % 2 == 0){
		printf("%lld", M / 2 * N);
	}
	else{
		printf("%lld", M / 2 * N + N / 2);
	}
	return 0;
}