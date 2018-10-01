#include <stdio.h>
#include <string.h>
int main(){
	int T;
	char str[26];
	scanf("%d", &T);
	while (T--){
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i += 2){
			printf("%c", str[i]);
		}
		if (strlen(str) % 2 == 1){
			for (int i = 1; i < strlen(str); i += 2){
				printf("%c", str[i]);
			}
		}
		printf("\n");
		for (int i = 1; i < strlen(str); i += 2){
			printf("%c", str[i]);
		}
		if (strlen(str) % 2 == 1){
			for (int i = 0; i < strlen(str); i += 2){
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}