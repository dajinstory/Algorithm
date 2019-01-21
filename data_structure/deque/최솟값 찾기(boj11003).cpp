#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;

int arr[5000000];
deque < pair<int, int> > myD;
int main(){
	int N, L;
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++){
		if (!myD.empty() && arr[i] <= myD.front().first){
			while (!myD.empty())myD.pop_front();
			myD.push_back(make_pair(arr[i], i));
		}
		else{
			while (!myD.empty() && myD.back().first >= arr[i]) myD.pop_back();
			myD.push_back(make_pair(arr[i], i));
		}
		if (myD.front().second < i - L + 1)myD.pop_front();
		arr[i] = myD.front().first;
	}
	for (int i = 0; i < N; i++)printf("%d ", arr[i]);

	return 0;
}
