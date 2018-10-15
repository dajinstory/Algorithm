#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

stack<pair<int, int> > myS;
int height[100004];
int arr[100004][2];
int main(){
	int N;
	long long max_area = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &height[i]);
	}
	
	height[0] = 0;
	height[N + 1] = 0;

	myS.push(make_pair(height[1], 1));
	for (int i = 2; i <= N + 1; i++){
		while (!myS.empty() && height[i] < myS.top().first){
			arr[myS.top().second][0] = i - myS.top().second;
			myS.pop();
		}
		myS.push(make_pair(height[i], i));
	}
	myS.pop();

	myS.push(make_pair(height[N], N));
	for (int i = N - 1; i >= 0; i--){
		while (!myS.empty() && height[i] < myS.top().first){
			arr[myS.top().second][1] = myS.top().second - i;
			myS.pop();
		}
		myS.push(make_pair(height[i], i));
	}
	myS.pop();


	for (int i = 1; i <= N; i++){
		if (((long long)(arr[i][0] + arr[i][1] - 1))*height[i]>max_area){
			max_area = ((long long)(arr[i][0] + arr[i][1] - 1))*height[i];
		}
	}
	printf("%lld", max_area);
	return 0;
}