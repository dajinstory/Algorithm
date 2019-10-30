#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> heights;

char map[54][54];
int mapH[54][54];
bool visit[54][54];
int xx[8]={1,1,1,0,0,-1,-1,-1};
int yy[8]={1,0,-1,1,-1,1,0,-1};

int minH, maxH, minIdx, maxIdx;
int si, sj, cnt;
int N, ans=1000000;

int dfs(int x, int y, int minH, int maxH){	
	int re=0;
	visit[x][y]=true;
	if(map[x][y]=='K')re++;
	for(int k=0;k<8;k++){
		int nx=x+xx[k];
		int ny=y+yy[k];			
		if(mapH[nx][ny]<minH || mapH[nx][ny]>maxH)continue;
		if(!visit[nx][ny]){
			re+= dfs(nx,ny,minH,maxH);
		}
	}
	return re;
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
			scanf("%d",&mapH[i][j]);
		}
	}

	// setting variables	
	minH=1000000, maxH=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			heights.push_back(mapH[i][j]);
			if(map[i][j]=='P' || map[i][j]=='K'){
				map[i][j]='K';
				if(mapH[i][j]<minH)minH=mapH[i][j];
				if(mapH[i][j]>maxH)maxH=mapH[i][j];
				si=i, sj=j, cnt++;
			}
		}
	}
	sort(heights.begin(), heights.end());
	minIdx = lower_bound(heights.begin(), heights.end(), minH)-heights.begin();
	maxIdx = lower_bound(heights.begin(), heights.end(), maxH+1)-heights.begin()-1;

	//solve
	for(int idx_l=0, idx_r=maxIdx ; idx_l<=minIdx && idx_r<N*N && idx_l<=idx_r;){
        memset(visit,0,sizeof(visit));
		if(cnt == dfs(si, sj, heights[idx_l], heights[idx_r])){
			if(heights[idx_r] - heights[idx_l] < ans){
				ans=heights[idx_r] - heights[idx_l];
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