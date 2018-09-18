#include <stdio.h>
#include <deque>
using namespace std;

int arr[1004];
deque<int> myD;

int main(){
	int T, N, MIN;
	char tmp;
	scanf("%d", &T);
	while (T--){
		MIN = 987654321;
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf(" %c", &tmp);
			arr[i] = tmp - 'A';
		}
		for (int i = 0; i < N; i++){
			if (arr[i] <= MIN){
				MIN = arr[i];
				myD.push_front(arr[i]);
			}
			else{
				myD.push_back(arr[i]);
			}
		}
		while (!myD.empty()){
			printf("%c", myD.front() + 'A');
			myD.pop_front();
		}
		printf("\n");
	}
	return 0;
}