#include <stdio.h>

int score[1004];
int main(){
	int T, N, sum, num;
	double avg;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);

		sum = 0, num = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &score[i]);
			sum += score[i];
		}
		avg = ((double)sum) / N;
		for (int i = 0; i < N; i++){
			if (((double)score[i])>avg){
				num++;
			}
		}
		printf("%.3lf%%\n", ((double)num) / N * 100);
	}
	return 0;
}