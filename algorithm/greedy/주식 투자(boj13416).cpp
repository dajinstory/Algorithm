#include <stdio.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

int main(){
	int T, N, A, B, C, sum;
	scanf("%d", &T);
	while (T--){
		sum = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d%d%d", &A, &B, &C);
			sum+= MAX(MAX(A,B), MAX(C, 0));
		}
		printf("%d\n", sum);
	}
	return 0;
}