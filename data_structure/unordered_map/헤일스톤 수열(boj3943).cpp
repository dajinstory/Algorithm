#include <stdio.h>
#include <iostream>
#include <unordered_map>
#define MAX(A,B)((A)>(B)?(A):(B))
using namespace std;
typedef long long ll;

unordered_map<ll,ll> dp;
int T,N;

ll getDP(ll num){
	if(dp.find(num)!=dp.end())return dp[num];
	ll next_num = (num%2==0 ? (num/2):(num*3+1));
	return dp[num]=MAX(num, getDP(next_num));
}

int main(){
	dp[1]=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n", getDP(N));
	}
	return 0;
}