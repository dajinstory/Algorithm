#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
	double pi = M_PI;
	int R;
	scanf("%d", &R);
	printf("%.6lf\n%.6lf", pi*R*R, ((double)R)*R * 2);
	return 0;
}