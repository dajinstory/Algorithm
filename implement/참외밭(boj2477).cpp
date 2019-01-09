#include <stdio.h>
using namespace std;

int arr[7];
int getMax(int a, int b){
	if (a > b)return a;
	return b;
}
int main(){
	int C, idx1 = 6, idx2 = 6;
	scanf("%d", &C);
	for (int i = 0; i < 6; i++){
		int tmp;
		scanf("%d%d", &tmp, &arr[i]);
		if (i % 2 == 0 && arr[i] > arr[idx1]){
			idx1 = i;
		}
		else if (i % 2 == 1 && arr[i] > arr[idx2]){
			idx2 = i;
		}
	}
	printf("%d", (arr[idx1] * arr[idx2] - arr[(idx1 + 3) % 6] * arr[(idx2 + 3) % 6])*C);
	return 0;
}