#include <stdio.h>
int N,M;
int visit[10];
int arr[10];

void check(int idx){
    
    if(idx==M){
        for(int i=0;i<M;i++) printf("%d ",arr[i]);
        printf("\n");
        return;
    }

    int start = 1;
    if(idx>0)start=arr[idx-1]+1;
    for(int i=start;i<=N;i++){
        if(!visit[i]){
            visit[i]=1;
            arr[idx]=i;
            check(idx+1);  
            visit[i]=0;
        }
    }
}

int main(){
    scanf("%d%d",&N, &M);
    check(0);
    return 0;
}
