#include <stdio.h>
int map[1004];
int check[1004];
int main(){
	int N, T;
	scanf("%d", &T);
	while (T--){
		int cycle = 0, now;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++){
			scanf("%d", &map[i]);
			check[i] = 0;
		}
		for (int i = 1; i <= N; i++){
			if (!check[i]){
				cycle++;
				now = i;
				while (!check[now]){
					check[now] = 1;
					now = map[now];
				}
			}
		}
		printf("%d\n", cycle);
	}
	return 0;
}