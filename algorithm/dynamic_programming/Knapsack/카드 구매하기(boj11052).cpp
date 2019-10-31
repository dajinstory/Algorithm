#include <stdio.h>
#define MAX(A,B)((A)>(B) ? (A):(B))
int cost[1004];
bool fix[1004];
int N;

int getDP(int idx){
	if(fix[idx])return cost[idx];
	fix[idx]=true;
	for(int i=1;i<=idx/2;i++){
		cost[idx]=MAX(getDP(idx), getDP(i)+getDP(idx-i));
	}
	return cost[idx];
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&cost[i]);
	}
	printf("%d",getDP(N));
	return 0;
}