#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

pair<int, int> spots[100001];
set<pair<int, int> > myS;

int getMul(int a1, int a2){
	return (a1 - a2)*(a1 - a2);
}
int getDist(pair<int, int> s1, pair<int, int> s2){
	return getMul(s1.first, s2.first) + getMul(s1.second, s2.second);
}

int main(){
	int N, x, y, dist, idx = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &spots[i].first, &spots[i].second);

		//spots.push_back(make_pair(x, y));
	}
	sort(spots, spots + N);
	dist = getDist(spots[0], spots[1]);
	myS.insert(make_pair(spots[0].second, spots[0].first));
	myS.insert(make_pair(spots[1].second, spots[1].first));
	for (int i = 2; i < N; i++){
		auto now_reverse = make_pair(spots[i].second, spots[i].first);
		while (getMul(spots[i].first, spots[idx].first) >= dist){
			myS.erase(make_pair(spots[idx].second, spots[idx].first));
			idx++;
		}

		int error = (int)(sqrt((double)dist) + 1);
		auto lower_point = make_pair(spots[i].second - error, -100000);
		auto upper_point = make_pair(spots[i].second + error, 100000);
		auto lower = myS.lower_bound(lower_point);
		auto upper = myS.upper_bound(upper_point);
		
		for (auto it = lower; it != upper; it++){
			int cmp = getDist(now_reverse, *it);
			if (cmp < dist)dist = cmp;
		}
		myS.insert(now_reverse);
	}
	printf("%d", dist);
	return 0;
}