#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char str[104];
int main(){
	if (!cin.getline(str, 104).eof()){
		cout << str;
	}
	while (!cin.getline(str, 104).eof()){
		cout << endl << str;
	}
	return 0;
}