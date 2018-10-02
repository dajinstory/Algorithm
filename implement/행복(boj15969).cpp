#include <stdio.h>
int main(){
	int N, min = 1004, max = 0, tmp;
	scanf("%d", &N);
	while (N--){
		scanf("%d", &tmp);
		if (tmp > max){
			max = tmp;
		}
		if (tmp < min){
			min = tmp;
		}
	}
	printf("%d", max - min);
	return 0;
}