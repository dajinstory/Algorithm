#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

stack<int> myS;
char input[31];
int len;

int check_error(void){
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < len; i++){
		if (input[i] == '(')cnt1++;
		else if (input[i] == ')')cnt1--;
		else if (input[i] == '[')cnt2++;
		else cnt2--;
		if (cnt1 < 0 || cnt2 < 0){
			return 1;
		}
	}
	if (cnt1 != 0 || cnt2 != 0){
		return 1;
	}
	return 0;
}
int main(){
	scanf(" %s", input);
	len = strlen(input);
	if (check_error()){
		printf("0");
		return 0;
	}
	for (int i = 0; i < len; i++){
		if (input[i] == '('){
			myS.push(-1);
		}
		else if (input[i] == '['){
			myS.push(-2);
		}
		else{
			int num, check;
			if (input[i] == ')'){
				num = 2;
				check = -1;
			}
			else{
				num = 3;
				check = -2;
			}
			if (myS.top() == check){
				myS.pop();
				myS.push(num);
			}
			else if (myS.top() > 0){
				num *= myS.top();
				myS.pop();
				if (myS.top() == check){
					myS.pop();
					myS.push(num);
				}
				else{
					printf("0");
					return 0;
				}
			}
			else{
				printf("0");
				return 0;
			}
			num = myS.top();
			myS.pop();
			if (!myS.empty() && myS.top() > 0){
				num += myS.top();
				myS.pop();
			}
			myS.push(num);
		}
	}
	printf("%d", myS.top());
	return 0;
}