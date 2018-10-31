#include <stdio.h>

int tree[4000][4000];
int max_x, max_y;

void update(int x, int y, int val); // val means the plus value.
int read(int x, int y); // return sum from 1,1 to x,y.
int getSum(int x1, int y1, int x2, int y2);

int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	max_x = max_y = 1024;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			int tmp;
			scanf("%d", &tmp);
			update(i, j, tmp);
		}
	}

	while (M--){
		int order, a, b, c, d;
		scanf("%d", &order);
		if (order == 0){
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c - getSum(a, b, a, b));
		}
		else{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			printf("%d\n", getSum(a, b, c, d));
		}
	}
	return 0;
}

void update(int x, int y, int val){
	int y1;
	while (x <= max_x){
		y1 = y;
		while (y1 <= max_y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}
int read(int x, int y){ // return sum from 1,1 to x,y.
	int sum = 0;
	while (x){
		int y1 = y;
		while (y1){
			sum += tree[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}

int getSum(int x1, int y1, int x2, int y2){
	return read(x2, y2) - read(x1 - 1, y2) - read(x2, y1 - 1) + read(x1 - 1, y1 - 1);
}
