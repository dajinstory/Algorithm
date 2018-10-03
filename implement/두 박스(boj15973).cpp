#include <stdio.h>
int main(){
	int x1, x2, y1, y2, a1, a2, b1, b2, type;
	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &a1, &b1, &a2, &b2);
	if (a1 > x2 || a2 < x1 || b1>y2 || b2 < y1){
		printf("NULL");
	}
	else if (type = (a1 == x2 || a2 == x1) + (b1 == y2 || b2 == y1)){
		if (type == 2) printf("POINT");
		else printf("LINE");
	}
	else{
		printf("FACE");
	}
	return 0;
}