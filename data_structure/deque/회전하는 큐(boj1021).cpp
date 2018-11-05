#include <stdio.h>
#include <deque>
#define MIN(A, B) ((A)<(B)?(A):(B))
using namespace std;

deque<int> myD;

int main(){
	int N, M, num, cnt, sum = 0;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++){
		myD.push_back(i);
	}
	for (int i = 0; i < M; i++){
		scanf("%d", &num);
		cnt = 0;
		while (myD.front() != num){
			myD.push_back(myD.front());
			myD.pop_front();
			cnt++;
		}
		myD.pop_front();
		sum += MIN(cnt, N - i - cnt);
	}
	printf("%d", sum);
	return 0;
}