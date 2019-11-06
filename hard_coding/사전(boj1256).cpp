#include <stdio.h>
typedef long long ll;

ll C[201][201];
ll zpos[103];
int N,M,K;
char ans[401];

int main(){
	scanf("%d%d%d",&N,&M,&K);

	for(int i=0;i<=N+M;i++){
		C[i][0]=C[i][i]=1;
		ans[i]='a';
	}
	for(int n=1;n<=N+M;n++){
		for(int r=1;r<n;r++){
			C[n][r]=C[n-1][r-1]+C[n-1][r];
		}
	}

	zpos[0]=0;
	for(int i=1;i<=M;i++){
		zpos[i]=N+i;
	}

	for(int i=1;i<=M;i++){
		ll subsum=0;
		for(int mv=0;zpos[i]-mv>zpos[i-1];mv++){
			int r = M-i;
			int n = r+mv;
			subsum+=C[n][r];
			if(subsum>=K){
				K-=(subsum-C[n][r]);
				zpos[i]-=mv;
				break;
			}
		}
	}
	if(K!=1){
		printf("-1");
		return 0;
	}

	for(int i=1;i<=M;i++)ans[zpos[i]]='z';
	printf("%s", ans+1);
	return 0;
}