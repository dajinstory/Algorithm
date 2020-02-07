#include <stdio.h>
typedef long long ll;

ll getMax(ll a, ll b){
	if(a>b)return a;
	return b;
}

int main(){
	ll T, P,M,F,C;
	scanf("%lld",&T);

	while(T--){
		scanf("%lld%lld%lld%lld",&P,&M,&F,&C);
		ll coupons = M/P*C%F + M/P*C/F*C;
		ll minus = F-C;
		printf("%lld\n", (coupons)>=(F) ? ((coupons-F)/minus + 1):(0));
	}
	return 0;
}