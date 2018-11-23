#include <stdio.h>
int mat1[104][104];
int mat2[104][104];
int re[104][104];
int main(){
	int N, M, K;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	scanf("%d%d", &M, &K);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < K; j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			for (int k = 0; k < M; k++){
				re[i][j] += mat1[i][k] * mat2[k][j];
			}
			printf("%d ", re[i][j]);
		}
		printf("\n");
	}
	return 0;
}