#include <stdio.h>
int books[104];
int main(){
	int N, M, L, sum = 0;
	scanf("%d%d%d", &N, &M, &L);
	for (int i = 0; i < N; i++){
		scanf("%d", &books[i]);
		sum += books[i];
	}
	if (sum > M){
		printf("-1");
	}
	else if (sum == M){
		printf("0");
	}
	else if (sum >= L || sum + L <= M){
		printf("1");
	}
	else{
		printf("-1");
	}

	return 0;
}