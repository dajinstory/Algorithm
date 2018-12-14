#include <stdio.h>
int isSosu[19] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 };
int nCk[20][20];
int get_nCk(int n, int k){
	if (nCk[n][k] != 0)return nCk[n][k];
	if (k == 0 || k == n)return nCk[n][k] = 1;
	return nCk[n][k] = get_nCk(n - 1, k - 1) + get_nCk(n - 1, k);
}
int main(){
	int N, div_1, div_2, div = 1;
	double re = 1, rate1, rate2, minus1, minus2;
	scanf("%d%d", &div_1, &div_2);
	rate1 = (double(div_1)) / 100;
	rate2 = (double(div_2)) / 100;
	for (int i = 0; i < 18; i++){
		div *= 2;
	}
	//printf("%lf %lf\n", rate1, rate2);

	for (int i = 0; i <= 18; i++){
		if (isSosu[i])continue;
		minus1 = 1;
		for (int k = 0; k < i; k++){
			minus1 *= rate1;
		}
		for (int k = i; k < 18; k++){
			minus1 *= (((double)1) - rate1);
		}

		for (int j = 0; j <= 18; j++){
			if (isSosu[j])continue;
			minus2 = 1;
			for (int k = 0; k < j; k++){
				minus2 *= rate2;
			}
			for (int k = j; k < 18; k++){
				minus2 *= (((double)1) - rate2);
			}
			//printf("%lf %lf\n", minus1, minus2);
			re -= (minus1*get_nCk(18, i))*(minus2*get_nCk(18, j));
		}
	}
	printf("%lf", re);
	return 0;
}