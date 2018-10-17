#include <stdio.h>
#include <string.h>

char str[333334];
char ans[1000004];
int main(){
	int len, start = 0;;
	scanf("%s", str);
	len = strlen(str);
	
	for (int i = 0; i < len; i++){
		int tmp = str[i] - '0';
		ans[3 * i] = tmp / 4 + '0';
		tmp %= 4;
		ans[3 * i + 1] = tmp / 2 + '0';
		tmp %= 2;
		ans[3 * i + 2] = tmp + '0';
	}
	
	if (ans[0] == '0'){
		start = 1;
		if (ans[1] == '0'){
			start = 2;
		}
	}
	printf("%s", ans + start);
	return 0;
}