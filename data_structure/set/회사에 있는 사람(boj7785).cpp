#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <functional>
using namespace std;

string inputs[1000001][2];
set<string, greater<string> > s;
int main() {
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin >> inputs[i][0] >> inputs[i][1];
	}
	
	for(int i=0;i<N;i++){
		if (inputs[i][1] == "enter"){
			s.insert(inputs[i][0]);
		} 
		else s.erase(inputs[i][0]);
	}
	for (auto i : s){
		cout << i << '\n';
	}
	return 0;
}