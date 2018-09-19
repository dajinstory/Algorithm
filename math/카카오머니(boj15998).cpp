#include <stdio.h>

long long arr[300004][2];

long long GCD(long long a, long long b){
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

int main(){
	int N, start;
	long long gcd;
	scanf("%d", &N);

	//set arr
	arr[0][0] = 0, arr[0][1] = 0;
	for (int i = 1; i <= N; i++){
		scanf("%lld%lld", &arr[i][0], &arr[i][1]);
		if (arr[i - 1][1] + arr[i][0] >= 0 && arr[i - 1][1] + arr[i][0] != arr[i][1]){
			printf("-1");
			return 0;
		}
	}

	//get first gcd
	start = -1;
	for (int i = 1; i <= N; i++){
		if (arr[i - 1][1] + arr[i][0] < 0){
			start = i;
			gcd = -arr[i][0] + arr[i][1] - arr[i - 1][1];
			break;
		}
	}

	//solve
	if (start == -1){
		printf("1000");
	}
	else{
		for (int i = start + 1; i <= N; i++){
			if (arr[i - 1][1] + arr[i][0] < 0){
				gcd = GCD(gcd, -arr[i][0] + arr[i][1] - arr[i - 1][1]);
			}
		}
		for (int i = 1; i <= N; i++){
			if (arr[i - 1][1] + arr[i][0] < 0){
				if (arr[i][1] - gcd >= 0){
					printf("-1");
					return 0;
				}
			}
		}
		printf("%lld", gcd);
	}
	return 0;
}