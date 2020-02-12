#include <stdio.h>
#include <vector>
using namespace std;
int map[100004];
int N, M;
char answer[300004];

int q(int index) {
	int re = 0;
	while (index) {
		re += map[index];
		index -= index&-index;
	}
	return re;
}
void update(int index, int value) {
	while (index <= 100000) {
		map[index] += value;
		index += index&-index;
	}
}
void check() {
	for (int i = 1; i <= N; i++) {
		printf("%d ", q(i));
	}
	printf("\n");
}

int find_next_idx(int idx, int plus){
	int l=idx+1,r=N,m, plus_n;
	while(l<=r){
		m=(l+r)/2;
		plus_n=m-idx-(q(m)-q(idx));
		if(plus_n<plus){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return l;
}

int main() {

	scanf("%d%d", &N, &M);
	printf("<");
	for(int rest=N, idx=0;rest>0;rest--){
		int plus = (M-1)%rest+1;
		int plus_max = N-idx - (q(N)-q(idx));
		if(plus_max < plus){
			plus-=plus_max;
			idx=0;
		}

		idx = find_next_idx(idx, plus);
		update(idx,1);

		printf(((rest)>(1) ? "%d, ":"%d>"), idx);
		//check();
	}
	return 0;
}
