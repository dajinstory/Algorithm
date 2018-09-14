/*
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100004];
int re[100004];
pair<int, int> order[200004];
int main(){
	int N, K, a, b, s, e, type, last, step;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++){
		scanf("%d%d", &a, &b);
		order[2 * i] = make_pair(-a, -(2 * i));
		order[2 * i + 1] = make_pair(-b, -(2 * i + 1));
	}
	sort(order, order + 2 * K);
	
	s = 1; e = N, last = N, type = 1;
	//first bound
	a = -order[0].first;
	b = -order[0].second;
	for (int i = 0; i < last - a; i++){
		re[last - i] = arr[e - i];
	}
	e = e - (last-a);
	last = a;
	step = b;
	sort(arr+1, arr + e + 1);
	if (b % 2 == 1){
		type = -1;
	}

	//gogo
	for (int i = 1; i < 2 * K; i++){
		a = -order[i].first;
		b = -order[i].second;
		if (b < step){
			continue;
		}
		step = b;
		if (type == 1){
			for (int i = 0; i < last - a; i++){
				re[last - i] = arr[e - i];
			}
			e = e - (last - a);
			if (b % 2 == 1){
				type = -1;
			}
		}
		else{
			for (int i = 0; i < last - a; i++){
				re[last - i] = arr[s + i];
			}
			s = s + (last - a);
			if (b % 2 == 0){
				type = 1;
			}
		}
		last = a;

	}
	if (type == 1){
		for (int i = 0; i < last; i++){
			re[i+1] = arr[s + i];
		}
	}
	else{
		for (int i = 0; i < last; i++){
			re[i+1] = arr[e - i];
		}
	}
	for (int i = 1; i <= N; i++){
		printf("%d ", re[i]);
	}
	return 0;
}
*/


//deque optimization
#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

deque<pair<int, int> > myD;
int arr[100000];
int re[100000];
int main(){
	int N, K, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &K);
	for (int i = 0; i < 2*K; i++){
		scanf("%d", &tmp);
		tmp -= 1;
		while (!myD.empty() && myD.back().first <= tmp){
			myD.pop_back();
		}
		myD.push_back(make_pair(tmp, i % 2));
	}

	sort(arr, arr + myD.front().first + 1);
	int s = 0, e = N - 1, last = N - 1, type = 0;
	while (!myD.empty()){
		int now = myD.front().first;
		int t = myD.front().second;
		myD.pop_front();
		if (type == 0){
			for (int i = 0; i < last - now; i++){
				re[last - i] = arr[e - i];
			}
			e = e - (last - now);
		}
		else{
			for (int i = 0; i < last - now; i++){
				re[last - i] = arr[s + i];
			}
			s = s + (last - now);
		}

		last = now;
		if (type + t == 1){
			type = -type + 1;
		}
	}

	if (type == 0){
		for (int i = 0; i <= last; i++){
			re[i] = arr[s + i];
		}
	}
	else{
		for (int i = 0; i <= last; i++){
			re[i] = arr[e - i];
		}
	}

	for (int i = 0; i < N; i++){
		printf("%d ", re[i]);
	}
	return 0;
}