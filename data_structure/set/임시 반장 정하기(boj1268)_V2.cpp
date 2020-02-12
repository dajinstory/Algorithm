#include <stdio.h>
int classroom[1000][5];
int re[1000];

int main(){
	int N, max = 0, max_idx = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 5; j++){
			scanf("%d", &classroom[i][j]);
		}
		for (int j = i - 1; j >= 0; j--){
			if (classroom[i][0] == classroom[j][0] || classroom[i][1] == classroom[j][1] || classroom[i][2] == classroom[j][2] || classroom[i][3] == classroom[j][3] || classroom[i][4] == classroom[j][4]){
				re[i]++;
				re[j]++;
			}
		}
	}
	for (int i = 0; i < N; i++){
		if (re[i] > max){
			max = re[i];
			max_idx = i + 1;
		}
	}
	printf("%d", max_idx);
	return 0;
}