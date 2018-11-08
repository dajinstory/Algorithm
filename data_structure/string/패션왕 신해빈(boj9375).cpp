#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> myM;
int main(){
	int T, N, num, re;
	char type[24], clothes[24];
	int nums[24];
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for (int i = 0; i < 24; i++)nums[i] = 0;
		num = 0; re = 1;
		for (int i = 0; i < N; i++){
			scanf(" %s %s", clothes, type);
			string key(type);
			auto itr = myM.find(key);
			if (itr == myM.end()){
				myM.insert({ key, num });
				nums[num] = 1;
				num++;
			}
			else{
				nums[myM[key]]++;
			}
		}
		for (int i = 0; i < num; i++){
			re *= nums[i]+1;
		}
		myM.clear();
		printf("%d\n", re - 1);
	}
	return 0;
}