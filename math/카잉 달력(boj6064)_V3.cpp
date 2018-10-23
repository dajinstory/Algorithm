#include <stdio.h>
int getGCD(int a, int b){
	int tmp;
	while (a*b > 0){
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a + b;
}
int main(){
	int T, M, N, a, b, rest, ans, LCM;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &M, &N, &a, &b);
		if (M == N){
			if (a == b){
				printf("%d\n", a);
			}
			else{
				printf("-1\n");
			}
			continue;
		}
		else if (M > N){
			int tmp = M;
			M = N;
			N = tmp;
			tmp = a;
			a = b;
			b = tmp;
		}
		ans = 0;
		rest = 0;
		LCM = N / getGCD(N, M) *M;
		if (a > b) b += N;
		while ((LCM + a - b) % M != rest && ans < LCM){
			rest = (rest + N) % M;
			ans += N;
		}
		if (ans == LCM) printf("-1\n");
		else printf("%d\n", ans + b);
	}
	return 0;
}