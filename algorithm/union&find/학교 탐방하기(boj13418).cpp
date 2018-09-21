#include <stdio.h>
#include <vector>
using namespace std;


int parent[1004][2];

int getRoot(int child, int type){
	if (child != parent[child][type]){
		return parent[child][type] = getRoot(parent[child][type], type);
	}
	return child;
}
int main(){
	int N, M, A, B, C, num0, num1;
	scanf("%d%d", &N, &M);
	num0 = 0;
	num1 = N;
	for (int i = 0; i <= N; i++){
		parent[i][0] = i;
		parent[i][1] = i;
	}
	for (int i = 0; i <= M; i++){
		scanf("%d%d%d", &A, &B, &C);
		if (getRoot(A, C) != getRoot(B, C)){
			parent[getRoot(A,C)][C] = getRoot(B,C);
			if (C == 1){
				num1--;
			}
			else{
				num0++;
			}
		}
	}


	//printf("%d %d\n", num0, num1);
	printf("%d", num0*num0 - num1*num1);
	return 0;
}