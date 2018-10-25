#include <stdio.h>
#include <algorithm>
#define MAX(A,B)(A>B?A:B)
using namespace std;


//4ms, 8ms, 48ms 이런분들은, IO에서 시간 더 줄인것!
int cnt[8001];
int main(){
	int N, sum = 0, idx = 0, mid=-4001, min = 4000, max = -4000, max_cnt = 0, cnt_num, max_idx;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int num;
		scanf("%d", &num);
		cnt[num + 4000]++;
		sum += num;
	}
	for (int i = 0; i <= 8000; i++){
		if (cnt[i]){
			max = i - 4000;
			if (min == 4000){
				min = i - 4000;
			}
			if (cnt[i] > max_cnt){
				cnt_num = 1;
				max_cnt = cnt[i];
				max_idx = i;
			}
			else if (cnt[i] == max_cnt && cnt_num == 1){
				cnt_num = 2;
				max_idx = i;
			}
			idx += cnt[i];
			if (mid == -4001 && idx >= (N + 1) / 2){
				mid = i - 4000;
			}
		}
	}

	printf("%.0lf\n%d\n%d\n%d", (double)sum / N, mid, max_idx - 4000, max-min);
	return 0;
}