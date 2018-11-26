#include <stdio.h>
int main(){
	int T, N;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		while (N % 2 == 0){
			N /= 2;
		}
		if (N>1){
			printf("Gazua\n");
		}
		else{
			printf("GoHanGang\n");
		}
	}
	return 0;
}