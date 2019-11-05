#include <stdio.h>

int sum[11];
int dp_sum[10][11]; // 0~start, len
int dp[10][11]; // start, len
int N, ans_len=-1;
long long ans;

int main(){
	scanf("%d",&N);
	N++;

	if(N<0 || N>1023){
		printf("-1");
		return 0;
	}

	for(int i=0;i<=9;i++)dp[i][1]=1;
	for(int len=1;len<=9;len++){
		for(int start=len-1;start<=9;start++){
			for(int ns=start+1;ns<=9;ns++){
				dp[ns][len+1]+=dp[start][len];
			}
		}
	}

	dp_sum[0][1]=1;
	for(int len=1;len<=10;len++){;
		for(int start=1;start<=9;start++){
			dp_sum[start][len]=dp_sum[start-1][len]+dp[start][len];
		}
	}

	sum[0] = dp_sum[9][0];
	for(int len = 1; len<=10; len++){
		sum[len]=sum[len-1]+dp_sum[9][len];
		if(sum[len]>=N && ans_len == -1)ans_len=len;
	}

	N-=sum[ans_len-1];
	while(ans_len){
		if(ans_len==1){
			ans = ans*10+N-1;
			break;
		}
		for(int start=1;start<=9;start++){
			if(dp_sum[start][ans_len] >= N){
				N-=dp_sum[start-1][ans_len];
				ans=ans*10+start;
				ans_len--;
				break;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}