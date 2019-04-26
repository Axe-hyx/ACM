#include <cstdio>
#include <cstring>

#define ss 10
#define maxn 100005
int cash,N;
int cost[ss], nu[ss];
int dp[maxn];
int main(){
    while(scanf("%d %d", &cash, &N)==2){
        for(int i=0;i<N;++i) scanf("%d %d", &nu[i], &cost[i]);
        if(!N || !cash) {printf("0\n");continue;}
        memset(dp,0, sizeof(dp));

        dp[0] = 1;

        for(int k=0;k<N;++k){// 优化降低复杂度
            for(int i=cash;i>=0;--i){ //错在循环嵌套
                for(int m=1; m<=nu[k]; ++m){
                    if(i >= cost[k]*m){
                        dp[i] += dp[i-cost[k]*m];
                    }
                }
                /*                while(nu[k]>0){
                                  if(i > cost[k]){
                                  dp[i]+=dp[i - cost[k]];
                                  --nu[k];
                                  }
                                  }
                                  */
            }
        }
        for(int i = cash; i>=0; --i){
            if(dp[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
}
