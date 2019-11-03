#include <stdio.h>
#include <math.h>
int T,N;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d", &N);
		printf("%d\n", (int)sqrt(N));
	}
	return 0;
}