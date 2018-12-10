#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
unordered_map<string, pair<ll, ll> > map;
int main(){
	string s1, s2, s3;
	map.insert(make_pair("black", make_pair(0, 1)));
	map.insert(make_pair("brown", make_pair(1, 10)));
	map.insert(make_pair("red", make_pair(2, 100)));
	map.insert(make_pair("orange", make_pair(3, 1000)));
	map.insert(make_pair("yellow", make_pair(4, 10000)));
	map.insert(make_pair("green", make_pair(5, 100000)));
	map.insert(make_pair("blue", make_pair(6, 1000000)));
	map.insert(make_pair("violet", make_pair(7, 10000000)));
	map.insert(make_pair("grey", make_pair(8, 100000000)));
	map.insert(make_pair("white", make_pair(9, 1000000000)));
	cin >> s1 >> s2 >> s3;
	printf("%lld", (map[s1].first * 10 + map[s2].first)*map[s3].second);
	return 0;
}