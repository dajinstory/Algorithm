#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char input[100004];
vector<pair<char, int> >str;
int check[26];
int main(){
	int N, len, cnt, sum, ans, first;
	scanf("%d%s", &N, input);
	len = strlen(input);
	str.push_back(make_pair(input[0], 1));
	for (int i = 1; i < len; i++){
		if (str[str.size() - 1].first == input[i]){
			str[str.size() - 1].second++;
		}
		else{
			str.push_back(make_pair(input[i], 1));
		}
	}
	cnt = 1;
	sum = ans = str[0].second;
	first = 0;
	check[str[0].first - 'a'] = 1;
	for (int i = 1; i < str.size(); i++){
		int now = str[i].first;
		int num = str[i].second;

		sum += num;
		if (++check[now - 'a'] == 1) cnt++;
		while (cnt > N){
			if (--check[str[first].first - 'a'] == 0){
				cnt--;
			}
			sum -= str[first].second;
			first++;
		}
		if (sum > ans)ans = sum;
	}
	printf("%d", ans);
	return 0;
}