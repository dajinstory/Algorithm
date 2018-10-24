#include <stdio.h>
#include <math.h>

int solve(int);
int main(){
	int T, num, tmp;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &tmp, &num);
		num -= tmp;
		printf("%d\n", solve(num));
	}
	return 0;
}
int solve(int num){
	if (num < 4)return num;
	int ans = (int)(sqrt((double)(num - 1)) / 1);
	if (num > ans*ans + ans)return 2 * ans + 1;
	else return 2 * ans;
}