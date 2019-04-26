#include <cstdio>
#include <cstring>


#define ss 7000

int C,G;
int ho[20];
int we[20];
int dp[21][2*ss];


//砝码做阶段 力矩做状态
int main(){
    while(scanf("%d %d", &C, &G) ==2 && C && G){
        for(int i=0; i<C;++i)  scanf("%d", &ho[i]);
        for(int i=0; i<G; ++i) scanf("%d", &we[i]);

        memset(dp, 0, sizeof(dp));
        dp[0][ss] = 1; //妙在边界条件的设置
        for(int i=1;i<=G;++i){
            for(int j=0; j<C;++j){
                for(int k = -ss;k<ss;++k)
                    dp[i][ss + we[i-1] * ho[j] + k] += dp[i-1][ss + k];
            }
        }
        printf("%d",dp[G][ss]);
    }
}
