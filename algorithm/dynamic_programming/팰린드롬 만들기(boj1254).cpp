#include <stdio.h>
#include <string.h>

int dp[1004][1004];
char arr[1004];
int len, plus;

int getDP(int s, int e){
	if(e<=s)return dp[s][e]=1;
	if(dp[s][e] != 0)return dp[s][e];
	if(arr[s]==arr[e] && getDP(s+1, e-1)==1){
		return dp[s][e]=1;
	}
	return dp[s][e]=-1;
}

int main(){
	scanf("%s",arr+1);
	len=strlen(arr+1);

	for(int s=len;s>0;s--){
		if(getDP(s,len)==1) plus=s-1;
	}
	printf("%d", len+plus);
	return 0;
}