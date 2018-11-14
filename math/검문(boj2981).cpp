#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int arr[104];
vector<int>sosu;
vector<pair<int,int> >insu;
vector<int>ans;
int Nsosu[40000];
void getSosu(){
	for (int i = 2; i < 40000; i++){
		if (Nsosu[i] == 0){
			sosu.push_back(i);
			for (int j = i << 1; j < 40000; j += i){
				Nsosu[j] = 1;
			}
		}
	}
}
int getGCD(int a, int b){
	int tmp;
	while (b != 0){
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}
int main(){
	int N, GCD = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	//N==2, arr[0]==arr[1]인경우 답이 무한개

	sort(arr, arr + N);
	for (int i = 1; i < N; i++){
		GCD = getGCD(GCD, arr[i] - arr[0]);
	}

	getSosu();
	for (int i = 0; sosu[i] * sosu[i] <= GCD; i++){
		if (GCD%sosu[i] != 0)continue;
		insu.push_back(make_pair(sosu[i], 0));
		while (GCD % sosu[i] == 0){
			insu[insu.size() - 1].second++;
			GCD /= sosu[i];
		}
	}
	if (GCD > 1)insu.push_back(make_pair(GCD, 1));

	ans.push_back(1);
	for (int i = 0; i < insu.size(); i++){
		int len = ans.size();
		int num;
		for (int j = 0; j < len; j++){
			num = ans[j];
			for (int k = 0; k < insu[i].second; k++){
				num *= insu[i].first;
				ans.push_back(num);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 1; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	return 0;
}