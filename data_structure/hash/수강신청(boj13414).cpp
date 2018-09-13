#include <stdio.h>
#include <unordered_map>
using namespace std;

int arr[500001];
unordered_map<int, int> clk;

int main(){
	int K, L;
	scanf("%d%d", &K, &L);
	for (int i = 0; i < L; i++){
		scanf("%d", &arr[i]);
		clk[arr[i]] = i;
	}
	for (int i = 0; i < L && K; i++){
		if (clk[arr[i]] == i){
			printf("%08d\n", arr[i]);
			K--;
		}
	}
	return 0;
}