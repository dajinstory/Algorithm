#include <stdio.h>
#include <math.h>

int main(){
	int N, ans;
	scanf("%d", &N);
	ans = (int)sqrt((double)(N-1)/3);
	while (ans*(ans + 1) * 3 < N-1){
		ans++;
	}
	printf("%d", ans + 1);
	return 0;
}