#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
int arr[1004];
int N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		int idx=lower_bound(dp.begin(), dp.end(), -arr[i]) - dp.begin();
		if(idx==dp.size())dp.push_back(-arr[i]);
		else dp[idx]=-arr[i];
	}
	printf("%d",dp.size());
	return 0;
}