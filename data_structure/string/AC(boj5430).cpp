#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

deque<int> myD;
char order[100004];
char input[400004];

void parse(int n);
int solve(int len, int N);
void answer(int type);
int main(){
	int T, len, N, re;
	scanf("%d", &T);
	while (T--){
		scanf(" %s", order);
		len = strlen(order);
		scanf("%d", &N);
		scanf(" %s", input);

		parse(N);
		re = solve(len, N);
		answer(re);
	}
	return 0;
}
void parse(int n){
	int len = strlen(input), idx = 0, num = 0;
	if (n == 0) return;
	for (int i = 1; i < len-1; i++){
		if (input[i] == ','){
			myD.push_back(num);
			idx++;
			num = 0;
		}
		else{
			num *= 10;
			num += input[i] - '0';
		}
	}
	myD.push_back(num);
}
int solve(int len, int N){
	int dir = 1;
	for (int i = 0; i < len; i++){
		if (order[i] == 'R'){
			dir *= -1;
		}
		else{
			N--;
			if (N < 0)return 0;

			if (dir == 1){
				myD.pop_front();
			}
			else{
				myD.pop_back();
			}
		}
	}
	return dir;
}
void answer(int type){
	if (type == 0){
		printf("error\n");
	}
	else if (type == 1){
		printf("[");
		if (myD.empty()){
			printf("]\n");
			return;
		}
		printf("%d", myD.front());
		myD.pop_front();
		while (!myD.empty()){
			printf(",%d", myD.front());
			myD.pop_front();
		}
		printf("]\n");
	}
	else{
		printf("[");
		if (myD.empty()){
			printf("]\n");
			return;
		}
		printf("%d", myD.back());
		myD.pop_back();
		while (!myD.empty()){
			printf(",%d", myD.back());
			myD.pop_back();
		}
		printf("]\n");
	}
}
