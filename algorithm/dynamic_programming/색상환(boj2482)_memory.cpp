#include <stdio.h>
#include <vector>
#define MAXN 1001
using namespace std;

bool Nsosu[MAXN];
int muls[200];
vector<int> sosu;
int N, K, MOD=1000000003;
int ans=0;

void make_sosu();
void combH(int n, int r);
void calc();

int main(){
	scanf("%d%d",&N,&K);
	if(K*2<=N){
		make_sosu();
		combH(K,N-2*K);
		calc();
		combH(K+1,N-2*K);
		calc();
	}
	printf("%lld", ans);
	return 0;
}


void make_sosu(){
	// make sosu
	for(int i=2;i<MAXN;i++){
		if(!Nsosu[i]){
			sosu.push_back(i);
			for(int j=i*i;j<MAXN;j+=i){
				Nsosu[j]=true;
			}
		}
	}
}
void combH(int n, int r){
	n=n+r-1;
	for(int i=0;i<r;i++){
		int num=n-i;
		for(int j=0;j<sosu.size();j++){
			while(num>1 && num%sosu[j]==0){
				num/=sosu[j];
				muls[j]++;
			}
		}
		num=i+1;
		for(int j=0;j<sosu.size();j++){
			while(num>1 && num%sosu[j]==0){
				num/=sosu[j];
				muls[j]--;
			}
		}
	}
}
void calc(){
	long long tmp=1;
	for(int i=0;i<sosu.size();i++){
		while(muls[i]>0){
			tmp=(tmp*sosu[i])%MOD;
			muls[i]--;
		}
	}
	ans=(ans+tmp)%MOD;
}