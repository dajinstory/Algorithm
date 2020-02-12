#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;

int N;
string text;
char cmds[500001][2];

list<char> ans;
char ans_cs[600001];

int main() {

	cin >> text >> N;
	for(int i=0;i<N;i++){
		scanf(" %c",&cmds[i][0]);
		if(cmds[i][0]=='P'){
			scanf(" %c",&cmds[i][1]);	
		}
	}
	for(int i=0;i<text.length();i++){
		ans.push_back(text[i]);
	}


    list<char>::iterator iter = ans.begin();
	advance(iter, text.size());
	for(int i=0;i<N;i++){
		if (cmds[i][0] == 'P') {
			iter = ans.insert(iter,cmds[i][1]);
			advance(iter, 1);
		}
		else if (cmds[i][0] == 'L') {
			if (iter != ans.begin()) {
				advance(iter, -1);
			}
		}
		else if (cmds[i][0] == 'D') {
			if (iter != ans.end()) {
				advance(iter, 1);
			}
		}
		else if (cmds[i][0] == 'B') {
			if (iter != ans.begin()) {
				advance(iter, -1);
				iter = ans.erase(iter);
			}
		}
	}

	int idx=0;
	for(list<char>::iterator i=ans.begin(); i!=ans.end(); i++, idx++){
		ans_cs[idx]=*i;
	}
	printf("%s", ans_cs);
	return 0;
}