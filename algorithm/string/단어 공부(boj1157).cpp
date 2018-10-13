#include <stdio.h>
#include <string.h>
char str[1000004];
int arr[26];
int main(){
	int cnt = 0, max = 0, ans, idx, len;
	scanf(" %s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] > 'Z'){
			idx = str[i] - 'a';
		}
		else{
			idx = str[i] - 'A';
		}
		arr[idx]++;
		if (arr[idx] == max){
			cnt++;
		}
		else if (arr[idx] > max){
			cnt = 1;
			max = arr[idx];
			ans = idx;
		}
	}
	if (cnt > 1){
		printf("?");
	}
	else{
		printf("%c", ans + 'A');
	}
	return 0;
}