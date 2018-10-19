#include <stdio.h>
#include <vector>
#define MAX(A, B) ((A)>(B)? (A):(B))
using namespace std;

typedef struct node{
	int x;
	int y;
	int r;
}node;

vector<node> order;

int solve(int x, int y);
int main(){
	int N, Q, query, a, b, c;
	scanf("%d%d", &N, &Q);
	while (Q--){
		scanf("%d", &query);
		if (query == 1){
			scanf("%d%d%d", &a, &b, &c);
			order.push_back({ a, b, c });
		}
		else{
			scanf("%d%d", &a, &b);
			printf("%d\n", solve(a, b));
		}
	}
	return 0;
}

int solve(int x, int y){
	int len = order.size(), re = 0, type;
	for (int i = 0; i < len; i++){
		int a = order[i].x - x;
		int b = order[i].y - y;
		type = 0;
		if (a < 0){
			a = -a;
			type++;
		}
		if (b < 0){
			b = -b;
			type++;
		}
		if (type % 2 == 0){
			if (order[i].r >= MAX(a, b)) re++;
		}
		else{
			if (order[i].r >= a + b)re++;
		}
	}
	return re;
}