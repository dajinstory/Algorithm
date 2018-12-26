#include <stdio.h>
#include <algorithm>
using namespace std;

int relation[501][501]; // i is higher priority than j
pair<int,int> score[501];
int num[501];
int main(){
	int T, N, M, bp;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++){
			scanf("%d", &num[i]);
			score[num[i]] = make_pair(i, num[i]);
		}
		for (int i = 1; i <= N; i++){
			for (int j = 1; j < i; j++){
				relation[num[j]][num[i]] = 1;
			}
			for (int j = i; j <= N; j++){
				relation[num[j]][num[i]] = 0;
			}
		}
		bp = 0;
		scanf("%d", &M);
		for (int i = 0; i < M; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if (relation[b][a] != 1){
				//bp = 1;
				//continue;
				int tmp = a;
				a = b;
				b = tmp;
			}
			score[a].first--;
			score[b].first++;
		}
		sort(score + 1, score + N + 1);
		//printf("bp = %d", bp);
		for (int i = 1; i <= N; i++){
			if (score[i].first != i){
				bp = 1;
				break;
			}
		}
		//printf("ANSWER = ");
		if (bp)printf("IMPOSSIBLE\n");
		else{
			for (int i = 1; i <= N; i++){
				printf("%d ", score[i].second);
			}
			printf("\n");
		}
	}
	return 0;
}