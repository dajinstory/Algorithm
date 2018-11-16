#include <stdio.h>
long long getGCD(long long a, long long b){
	long long tmp;
	while (b != 0){
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}
long long solve(long long a, long long b);
int main(){
	int T;
	long long A, B;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &A, &B);
		printf("%lld\n", solve(A, B));
	}
	return 0;
}
long long solve(long long a, long long b){
	long long tmp, gcd, lcm;
	tmp = getGCD(a, b);
	a /= tmp;
	b /= tmp;
	while (1){
		tmp = b / a;
		if (tmp*a != b){
			tmp++;
		}
		gcd = getGCD(tmp, b);
		lcm = tmp / gcd*b;
		a = lcm / b*a - lcm / tmp;
		b = lcm;
		if (a == 0){
			return b;
		}
		gcd = getGCD(a, b);
		a /= gcd;
		b /= gcd;
	}
}