#include <stdio.h>

long long arr[104][104][104];

long long nCk(int n, int k){
	int ans = 1;
	for (int i = 0; i < k; i++){
		ans *= n - i;
	}
	for (int i = 0; i < k; i++){
		ans /= (i + 1);
	}
	return ans;
}

long long solve(int n, int r, int g, int b){
	long long ans = 0;
	if (n < 0 || r < 0 || g < 0 || b < 0){
		return 0;
	}
	if (arr[r][g][b] != -1){
		return arr[r][g][b];
	}
	if (n == 0){
		return arr[r][g][b] = 1;
	}
	if (n % 3 == 0){
		ans += solve(n - 1, r - n / 3, g - n / 3, b - n / 3) * nCk(n, n / 3) * nCk(n / 3 * 2, n / 3);
	}
	if (n % 2 == 0){
		ans += solve(n - 1, r - n / 2, g - n / 2, b) * nCk(n, n / 2);
		ans += solve(n - 1, r - n / 2, g, b - n / 2) * nCk(n, n / 2);;
		ans += solve(n - 1, r, g - n / 2, b - n / 2) * nCk(n, n / 2);
	}
	ans += solve(n - 1, r - n, g, b);
	ans += solve(n - 1, r, g - n, b);
	ans += solve(n - 1, r, g, b - n);
	return arr[r][g][b] = ans;
}

int main(){
	int N, rn, gn, bn;
	scanf("%d%d%d%d", &N, &rn, &gn, &bn);
	for (int i = 0; i <= rn; i++){
		for (int j = 0; j <= gn; j++){
			for (int k = 0; k <= bn; k++){
				arr[i][j][k] = -1;
			}
		}
	}
	if ((N + 1)*N / 2 > rn + gn + bn){
		printf("0");
	}
	else{
		printf("%lld\n", solve(N, rn, gn, bn));
	}

	return 0;
}