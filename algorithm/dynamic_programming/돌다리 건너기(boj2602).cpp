#include <stdio.h>
#include <string.h>
typedef long long ll;

char key[24];
char arr[2][104];
ll dp[2][104][24];
int keylen, len;
ll ans;

int main(){
	scanf(" %s", key+1);
	scanf(" %s", arr[0]+1);
	scanf(" %s", arr[1]+1);
	
	keylen=strlen(key+1);
	len=strlen(arr[0]+1);

	dp[0][0][0]=dp[1][0][0]=1;
	for(int i=0;i<=len;i++){
		for(int check=0;check<keylen;check++){
			for(int p=0;p<2;p++){
				//printf("%d %d %d %d\n", p, i, check, dp[p][i][check]);

				int np=1-p;
				for(int j=i+1;j<=len;j++){
					if(arr[np][j]==key[check+1]){
						//printf(">>%d %d %d\n", np, j, check+1);
						dp[np][j][check+1]+=dp[p][i][check];
					}
				}
			}
		}
		for(int p=0;p<2;p++) ans+=dp[p][i][keylen];
	}
	printf("%lld", ans);
	
	return 0;
}