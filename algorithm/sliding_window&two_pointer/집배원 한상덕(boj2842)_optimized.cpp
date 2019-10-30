#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MIN(A,B) (((A)<(B)) ? (A) : (B) )
#define MAX(A,B) (((A)>(B)) ? (A) : (B) )
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

			if(maph[ni][nj]<min_height||maph[ni][nj]>max_height){
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

int get_min_idx(int si, int sj, int max_height, int idx_l, int idx_r){
	while(idx_l<=idx_r){
		int idx_mid=(idx_l+idx_r)/2;
		if(bfs(si,sj,heights[idx_mid],max_height)){
			idx_l=idx_mid+1;
		}
		else{
			idx_r=idx_mid-1;
		}
	}
	return idx_r;
}
int get_max_idx(int si, int sj, int min_height, int idx_l, int idx_r){
	int idx_bound = idx_r;
	while(idx_l<=idx_r){
		int idx_mid=(idx_l+idx_r)/2;
		if(bfs(si,sj,min_height,heights[idx_mid])){
			idx_r=idx_mid-1;
		}
		else{
			idx_l=idx_mid+1;
		}
	}
	if(idx_l>idx_bound)return idx_bound;
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
	int idx_l,idx_r,idx_min,idx_max;
	int ans=1000000;
	int tmp;

	idx_l = lower_bound(heights.begin(), heights.end(), P[0].first)-heights.begin();
	idx_r = lower_bound(heights.begin(), heights.end(), P[P.size()-1].first)-heights.begin();
	idx_min = get_min_idx(start_i,start_j,P[P.size()-1].first, 0,idx_l);
	idx_max = get_max_idx(start_i,start_j,P[0].first, idx_r,N*N-1);
	if(idx_min)
	if(idx_min==-1)idx_max++;
	if(idx_max==N*N)idx_max--;
	for(idx_l=idx_min, idx_r; heights[idx_l]<=P[0].first && idx_r<=idx_max && idx_l<=idx_r; ){
		if(bfs(start_i,start_j,heights[idx_l],heights[idx_r])){
			if(heights[idx_r]-heights[idx_l]<ans){
				ans=heights[idx_r]-heights[idx_l];
			}
			idx_l++;
		}
		else{
			idx_r++;
		}
	}
	printf("%d",ans);
	return 0;
}