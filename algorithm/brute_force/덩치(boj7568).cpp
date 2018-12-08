#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int> arr[54];
int rankk[54];
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d%d", &arr[i].first, &arr[i].second);
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			if ((arr[i].first - arr[j].first)*(arr[i].second - arr[j].second)>0){
				if (arr[i].first > arr[j].first){
					rankk[j]++;
				}
				else{
					rankk[i]++;
				}
			}
		}
		printf("%d ", rankk[i] + 1);
	}
	return 0;
}