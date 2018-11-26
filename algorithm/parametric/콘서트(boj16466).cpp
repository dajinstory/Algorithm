#include <stdio.h>
//원래는 N값이 훨씬 컸었다... 그래서 parametric으로 해결
typedef long long ll;
ll arr[1000000];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &arr[i]);
	}

	ll l, r, m, sum;
	l = 1; r = 5000000000;;
	while (l <= r){
		m = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < N; i++){
			if (arr[i] <= m){
				sum++;
			}
		}
		if (sum < m){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	printf("%lld", l);
	return 0;
}