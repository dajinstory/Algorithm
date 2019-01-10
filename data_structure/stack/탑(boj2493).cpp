#include <stdio.h>
#include <stack>
using namespace std;

typedef struct node{
	int idx;
	int height;
}node;
stack<node>myS;
int ans[500001];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int h;
		scanf("%d", &h);
		while (!myS.empty() && myS.top().height < h) myS.pop();
		if (!myS.empty())ans[i] = myS.top().idx + 1;
		myS.push({ i, h });
	}
	for (int i = 0; i < N; i++)printf("%d ", ans[i]);
	return 0;
}