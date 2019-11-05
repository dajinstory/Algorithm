#include <stdio.h>
#include <vector>
using namespace std;

int V[104];
int visit[104][1004];
vector<int> vs[104];
int N,S,M, ans=-1;

int main(){
	scanf("%d%d%d",&N,&S,&M);
	for(int i=1;i<=N;i++) scanf("%d",&V[i]);

	vs[0].push_back(S);
	for(int i=1;i<=N;i++){
		for(int j=0;j<vs[i-1].size();j++){
			int vb, vn;
			vb=vs[i-1][j];
			vn=vb-V[i];
			if(vn>=0 && !visit[i][vn]){
				visit[i][vn]=1;
				vs[i].push_back(vn);
			}
			vn=vb+V[i];
			if(vn<=M && !visit[i][vn]){
				visit[i][vn]=1;
				vs[i].push_back(vn);
			}
		}
	}
	for(int i=0;i<vs[N].size();i++){
		if(ans<vs[N][i])ans=vs[N][i];
	}
	printf("%d",ans);
	return 0;
}