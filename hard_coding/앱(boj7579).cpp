#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector< pair<ll,ll> > dp;
ll memory[104];
ll cost[104];
ll N,M;

int main(){
	scanf("%lld%lld",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%lld",&memory[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%lld",&cost[i]);
	}
	
	dp.push_back(make_pair((ll)0,(ll)0));
	for(int i=0;i<N;i++){
		for(int j=dp.size()-1;j>=0;j--){
			pair<ll,ll> node = make_pair(dp[j].first+memory[i], dp[j].second+cost[i]);
			int idx = lower_bound(dp.begin(), dp.end(), node) - dp.begin();
			
			if(idx == dp.size() && dp[idx-1].first != node.first) dp.push_back(node);
			else if(node.first != dp[idx-1].first && node.second<dp[idx].second) {
				dp.insert(dp.begin()+idx, node);
				while(dp.size()-1>=idx+1 && dp[idx].first == dp[idx+1].first){
					dp.erase(dp.begin()+idx+1);
				}
			}
			while(idx-1>=0 && dp[idx-1].second>=dp[idx].second){
				dp.erase(dp.begin()+idx-1);
				idx--;
			}
		}
	}

	int idx=lower_bound(dp.begin(), dp.end(), make_pair(M,(ll)0))-dp.begin();
	printf("%lld", dp[idx].second);
	return 0;
}