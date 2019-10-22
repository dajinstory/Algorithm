#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll arr[3004];
ll arr_sum[3004];
ll dp[3004][2]; //헬기가 마지막으로 내린 곳이 i번째일 때, i번째 위치까지 배달한 가격.
int N,C,H;

ll getSum(int s, int e){ // s<=e
    if(s==e+1)return 0;
    if(s==0)return arr_sum[e];
    return arr_sum[e]-arr_sum[s-1];
}

ll getCost(int s, int e){ // s<=e
    ll mid = (arr[s]+arr[e]+1)/2;
    int idx = lower_bound(arr,arr+N+1,mid)-arr;
    return C*(getSum(s,idx-1) - arr[s]*(idx-s) + arr[e]*(e-idx+1) - getSum(idx,e));
}

int main(){

    // get input
    scanf("%d",&N);   
    for(int i=1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d%d",&C,&H);

    // set inital state
    sort(arr, arr+N+1);
    for(int i=1;i<=N;i++){
        arr_sum[i]=arr[i]+arr_sum[i-1];
        dp[i][0]=9876543210;
        dp[i][1]=N;
    }
    dp[0][0]=0;
    dp[0][1]=0;

    // solve with dp
    for(int i=0;i<N;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<=N;j++){
            ll cost = getCost(i,j)+H;
            if(dp[i][0]+cost<dp[j][0]){
                dp[j][0] = dp[i][0]+cost;
                dp[j][1] = dp[i][1]+1;
            }
            else if(dp[i][0]+cost==dp[j][0] && dp[j][1]>dp[i][1]+1){
                dp[j][1]=dp[i][1]+1;
            }
            //printf("%d %d %lld %lld\n",i,j,dp[j][0], cost);
        }
    }

    // get answer
    ll ans=C*getSum(0,N-1);
    for(int i=0;i<=N;i++){
        //printf("%lld ", dp[i][0]);
        if(i>0 && arr[i]==arr[i-1])continue;
        ll subans=dp[i][0]+C*(getSum(i+1,N)-arr[i]*(N-i));
        if(subans<ans){
            ans=subans;
        }
    }
    printf("%lld",ans);
    return 0;
}