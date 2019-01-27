#include <stdio.h>
int arr[100];
int N;
long long ans;
const int DIV = 10000003;
int getGCD(int a, int b){
	while (a != 0 && b != 0){
		if (a >= b){
			a %= b;
		}
		else{
			b %= a;
		}
	}
	return a + b;
}
void cal(int idx, int gcd){
	long long plus = 1;
	if (gcd == 1){
		for (int i = 0; i < N - idx; i++)plus = plus * 2 % DIV;
		ans = (ans + plus) % DIV;
	}
	else if(idx<N){
		cal(idx+1, getGCD(gcd, arr[idx]));
		cal(idx+1, gcd);
	}
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	cal(0, 0);
	printf("%lld", ans);
	return 0;
}