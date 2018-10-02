#include <stdio.h>
#include <vector>
#include <algorithm>
#define MIN(A,B) ((A)<(B)?(A):(B))

using namespace std;
 
pair<int,int> arr[5004];
int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &arr[i].second, &arr[i].first);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		int tmp = 987654321;
		if (i - 1 >= 0 && arr[i - 1].first == arr[i].first){
			tmp = MIN(tmp, arr[i].second - arr[i - 1].second);
		}
		if (i + 1 < N && arr[i + 1].first == arr[i].first){
			tmp = MIN(tmp, arr[i + 1].second - arr[i].second);
		}
		sum += tmp;
	}
	printf("%d", sum);
	return 0;
}