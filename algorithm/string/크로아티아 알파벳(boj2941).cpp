#include <stdio.h>  
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//종륜줄 알았는데 전체 개수였네.
int visit[40];
char str[104];
int main(){
	int len, ans = 0;
	scanf(" %s", str);
	len = strlen(str);
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == '='){
			if (str[i - 1] == 'c'){
				//c=
				visit[30]++;
				i -= 1;
			}
			else if (str[i - 1] == 's'){
				//s=
				visit[31]++;
				i -= 1;
			}
			else if (i - 2 >= 0 && str[i - 2] == 'd'){
				//dz=
				visit[32]++;
				i -= 2;
			}
			else{
				//ze
				visit[33]++;
				i -= 1;
			}
		}
		else if (str[i] == '-'){
			if (str[i - 1] == 'c'){
				//c-
				visit[34]++;
				i -= 1;
			}
			else{
				//d-
				visit[35]++;
				i -= 1;
			}
		}
		else if (i>0 && str[i] == 'j'){
			if (str[i - 1] == 'l'){
				//lj
				visit[36]++;
				i -= 1;
			}
			else if (str[i - 1] == 'n'){
				//nj
				visit[37]++;
				i -= 1;
			}
			else{
				//알파벳 j
				visit[str[i] - 'a']++;
			}
		}
		else{
			visit[str[i] - 'a']++;
		}
	}
	for (int i = 0; i < 40; i++){
		ans += visit[i];
	}
	printf("%d", ans);
	return 0;
} 