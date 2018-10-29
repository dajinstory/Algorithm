#include <stdio.h>
#include <stack>
using namespace std;

stack<int> myS;
int re[200004];
int main(){
	int N, num, now = 1, order = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		for (now; now <= num; now++){
			myS.push(now);
			re[order] = 1;
			order++;
		}
		if (myS.top() != num){
			printf("NO\n");
			return 0;
		}
		else{
			myS.pop();
			re[order] = -1;
			order++;
		}
	}
	for (int i = 0; i < order; i++){
		if (re[i] == 1)printf("+\n");
		else printf("-\n");
	}
	return 0;
}