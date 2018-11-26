#include <stdio.h>
#define MAX_N 15

long long fibo[21];
long long matrix[MAX_N][MAX_N];
long long standard[MAX_N][MAX_N];
const int DIV = 100000007;
//NxN 행렬의 m승 = 2N-2+m-1번쨰 애.
//X번째 애 => 3-2N+X승

void set_fibo(int);
void set_standard(int);
void mul_standard(void);
void mul_matrix(void);
void solve(int, int);

int main(){
	int T, N, K;
	long long re;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &K, &N);

		set_fibo(K);
		set_standard(K);
		if (3 - 2 * (K + 2) + N < 2){
			re = fibo[N];
			//printf("부족해!");
		}
		else{
			solve(3 - 2 * (K + 2) + N - 1, K);
			//printf("연산함! %d ", 3 - 2*(K + 2) + N);
			re = 0;
			for (int i = 0; i < K + 2; i++){
				re += fibo[K * 2 + 2 - i] * matrix[i][0];
				re %= DIV;
			}
		}
		printf("%lld\n", re);
	}
	return 0;
}

void set_fibo(int K){
	fibo[0] = 1;
	for (int i = 1; i <= (K + 2) * 2 - 1; i++){
		fibo[i] = fibo[i - 1];
		if (i - K - 1 >= 0)fibo[i] += fibo[i - K - 1];
	}
}
void set_standard(int K){
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			standard[i][j] = 0;
			matrix[i][j] = 0;
		}
	}
	standard[0][0] = 1;
	standard[K][0]++;
	for (int i = 1; i < K + 2; i++){
		standard[i - 1][i] = 1;
	}
}
void solve(int N, int K){
	if (N == 1){
		for (int i = 0; i < MAX_N; i++){
			for (int j = 0; j < MAX_N; j++){
				matrix[i][j] = standard[i][j];
			}
		}
		return;
	}
	solve(N / 2, K);
	mul_matrix();
	if (N % 2 == 1){
		mul_standard();
	}
}

void mul_matrix(void){
	long long tmp[MAX_N][MAX_N];
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			tmp[i][j] = 0;
			for (int k = 0; k < MAX_N; k++){
				tmp[i][j] += matrix[i][k] * matrix[k][j];
				tmp[i][j] %= DIV;
			}
		}
	}
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			matrix[i][j] = tmp[i][j];
		}
	}
}

void mul_standard(void){
	long long tmp[MAX_N][MAX_N];
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			tmp[i][j] = 0;
			for (int k = 0; k < MAX_N; k++){
				tmp[i][j] += matrix[i][k] * standard[k][j];
				tmp[i][j] %= DIV;
			}
		}
	}
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			matrix[i][j] = tmp[i][j];
		}
	}
}
