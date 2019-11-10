#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> friends[1000001];
stack<pair<int,int> > myS;
int N, cnt;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	myS.push(make_pair(-1,1));
	while(!myS.empty()){
		int pre=myS.top().first;
		int now=myS.top().second;
		int check=-1;
		myS.pop();
		if(now>0){
			cnt++;
			check=1;
		}
		now*=check;
		for(int i=0;i<friends[now].size();i++){
			int next=friends[now][i];
			if(next==pre)continue;
			myS.push(make_pair(now,next*check*(-1)));
		}
	}
	printf("%d",(cnt)<(N-cnt) ? (cnt):(N-cnt));
	return 0;
}