#include <stdio.h>
#include <vector>
#define MIN(A,B)((A)<(B)?(A):(B))
using namespace std;

vector<int> friends[1000001];
int dp[1000001][2];
bool visit[1000001][2];
int N, cnt;

int getDP(int pre, int now, int check){
	if(visit[now][check])return dp[now][check];
	visit[now][check]=true;
	if(check)dp[now][check]=1;
	for(int i=0;i<friends[now].size();i++){
		int next=friends[now][i];
		if(next==pre)continue;
		int plus=getDP(now,next,1);
		if(check==1){
			plus=MIN(plus,getDP(now,next,0));
		}
		dp[now][check]+=plus;
	}
	return dp[now][check];
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	printf("%d",MIN(getDP(-1,1,0), getDP(-1,1,1)));
	return 0;
}