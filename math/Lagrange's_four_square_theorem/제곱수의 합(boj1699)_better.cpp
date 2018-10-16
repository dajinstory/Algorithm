#include <stdio.h>
#include <math.h>
using namespace std;

int sum[100004];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 1; i*i <= N; i++){
		sum[i*i] = 1;
		for (int j = i; i*i + j*j <= N; j++){
			sum[i*i + j*j] = 2;
		}
	}
	if (sum[N]){
		printf("%d", sum[N]);
		return 0;
	}

	for (int i = 1; i*i <= N; i++){
		if (sum[N - i*i]){
			printf("3");
			return 0;
		}
	}
	printf("4");
	return 0;
}