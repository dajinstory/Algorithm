#include <stdio.h>
#include <stack>
#define MAX_N 20004
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
using namespace std;
typedef struct Point{
	int x;
	int y;
}Point;

Point arr[MAX_N];
Point original[MAX_N];
int visit[MAX_N];
stack<int> myS;
int N;

void work(int x, int y, int now, int plus, int maxY);
int solve(int x, int y);
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &original[i].x, &original[i].y);
	}

	for (int tc = 0; tc < 5; tc++){
		int x, y;
		scanf("%d%d", &x, &y);
		if (solve(x, y)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}

void work(int x, int y, int now, int plus, int maxY){
	int start = now, next;
	start %= N;
	now %= N;
	printf("\nnow =%d\n", now);
	do{
		next = (now + plus + N) % N;
		//올라가는 모양이고, x왼쪽에 있다.
		if (arr[now].y < arr[next].y && arr[now].x < x){
			//최대제한보다 낮은위치에 있다.
			if (arr[next].y < maxY){
				maxY = arr[next].y;
				while (!myS.empty() && arr[myS.top()].y < maxY){
					printf("pop %d\n", myS.top());
					myS.pop();
				}
			}
		}
		if (arr[next].y <= maxY && arr[next].y >= y && arr[next].x <= x){
			printf("push %d\n", next);
			myS.push(next);
		}
		now = next;
	} while (now != start);
	while (!myS.empty()){
		visit[myS.top()] = 1;
		myS.pop();
	}
	for (int i = 0; i < N; i++){
		printf("%d ", visit[i]);
	}
	printf("\n");
}


int solve(int x, int y){
	int min_x = -1, min_y = -1, max_x = 987654321, max_y = 987654321;
	int min_x_idx = -1, min_y_idx = -1, max_x_idx = -1, max_y_idx = -1;
	//get the closest line
	for (int i = 0; i < N; i++){
		visit[i] = 0;
		Point now, next;
		now = original[i], next = original[(i + 1) % N];
		if (now.x == next.x){
			if (MIN(now.y, next.y) < y && y < MAX(now.y, next.y)){
				if (now.y > next.y && now.x <= x){
					if (now.x >= min_x){
						min_x_idx = i;
						min_x = now.x;
					}
				}
				else if (now.y < next.y && now.x >= x){
					if (now.x <= max_x){
						max_x_idx = i;
						max_x = now.x;
					}
				}
			}
		}
		else{
			if (MIN(now.x, next.x) < x && x < MAX(now.x, next.x)){
				if (next.x > now.x && now.y <= y){
					if (now.y >= min_y){
						min_y_idx = i;
						min_y = now.y;
					}
				}
				else if (next.x < now.x && now.y >= y){
					if (now.y <= max_y){
						max_y_idx = i;
						max_y = now.y;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", min_x_idx, min_y_idx, max_x_idx, max_y_idx);
	for (int i = 0; i < N; i++){
		arr[i] = original[i];
	}
	work(x, y, max_y_idx, 1, max_y);
	for (int i = 0; i < N; i++){
		arr[i].x = -arr[i].x;
	}
	work(-x, y, max_y_idx + 1, -1, max_y);
	for (int i = 0; i < N; i++){
		arr[i].y = -arr[i].y;
	}
	work(-x, -y, min_y_idx, 1, -min_y);
	for (int i = 0; i < N; i++){
		arr[i].x = -arr[i].x;
	}
	work(x, -y, min_y_idx + 1, -1, -min_y);
	
	//y=x 대칭
	for (int i = 0; i < N; i++){
		arr[i].x = original[i].y;
		arr[i].y = original[i].x;
	}
	work(y, x, max_x_idx + 1, -1, max_x);
	for (int i = 0; i < N; i++){
		arr[i].x = -arr[i].x;
	}
	work(-y, x, max_x_idx, 1, max_x);
	for (int i = 0; i < N; i++){
		arr[i].y = -arr[i].y;
	}
	work(-y, -x, min_x_idx + 1, -1, -min_x);
	for (int i = 0; i < N; i++){
		arr[i].x = -arr[i].x;
	}
	work(y, -x, min_x_idx, 1, -min_x);
	
	int sum = 0;
	for (int i = 0; i < N; i++){
		sum += visit[i];
	}
	for (int i = 0; i < N; i++){
		printf("%d ", visit[i]);
	}
	printf("\n");
	if (sum == N){
		return 1;
	}
	else{
		return 0;
	}
}