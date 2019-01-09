#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[75600];
ll p[3];

ll getMin(ll a, ll b){
	if (a < b)return a;
	return b;
}
int overflow(ll a, ll b){
	if (a*b / b != a)return 1;
	return 0;
}
int main(){
	int idx, check = 0;
	scanf("%lld%lld%lld%d", &p[0], &p[1], &p[2], &idx);
	sort(p, p + 3);

	arr[0] = 1;
	for (int i = 1; i <= idx; i++){
		ll num = 1000000000000000001;
		for (int j = 0; j < i; j++){
			for (int k = 0; k < 3; k++){
				if (overflow(arr[j], p[k]))continue;
				if (arr[j] * p[k]>arr[i - 1]){
					num = getMin(num, arr[j] * p[k]);
				}
			}
		}
		arr[i] = num;
	}
	printf("%lld\n", arr[idx]);
	return 0;
}