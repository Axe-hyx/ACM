#include <cstdio>
int c,n;
#define max(a,b) (a>b?a:b)
#define maxn 100
int dp[maxn][maxn];
int main(){
    scanf("%d", &c);
    while(c--){
        scanf("%d",&n);
        for(int i=0; i<n;++i){
            for(int j=0;j<=i;++j){
                scanf("%d", &dp[i][j]);
            }
        }
        for(int i=n-2; i>=0;--i){
            for(int j=0;j<=i;++j){
                dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
                //              dp[i][j] = dp[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
                //              dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + dp[i][j]; //max宏导致求值不对
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        printf("%d\n",dp[0][0]);
    }
}
