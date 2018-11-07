#include <stdio.h>
int main(){
	int N, M;
	long long ans;

	while (1){
		ans = 1;
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0)break;
		if (M > N / 2)M = N - M;
		for (int i = 0; i < M; i++){
			ans *= N - i;
			ans /= i + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}