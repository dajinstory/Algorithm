#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> nums;
int N;

void make_nums(ll num){
	nums.push_back(num);
	for(int i=0;i<num%10;i++){
		make_nums(num*10+i);
	}
}


int main(){
	scanf("%d",&N);
	if(N<0 || N>1022){
		printf("-1");
		return 0;
	}

	for(ll i=0;i<=9;i++){
		make_nums(i);
	}
	sort(nums.begin(), nums.end());

	printf("%lld", nums[N]);
	return 0;
}