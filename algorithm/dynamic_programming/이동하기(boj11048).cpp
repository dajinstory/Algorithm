#include <stdio.h>
#define MAX(A,B)((A)>(B) ? (A):(B))

int N,M;
int map[1004][1004];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&map[i][j]);
			map[i][j] += MAX(map[i-1][j], map[i][j-1]);
		}
	}
	printf("%d",map[N][M]);
	return 0;
}