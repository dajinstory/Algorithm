#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int Nsosu[300000];
vector<int>sosu;
int main(){
	for (int i = 2; i < 300000; i++){
		if (Nsosu[i] == 0){
			sosu.push_back(i);
			for (int j = i << 1; j < 300000; j += i){
				Nsosu[j] = 1;
			}
		}
	}
	int N, idx1, idx2;
	while (scanf("%d", &N)){
		if (N == 0)break;
		idx1 = lower_bound(sosu.begin(), sosu.end(), N) - sosu.begin();
		idx2 = lower_bound(sosu.begin(), sosu.end(), 2*N) - sosu.begin();
		if (sosu[idx2] != 2 * N)idx2--;
		if (sosu[idx1] == N)idx1++;
		printf("%d\n", idx2 - idx1 + 1);
	}
	return 0;
}