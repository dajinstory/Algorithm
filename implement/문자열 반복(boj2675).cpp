#include <stdio.h>
#include <string.h>

int main(){
	int T, n;
	char str[24];

	scanf("%d", &T);
	while (T--){
		scanf("%d %s", &n, str);
		for (int i = 0; i < strlen(str); i++){
			for (int j = 0; j < n; j++){
				if (str[i] == '\\'){
					printf("\\");
				}
				else{
					printf("%c", str[i]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}