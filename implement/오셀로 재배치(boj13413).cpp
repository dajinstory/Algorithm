#include <stdio.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  

char arr[100004];
char ans[100004];
int main(){
	int T, N;
	int w, b;
	scanf("%d", &T);
	while (T--){
		w = 0; b = 0;
		scanf("%d", &N);
		scanf(" %s%s", arr, ans);
		for (int i = 0; i < N; i++){
			if (arr[i] != ans[i]){
				if (arr[i] == 'W'){
					w++;
				}
				else{
					b++;
				}
			}
		}
		printf("%d\n", w + b - MIN(w, b));
	}
	return 0;
}