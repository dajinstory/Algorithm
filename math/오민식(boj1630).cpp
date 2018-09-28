#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int Nsosu[1000000];
vector<int> sosu;

void setSosu(int n){
	for (int i = 2; i <= n; i++){
		if (Nsosu[i] == 0){
			sosu.push_back(i);
			for (int j = i << 1; j <= n; j += i){
				Nsosu[j] = 1;
			}
		}
	}
}

int main(){
	long long N, num = 1;
	scanf("%lld", &N);
	setSosu(N);

	for (int i = 0; i < sosu.size(); i++){
		long long tmp = 1;
		while (N >= tmp*sosu[i]){
			tmp *= sosu[i];
			num *= sosu[i];
			num %= 987654321;
		}
	}
	printf("%lld", num);
	return 0;
}