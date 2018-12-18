#include <stdio.h>
int adj[30][2];
void p_in(int now){
	if (adj[now][0] != '.' - 'A'){
		p_in(adj[now][0]);
	}
	printf("%c", now + 'A');
	if (adj[now][1] != '.' - 'A'){
		p_in(adj[now][1]);
	}
}
void p_pre(int now){
	printf("%c", now + 'A');
	if (adj[now][0] != '.' - 'A'){
		p_pre(adj[now][0]);
	}
	if (adj[now][1] != '.' - 'A'){
		p_pre(adj[now][1]);
	}
}
void p_post(int now){
	if (adj[now][0] != '.' - 'A'){
		p_post(adj[now][0]);
	}
	if (adj[now][1] != '.' - 'A'){
		p_post(adj[now][1]);
	}
	printf("%c", now + 'A');
}
int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		adj[a - 'A'][0] = b - 'A';
		adj[a - 'A'][1] = c - 'A';
	}
	p_pre(0);
	printf("\n");
	p_in(0);
	printf("\n");
	p_post(0);
	return 0;
}