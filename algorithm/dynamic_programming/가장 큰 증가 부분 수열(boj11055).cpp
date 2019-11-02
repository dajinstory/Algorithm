#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > dp;
int arr[1004];
int N;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&arr[i]);
	for(int i=0;i<N;i++){
		pair<int,int> item = make_pair(arr[i], arr[i]);
		int idx = lower_bound(dp.begin(), dp.end(), item)-dp.begin();
		if(idx>0){
			item.second+=dp[idx-1].second;
		}
		if(idx==dp.size()) dp.push_back(item);
		else{
			dp.insert(dp.begin()+idx,item);
			while( idx+1 < dp.size()  && dp[idx].second>=dp[idx+1].second){
				dp.erase(dp.begin()+idx+1);
			}
		}
	}

	int ans=0;
	for(int i=0;i<dp.size();i++){
		if(dp[i].second>ans){
			ans = dp[i].second;
		}
	}
	printf("%d", ans);
	return 0;
}