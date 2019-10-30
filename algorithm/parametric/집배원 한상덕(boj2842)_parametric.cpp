#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;

char map[54][54];
int maph[54][54];
int visit[54][54];
vector<int> heights;
vector< pair< int, pair<int,int> > > P;
queue< pair<int,int> > myQ;

int bfs(int si, int sj, int min_height, int max_height){
	int xx[8]={1,1,1,0,0,-1,-1,-1};
	int yy[8]={1,0,-1,1,-1,1,0,-1};
	int rests=P.size();

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			visit[i][j]=0;
		}
	}

	visit[si][sj]=1;
	myQ.push(make_pair(si,sj));
	rests--;
	while(!myQ.empty()){
		int i,j;
		i=myQ.front().first;
		j=myQ.front().second;
		myQ.pop();
		for(int k=0;k<8;k++){
			int ni,nj;
			ni=i+xx[k];
			nj=j+yy[k];

			if(ni<1||nj<1||ni>N||nj>N||maph[ni][nj]<min_height||maph[ni][nj]>max_height){
				continue;
			}

			if(!visit[ni][nj]){
				visit[ni][nj]=1;
				myQ.push(make_pair(ni,nj));
				if(map[ni][nj]=='P' || map[ni][nj]=='K'){
					rests--;
				}
			}
		}
		while( !rests && !myQ.empty()){
			myQ.pop();
		}
	}
	return rests==0;
}

int parametric_search(int si, int sj, int min_height, int idx_l, int idx_h){
	while(idx_l<=idx_h){
		int idx_mid=(idx_l+idx_h)/2;
		if(bfs(si,sj,min_height,heights[idx_mid])){
			idx_h=idx_mid-1;
		}
		else{
			idx_l=idx_mid+1;
		}
	}
	return idx_l;
}

int main(){

	//input
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&maph[i][j]);
			heights.push_back(maph[i][j]);
			if(map[i][j]=='P' || map[i][j]=='K'){
				P.push_back(make_pair(maph[i][j], make_pair(i,j)));
			}
		}
	}

	//solve
	sort(P.begin(), P.end());
	sort(heights.begin(), heights.end());
	int start_i = P[0].second.first;
	int start_j = P[0].second.second;
	int idx_start=lower_bound(heights.begin(), heights.end(), P[0].first)-heights.begin();
	int idx_l=lower_bound(heights.begin(), heights.end(), P[P.size()-1].first)-heights.begin();
	int ans=1000000;
	int idx_h=N*N-1;
	for(int i=idx_start; i>=0; i--){
		idx_h = parametric_search(start_i, start_j, heights[i], idx_l, idx_h);
		if(idx_h==N*N){
			idx_h=N*N-1;
			continue;
		}
		if(idx_h<idx_l)idx_h=idx_l;
		if(idx_h==-1) break;
		
		if(heights[idx_h]-heights[i]<ans)ans=heights[idx_h]-heights[i];

		if(heights[idx_h]==heights[idx_l])break;
	}
	printf("%d",ans);
	return 0;
}