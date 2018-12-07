#include <stdio.h>
#include <algorithm>
#define DIV 1000000007
using namespace std;

typedef long long ll;

pair < ll, ll > fibo[80];
void initFibo(void){
	fibo[0] = make_pair(0, 1);
	for (int i = 1; i <= 62; i++){
		ll small, big;
		small = ((fibo[i - 1].first*fibo[i - 1].first) % DIV + (fibo[i - 1].second*fibo[i - 1].second) % DIV) % DIV;
		big = ((fibo[i - 1].second*fibo[i - 1].first) % DIV + ((fibo[i - 1].first + fibo[i - 1].second) % DIV * fibo[i - 1].second) % DIV) % DIV;
		fibo[i] = make_pair(small, big);
	}
}
ll getGCD(ll a, ll b){
	while (b != 0){
		ll tmp;
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}
ll getFibo(ll idx){
	ll minus = 1;
	int exp = 0;
	ll small = 1, big = 0, bigger;

	while (minus <= idx){
		minus *= 2;
		exp++;
	}
	while (idx != 0){
		if (minus > idx){
			minus /= 2;
			exp--;
		}
		else{
			idx -= minus;
			bigger = small + big;
			small = ((small*fibo[exp].first) % DIV + (big*fibo[exp].second) % DIV) % DIV;
			big = ((big*fibo[exp].first) % DIV + (bigger*fibo[exp].second) % DIV) % DIV;
		}
		//printf("%lld %lld\n", small, big);
	}
	return big;
}
int main(){
	long long N, M, G;
	scanf("%lld%lld", &N, &M);

	initFibo();

	G = getGCD(M, N);

	printf("%lld", getFibo(G));
	return 0;
}