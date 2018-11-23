#include <stdio.h>
int main(){
	int N, re = 1;
	scanf("%d", &N);
	while (N--){
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == re){
			re = b;
		}
		else if (b == re){
			re = a;
		}
	}
	printf("%d", re);
	return 0;
}