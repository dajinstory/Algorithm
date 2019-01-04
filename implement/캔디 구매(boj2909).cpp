#include <stdio.h>
using namespace std;
int main(){
	int cost, K, money = 1, ans;
	scanf("%d%d", &cost, &K);
	for (int i = 0; i < K; i++)money *= 10;

	if (money > cost){
		if (cost * 2 >= money)ans = money;
		else ans = 0;
	}
	else{
		if ((cost%money) * 2 >= money){
			ans = (cost / money)*money + money;
		}
		else{
			ans = (cost / money)*money;
		}
	}
	printf("%d", ans);
	return 0;
}