#include <stdio.h>
#include <string.h>

char str[1000004];
int alpha[26];
int main(){
	int len, max_idx = 0, cnt = 0;;
	scanf(" %s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++){
		alpha[(str[i] - 'A') % 32]++;
	}
	for (int i = 0; i < 26; i++){
		if (alpha[i] > alpha[max_idx]){
			max_idx = i;
			cnt = 1;
		}
		else if (alpha[i] == alpha[max_idx]){
			cnt++;
		}
	}
	if (cnt > 1)printf("?");
	else printf("%c", 'A' + max_idx);
	return 0;
}