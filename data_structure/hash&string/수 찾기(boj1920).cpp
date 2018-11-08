#include <stdio.h>
#include <unordered_set>
using namespace std;
unordered_set<int> Set;

int main(){
	int N, M, tmp;
	scanf("%d", &N);
	while (N--){
		scanf("%d", &tmp);
		Set.insert(tmp);
	}
	scanf("%d", &M);
	while (M--){
		scanf("%d", &tmp);
		if (Set.end() != Set.find(tmp)){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}