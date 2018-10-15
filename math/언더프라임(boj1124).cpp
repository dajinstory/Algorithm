#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int nSosu[100000];
vector<int> sosu;
queue<pair<int, pair<int, int> > >myQ;
void setSosu(void); 
int getNum(long long limit);
int getNum_second_way(long long limit);

int main(){
	long long A, B;
	scanf("%lld%lld", &A, &B);

	setSosu();
	printf("%d", getNum_second_way(B) - getNum_second_way(A - 1));

	return 0;
}

void setSosu(void){
	nSosu[0] = nSosu[1] = 1;
	for (int i = 2; i <= 100000; i++){
		if (nSosu[i] == 0){
			sosu.push_back(i);
			for (int j = i << 1; j <= 100000; j+=i){
				nSosu[j] = 1;
			}
		}
	}
}


int getNum(long long limit){
	long long mul;
	int idx, sum, ans = 0;
	myQ.push(make_pair(1, make_pair(0, 0)));
	while (!myQ.empty()){
		mul = myQ.front().first;
		idx = myQ.front().second.first;
		sum = myQ.front().second.second;
		myQ.pop();
		if (idx < sosu.size() && mul*sosu[idx] <= limit) {
			myQ.push(make_pair(mul, make_pair(idx + 1, sum)));
			while (mul*sosu[idx] <= limit){
				mul *= sosu[idx];
				sum++;

				if (nSosu[sum] == 0)ans++;
				myQ.push(make_pair(mul, make_pair(idx + 1, sum)));
			}
		}
	}
	return ans;
}
int getNum_second_way(long long limit){
	long long mul;
	int idx, sum, ans = 0;
	myQ.push(make_pair(1, make_pair(0, 0)));
	while (!myQ.empty()){
		mul = myQ.front().first;
		idx = myQ.front().second.first;
		sum = myQ.front().second.second;
		if (nSosu[sum] == 0)
		{
			ans++;
		}
		myQ.pop();
		for (int i = idx; i < sosu.size() && mul*sosu[i] <= limit; i++) {
			myQ.push(make_pair(mul*sosu[i], make_pair(i, sum + 1)));
		}
	}
	return ans;
}
/*
//memory limit by recursive function
int getNum(int idx, int sum, long long mul, long long limit){
	int subSum = 0;
	if (idx==sosu.size() || mul*sosu[idx] > limit)return 0;
	subSum += getNum(idx + 1, sum, mul, limit);
	while (1){
		mul*=sosu[idx];
		sum += 1;
		if (mul > limit){
			break; 
		}
		if (mul < 0){
			printf("%lld", mul);
		}
		if (nSosu[sum] == 0){
			subSum += 1;
		}
		subSum += getNum(idx + 1, sum, mul, limit);
	}
	return subSum;
}
*/