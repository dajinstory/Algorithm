#include <stdio.h>
#include <string.h>
#define ALL 1000000

char str[10];
int main(){
	int T, len;
	double tmp;
	long long div, all, num, num_min, num_max;
	scanf("%d", &T);
	while (T--){
//		scanf("%lf", &tmp);
//		num = (int)(tmp / 0.0001);
		scanf(" %s", str);
		len = strlen(str);
		num = 0;
		for (int i = 0; i < len; i++){
			if (str[i] == '.')continue;
			num = num * 10 + str[i] - '0';
		}
		num *= 10;
		num_min = num - 5;
		num_max = num + 5;

		all = 0;
		do{
			all += ALL;
			div = all / num_max;
			while (num_max*div <= all)div++;
		} while (num_min*div > all);
		printf("%lld\n", div);
	}
	return 0;
}