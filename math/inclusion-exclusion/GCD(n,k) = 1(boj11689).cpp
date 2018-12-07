#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> insu;
ll N;

long long cal(vector<ll> myV, int idx, long long now, int select){
	if (idx == myV.size()){
		if (select % 2 == 1){
			return -(N / now);
		}
		else{
			return N / now;
		}
	}
	return cal(myV, idx + 1, now*myV[idx], select + 1) + cal(myV, idx + 1, now, select);
}

int main(){
	ll re = 1, num;
	scanf("%lld", &N);
	num = N;
	for (ll i = 2;i*i<=num; i++){
		if (num%i == 0){
			insu.push_back(i);
			while (num%i == 0){
				num /= i;
			}
		}
	}
	if (num != 1){
		insu.push_back(num);
	}
	printf("%lld", cal(insu, 0, 1, 0));
	return 0;
}