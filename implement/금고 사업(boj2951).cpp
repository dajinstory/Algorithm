#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sosu[4001];
vector<int> cmb;
vector<int> sosu_arr;
int isSosu[4001];
int A, B;
long long L;
long long sum, dup, tmpS, tmpD;

void setSosu(void);
void combVector(int a, int b);
long long cal(vector<int> myV, int idx, long long now, int select);
int solve(void);

int main(){
	setSosu();
	solve();
	return 0;
}

void setSosu(void){
	for (int i = 2; i <= 4000; i++){
		if (isSosu[i] == 0){
			for (int j = i << 1; j <= 4000; j += i){
				isSosu[j] = 1;
			}
			sosu_arr.push_back(i);
		}
	}
	for (int i = 2; i <= 4000; i++){
		for (int j = 0; j < sosu_arr.size(); j++){
			if (i%sosu_arr[j] == 0){
				sosu[i].push_back(sosu_arr[j]);
			}
		}
	}
}
void combVector(int a, int b){
	int i = 0, j = 0;
	cmb.clear();
	while (i < sosu[a].size() || j < sosu[b].size()){
		if (i >= sosu[a].size()){
			cmb.push_back(sosu[b][j]);
			j++;
		}
		else if (j >= sosu[b].size()){
			cmb.push_back(sosu[a][i]);
			i++;
		}
		else{
			if (sosu[a][i] < sosu[b][j]){
				cmb.push_back(sosu[a][i]);
				i++;
			}
			else if (sosu[a][i]>sosu[b][j]){
				cmb.push_back(sosu[b][j]);
				j++;
			}
			else{
				cmb.push_back(sosu[a][i]);
				i++, j++;
			}
		}
	}
}
//못넣는 애의 개수를 구한다.
long long cal(vector<int> myV, int idx, long long now, int select){
	if (idx == myV.size()){
		if (select == 0){
			return 0;
		}
		if (select % 2 == 1){
			return L / now;
		}
		else{
			return -(L / now);
		}
	}
	return cal(myV, idx + 1, now*myV[idx], select + 1) + cal(myV, idx + 1, now, select);
}

int solve(void){
	scanf("%d%d%lld", &A, &B, &L);
	for (int i = 1; i <= (A + B - 1) / 2; i++){
		combVector(i, A + B - i);
		tmpD = L - cal(cmb, 0, 1, 0);
		tmpS = L - cal(sosu[i], 0, 1, 0) + L - cal(sosu[A + B - i], 0, 1, 0) - tmpD;
		sum += tmpS;
		dup += tmpD;
	}

	tmpS = L - cal(sosu[A + B], 0, 1, 0);
	sum += tmpS;
	dup += 1;
	sum *= 2, dup *= 2;

	if ((A + B) % 2 == 0){
		tmpD = L - cal(sosu[(A + B) / 2], 0, 1, 0);
		sum += tmpD;
		dup += tmpD;
	}
	printf("%lld\n%lld\n%lld\n", (A + B + 1)*L - sum, sum - dup, dup);
	return 0;
}