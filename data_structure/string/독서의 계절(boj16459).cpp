#include <iostream>
#include <string>
#define MIN(A,B)((A)<(B)? A:B)
using namespace std;

string input[104];

int getMin(int a, int b);

int main(){
	string WHO, WHERE, WHAT;
	int num = -1, idx, idx_2, idx_3, idx_min;
	do{
		num++;
		getline(cin, input[num]);
	} while (!(input[num].length() == 1 && input[num][0] == '0'));
	getline(cin, WHO);
	getline(cin, WHERE); //+WHO
	getline(cin, WHAT); //+WHO, WHERE


	//parsing WHERE
	idx = WHERE.find("WHO", 0);
	while (idx != string::npos){
		WHERE.replace(idx, 3, WHO);
		idx += WHO.length();
		idx = WHERE.find("WHO", idx);
	}


	//parsing WHAT
	idx = WHAT.find("WHO", 0);
	idx_2 = WHAT.find("WHERE", 0);
	idx_min = getMin(idx, idx_2);
	while (idx_min != string::npos){
		if (idx == idx_min){
			WHAT.replace(idx_min, 3, WHO);
			idx_min += WHO.length();
		}
		else{
			WHAT.replace(idx_min, 5, WHERE);
			idx_min += WHERE.length();
		}
		idx = WHAT.find("WHO", idx_min);
		idx_2 = WHAT.find("WHERE", idx_min);
		idx_min = getMin(idx, idx_2);
	}

//	cout << WHO << endl << WHERE << endl << WHAT << endl;

	//solving queries..
	for (int i = 0; i < num; i++){
		idx = input[i].find("WHO", 0);
		idx_2 = input[i].find("WHERE", 0);
		idx_3 = input[i].find("WHAT", 0);
		idx_min = getMin(getMin(idx, idx_2), idx_3);
		while (idx_min != string::npos){
			if (idx == idx_min){
				input[i].replace(idx_min, 3, WHO);
				idx_min += WHO.length();
			}
			else if (idx_2 == idx_min){
				input[i].replace(idx_min, 5, WHERE);
				idx_min += WHERE.length();
			}
			else{
				input[i].replace(idx_min, 4, WHAT);
				idx_min += WHAT.length();
			}
			idx = input[i].find("WHO", idx_min);
			idx_2 = input[i].find("WHERE", idx_min);
			idx_3 = input[i].find("WHAT", idx_min);
			idx_min = getMin(getMin(idx, idx_2), idx_3);
		}
		cout << input[i] << endl;
	}
	return 0;
}

int getMin(int a, int b){
	if (a == -1){
		return b;
	}
	else if (b == -1){
		return a;
	}
	else{
		return MIN(a, b);
	}
}
