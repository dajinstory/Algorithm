#include <stdio.h>
int pos[3];
int solve(int now);
int getMin(int a, int b){
	if (a < b)return a;
	return b;
}
int main(){
	int T, A, now, next, tmp;
	char charr;
	scanf("%d", &T);
	while (T--){
		scanf("%d.%d", &A, &tmp);
		A = A * 1000 + tmp;
		pos[0] = A;

		scanf("%d.%d", &A, &tmp);
		A = A * 1000 + tmp;
		pos[1] = A;

		scanf(" %c", &charr);

		scanf("%d.%d", &A, &tmp);
		A = A * 1000 + tmp;
		pos[2] = A;
		now = charr - 'A';
		next = -(now - 1);
		printf("%d\n", getMin(solve(pos[now]), solve(pos[next]) + 1));
	}
	return 0;
}
int solve(int now){
	int re = 6;
	int cnt, num;
	if (now == pos[2])return 0;

	num = now;
	cnt = 0;
	for (int i = 0; i < 5; i++){
		num += 20;
		cnt++;
		if (num > 146000)num = 144000;
		if (num == pos[2])re = getMin(re, cnt);
	}

	num = now;
	cnt = 0;
	for (int i = 0; i < 5; i++){
		num -= 20;
		cnt++;
		if (num < 144000)num = 146000;
		if (num == pos[2])re = getMin(re, cnt);
	}
	return re;
}