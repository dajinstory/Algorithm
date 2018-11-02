#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

stack<int> myS;
char str[34];

int main(){
	int len, bp = 0, num, top;
	scanf(" %s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] == '('){
			myS.push(-2);
		}
		else if (str[i] == '['){
			myS.push(-3);
		}
		else{
			if (str[i] == ')'){
				num = 2;
			}
			else if (str[i] == ']'){
				num = 3;
			}
			top = 0;
			while (!myS.empty() && myS.top() > 0){
				top += myS.top();
				myS.pop();
			}
			if (myS.empty() || myS.top() != -num){
				bp = 1;
				break;
			}
			if (top == 0){
				top = 1;
			}
			myS.pop();
			myS.push(top*num);
		}
	}
	if (bp){
		printf("0");
	}
	else{
		int re = 0;
		while (!myS.empty()){
			re += myS.top();
			myS.pop();
		}
		printf("%d", re);
	}
	return 0;
}