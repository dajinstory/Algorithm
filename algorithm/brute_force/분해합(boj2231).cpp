#include <stdio.h>
int main(){
	int N, num, sum, ans = 0, len = 0, s;
	scanf("%d", &N);
	num = N;
	while (num){
		len++;
		num /= 10;
	}
	s = N - len * 9;
	if (s < 0)s = 1;
	for (int i = s; i <= N; i++){
		sum = i;
		num = i;
		while (num){
			sum += num % 10;
			num /= 10;
		}
		if (sum == N){
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}