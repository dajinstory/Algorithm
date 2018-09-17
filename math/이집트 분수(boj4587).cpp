#include <stdio.h>

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
	long long c1, p1, p2, div, limit = 1000000;
	while (1){
		scanf("%lld%lld", &c1, &p1);
		if (c1 == 0 && p1 == 0){
			break;
		}
		p2 = 2;
		while (1){
			if (p1 < p2*c1 && (p1*p2) / GCD(c1*p2 - p1, p1*p2) < limit){
				printf("%lld ", p2);
				c1 = c1*p2 - p1;
				p1 = p1*p2;
				div = GCD(c1, p1);
				c1 /= div;
				p1 /= div;
			}
			else if (p1 == p2*c1){
				printf("%lld\n", p2);
				break;
			}
			else{
				p2++;
			}
		}
	}
	return 0;
}