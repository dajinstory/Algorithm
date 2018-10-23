#include <stdio.h>
typedef long long ll;

ll abs(ll a){
	if (a < 0) return -a;
	return a;
}
ll egcd(ll a, ll b, ll &s, ll &t) {
	if (!b){
		s = 1, t = 0;
		return a;
	}
	ll q = a / b, r = a%b, sp, tp;
	ll g = egcd(b, r, sp, tp);
	s = tp; t = sp - tp*q;
	return g;
}
int main(){
	int T;
	ll M, N, a, b, s, t, G;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld%lld%lld", &M, &N, &a, &b);
		a--, b--;
		G = egcd(M, N, s, t);
		if (abs(a - b) % G == 0) {
			ll k = (b - a) / G;
			ll d = M * N / G;
			printf("%lld\n", (d * 100000000 + s * k * M + a) % d + 1);
		}
		else puts("-1");
	}
	return 0;
}