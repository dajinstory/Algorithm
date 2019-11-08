#include <stdio.h>
#include <vector>
using namespace std;

int N,M,W;
vector<int> weights;
bool visit[120004];
int s=60000;

int main(){
	visit[s]=true;
	weights.push_back(s);

	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&W);
		int len=weights.size();
		for(int j=0;j<len;j++){
			int w=weights[j];
			if(w+W<=s*2 && !visit[w+W]){
				visit[w+W]=true;
				weights.push_back(w+W);
			}
			if(w-W>=0 && !visit[w-W]){
				visit[w-W]=true;
				weights.push_back(w-W);
			}
		}
	}
	scanf("%d",&M);
	while(M--){
		scanf("%d",&W);
		printf("%c ",visit[W+s]? 'Y':'N');
	}
	return 0;
}