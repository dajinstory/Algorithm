#include <stdio.h>
int main(){
	int T, N;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		if (N > 6)printf("1\n");
		else if (N == 5) printf("1\n");
		else if (N == 4) printf("2\n");
		else printf("0\n");
	}
	return 0;
}