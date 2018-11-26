#include <stdio.h>

int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year[7][2]; //월 화 수 목 금 토 일 로시작

int isYun(int year);
void setYear(void);
int solve(int year);
int get2800Fridays(void);

int main(){
	int N, sum, sum2800;
	setYear();
	scanf("%d", &N);

	sum2800 = get2800Fridays();
	sum = solve(2019 + (N - 2019) % 2800);
	sum += sum2800*((N - 2019) / 2800);
	printf("%d", sum);
	return 0;
}

int isYun(int year){
	if (year % 400 == 0){
		return 1;
	}
	else if (year % 100 == 0){
		return 0;
	}
	else if (year % 4 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void setYear(void){
	int num;
	for (int i = 0; i < 7; i++){
		num = i;
		for (int j = 0; j < 12; j++){
			if ((num + 13) % 7 == 5){
				year[i][0]++;
			}
			num += month[j];
		}
	}
	month[1]++;
	for (int i = 0; i < 7; i++){
		num = i;
		for (int j = 0; j < 12; j++){
			if ((num + 13) % 7 == 5){
				year[i][1]++;
			}
			num += month[j];
		}
	}
}

int solve(int n){
	int sum, num;
	sum = 0, num = 1;
	for (int i = 2019; i <= n; i++){
		int yun = isYun(i);
		sum += year[num][yun];
		num = (num + 365 + yun) % 7;
	}
	return sum;
}

int get2800Fridays(void){
	int sum = 0, num = 1;
	for (int i = 2019; i < 2019 + 2800; i++){
		int yun = isYun(i);
		sum += year[num][yun];
		num = (num + 365 + yun) % 7;
	}
	return sum;
}
