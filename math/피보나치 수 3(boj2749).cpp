#include <stdio.h>

const long long DIV = 1000000;
long long matrix[2][2];

void solve(long long N);
int main(){
	long long N;
	scanf("%lld", &N);
	solve(N+1);
	printf("%lld\n", matrix[1][1]);
	return 0;
}
void solve(long long N){
	if (N == 1){
		matrix[0][0] = 1;
		matrix[1][0] = matrix[0][1] = 1;
		matrix[1][1] = 0;
		return;
	}
	solve(N / 2);

	long long tmp[2][2];
	tmp[0][0] = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
	tmp[1][0] = tmp[0][1] = (matrix[0][0] + matrix[1][1]) * matrix[0][1];
	tmp[1][1] = matrix[1][1] * matrix[1][1] + matrix[0][1] * matrix[1][0];
	if (N % 2 == 1){
		tmp[1][1] = tmp[0][1];
		tmp[0][1] = tmp[0][0];
		tmp[0][0] += tmp[1][0];
		tmp[1][0] = tmp[0][1];
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			matrix[i][j] = tmp[i][j] % DIV;
		}
	}
}
