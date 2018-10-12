#include <stdio.h>

int getEulerInverse(int num, int mod);

int main(){
	int e, s, m, re_e, re_s, re_m, ans;
	const int E = 15, S = 28, M = 19;

	scanf("%d%d%d", &e, &s, &m);
	re_e = getEulerInverse(S*M, E);
	re_s = getEulerInverse(E*M, S);
	re_m = getEulerInverse(E*S, M);
	ans = (S*M*re_e*e + E*M*re_s*s + E*S*re_m*m) % (E*S*M);
	if (ans == 0){
		ans = E*S*M;
	}
	printf("%d", ans);
	return 0;
}

int getEulerInverse(int num, int mod){
	int s[2], t[2], r[2], q[2], now, next;
	s[0] = 1, s[1] = 0;
	t[0] = 0, t[1] = 1;
	r[0] = num, r[1] = mod;
	now = 1, next = 0;

//	printf("s t r q \n");
	while (1){
		q[now] = r[next] / r[now];
//		printf("%d %d %d %d\n", s[now], t[now], r[now], q[now]);
		r[next] = r[next] - r[now] * q[now];
		if (r[next] == 0){
			break;
		}
		s[next] = s[next] - s[now] * q[now];
		t[next] = t[next] - t[now] * q[now];
		now = next;
		next = (now + 1) % 2;
	}
	return (s[now] + mod) % mod;
}
