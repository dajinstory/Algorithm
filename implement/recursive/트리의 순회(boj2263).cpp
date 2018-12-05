#include <stdio.h>
int in[100001];
int post[100001];
int tree[100001][2];

void tracking(int s1, int e1, int s2, int e2){
	int div, child1, child2;
	if (s1 == e1){
		printf("%d ", post[e2]);
		return;
	}
	else if (s1 > e1)return;
	printf("%d ", post[e2]);
	for (int i = s1; i <= e1; i++){
		if (in[i] == post[e2]){
			div = i;
			break;
		}
	}
	//in postorder
	child1 = s2 + div - 1 - s1;
	child2 = e2 - 1;
	tree[e2][0] = child1;
	tree[e2][1] = child2;
	if (child1 == child2)tree[e2][1] = 0;

	tracking(s1, div - 1, s2, child1);
	tracking(div + 1, e1, child1+1, child2);
}
void printPreorder(int root){
	if (root == 0)return;
	printf("%d ", post[root]);
	printPreorder(tree[root][0]);
	printPreorder(tree[root][1]);
}
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &in[i]);
	}
	for (int i = 1; i <= N; i++){
		scanf("%d", &post[i]);
	}
	tracking(1, N, 1, N);
//	printPreorder(N);
	return 0;
}