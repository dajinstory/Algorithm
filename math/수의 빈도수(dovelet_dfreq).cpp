#include <stdio.h>
int main(){
	int N, M, re = 0, e10 = 1;;
	scanf("%d%d", &N, &M);
	while (e10 <= N){
		if (M == 0){
			re += (N / (e10 * 10) - 1) * e10;
		}
		else re += N / (e10 * 10) * e10;

		if (N % (e10 * 10) / e10 == M){
			re += N%e10 + 1;
		}
		else if (N % (e10 * 10) / e10 > M){
			re += e10;
		}
		e10 *= 10;
	}
	printf("%d\n", re);
	return 0;
}