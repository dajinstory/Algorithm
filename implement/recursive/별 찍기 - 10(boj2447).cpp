#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char str[2187][2187];
char blank[2187];
void printStar(int x, int y, int l){
	if (l == 1){
		str[x][y] = '*';
		return;
	}
	else if (l < 0){
		l = -l;
		for (int i = x; i < x + l; i++){
			for (int j = y; j < y + l; j++){
				str[i][j] = ' ';
			}
		}
		return;
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (i == 0 && j == 0)printStar(x, y, l / 3);
			else if (i == 1 && j == 1)printStar(x + l / 3, y + l / 3, -l / 3);
			else{
				for (int px = 0; px < l/3;px++){
					for (int py=0;py<l/3;py++){
						int nx, ny;
						nx = x + l/3*i + px;
						ny = y + l/3*j + py;
						str[nx][ny] = str[px][py];
					}
				}
			}
		}
	}
}
int main(){
	int N;
	scanf("%d", &N);
	if (N == 1){
		printf("*");
		return 0;
	}
	printStar(0, 0, N / 3);
	for (int i = 0; i < N / 3; i++)blank[i] = ' ';
	for (int i = 0; i < N; i++){
		int x = i % (N / 3);
		if (i < N / 3 || i >= (N / 3) * 2){
			printf("%s%s%s\n", str[x], str[x], str[x]);
		}
		else{
			printf("%s", str[x]);
			printf("%s", blank);
			printf("%s\n", str[x]);
		}
	}
	return 0;
}