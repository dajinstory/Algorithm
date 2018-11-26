#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100000
int arr[MAX_N], brr[MAX_N];
int main(){
	int N, score = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
        if(arr[i]<0||arr[i]>100000){
            return 0;
        }
	}
	for (int i = 0; i < N; i++){
		scanf("%d", &brr[i]);
        if(brr[i]<0||brr[i]>100000){
            return 0;
        }
	}
	sort(arr, arr + N);
	sort(brr, brr + N);
	for (int i = 0, j = 0; i < N && j < N;){
		if (arr[i] < brr[j]){
			score++;
			i++, j++;
		}
		else{
			j++;
		}
	}
	if (score >= (N + 1) / 2){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}