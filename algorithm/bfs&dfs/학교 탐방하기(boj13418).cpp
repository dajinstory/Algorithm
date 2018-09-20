#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue<int> myQ;
queue<int> myQ2;
vector<int> map[1004][2];
int check[1004][2];

int main(){
	int N, M, A, B, C, num = 0, num2 = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= M; i++){
		scanf("%d%d%d", &A, &B, &C);
		if (C == 1){
			map[A][0].push_back(B);
			map[B][0].push_back(A);
		}
		else{
			map[A][1].push_back(B);
			map[B][1].push_back(A);
		}
	}
	for (int i = 0; i <= N; i++){
		if (check[i][0] == 0){
			num++;
			myQ.push(i);
			while (!myQ.empty()){
				int now = myQ.front();
				myQ.pop();
				check[now][0] = num;
				for (int i = 0; i < map[now][0].size(); i++){
					if (check[map[now][0][i]][0] == 0){
						myQ.push(map[now][0][i]);
					}
				}
			}
		}
		if (check[i][1] == 0){
			num2++;
			myQ2.push(i);
			while (!myQ2.empty()){
				int now = myQ2.front();
				myQ2.pop();
				check[now][1] = num2;
				for (int i = 0; i < map[now][1].size(); i++){
					if (check[map[now][1][i]][1] == 0){
						myQ2.push(map[now][1][i]);
					}
				}
			}
		}
	}
	num -= 1;
	num2 = N + 1 - num2;
	//printf("%d %d\n", num, num2);
	printf("%d", num2*num2 - num*num);
	return 0;
}