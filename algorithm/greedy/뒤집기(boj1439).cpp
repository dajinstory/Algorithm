#include <stdio.h>
#include <string.h>
char str[1000001];
int main(){
	int cnt = 1, len;
	char cmp;
	scanf("%s", str);

	len = strlen(str), cmp = str[0];
	for (int i = 1; i < len; i++){
		if (str[i] != cmp){
			cmp = str[i];
			cnt++;
		}
	}
	printf("%d", cnt / 2);
	return 0;
}