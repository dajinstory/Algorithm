#include <stdio.h>
#define MAX_N 20004
using namespace std;

typedef struct Spot{
	int x;
	int y;
}Spot;

int N;
Spot arr[MAX_N];
int pre[4][2] = { 3, 4, 0, 5, 1, 6, 2, 7 };

int solve(int x, int y);
int getArea(int x, int y, int idx);
int rotate(int now, int next);

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &arr[i].x, &arr[i].y);
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

int solve(int x, int y){
	int start, now, next, spin;
	int area, next_area;
	for (start = 0; start < N; start++){
		if (getArea(x, y, start) < 4){
			break;
		}
	}

	area = getArea(x, y, start);
	now = start;
	if (pre[area][0] == getArea(x, y, (start - 1 + N) % N) || pre[area][1] == getArea(x, y, (start - 1 + N) % N)){
		spin = 0;
	}
	else{
		spin = -1;
	}

//	printf("start, spin, area = %d, %d, %d\n", start, spin, area);
	do{
		next = (now + 1) % N;
		next_area = getArea(x, y, next);
		spin += rotate(now, next);
		if (next_area < 4){
			spin -= (next_area - area + 4) % 4;
			area = next_area;
		}
//		printf("%d %d, %d\n", arr[next].x, arr[next].y, spin);

		if ((spin < -1 || spin>2)){
			if (getArea(x, y, next) < 4 || getArea(x, y, now) < 4 || getArea(x, y, (now - 1 + N) % N) < 4){
				return 0;
			}
			spin -= 4;
		}
		now = next;
	} while (now != start);
	return 1;
}

int getArea(int x, int y, int idx){
	if (arr[idx].x > x){
		if (arr[idx].y > y){
			return 0;
		}
		else if (arr[idx].y < y){
			return 3;
		}
		else{
			return 4;
		}
	}
	else if (arr[idx].x < x){
		if (arr[idx].y > y){
			return 1;
		}
		else if (arr[idx].y < y){
			return 2;
		}
		else{
			return 6;
		}
	}
	else{
		if (arr[idx].y > y){
			return 5;
		}
		else if (arr[idx].y < y){
			return 7;
		}
		else{
			return 8;
		}
	}
}

int rotate(int now, int next){
	int before = (now - 1 + N) % N;
	int x1, x2, y1, y2;
	x1 = arr[now].x - arr[before].x;
	y1 = arr[now].y - arr[before].y;
	x2 = arr[next].x - arr[now].x;
	y2 = arr[next].y - arr[now].y;
	if (x1*y2 - x2*y1 > 0){
		return 1;
	}
	else{
		return -1;
	}
}