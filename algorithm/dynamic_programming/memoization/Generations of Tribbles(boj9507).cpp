#include <stdio.h>
typedef long long ll;

ll fibo[70];
int T,N;

ll get_fibo(int idx){
	if(fibo[idx])return fibo[idx];
	return fibo[idx] = get_fibo(idx-1)+get_fibo(idx-2)+get_fibo(idx-3)+get_fibo(idx-4);
}

int main(){
	fibo[0]=fibo[1]=1;
	fibo[2]=2;
	fibo[3]=4;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",get_fibo(N));
	}
	return 0;
}