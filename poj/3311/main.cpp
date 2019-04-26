#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 100000
int n;
int dp[12][1 << 12];
int g[12][12];
int main(){
    while(scanf("%d", &n) == 1&&n){
        for(int i=0; i<=n; ++i)
            for(int k=0; k<=n;++k)
                scanf("%d", &g[i][k]);

        for(int i =0;i<=n;++i){
            for(int k=0; k<=n; ++k){
                for(int m=0; m<=n; ++m){
                    if(g[i][k] + g[k][m] < g[i][m])
                        g[i][m] = g[i][k] + g[k][m];
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<1<<n; ++i)
        {
            for(int l=0; l<n;++l){
                if((i&(1<<l))){ // cation here fuck
                    if(i == (1<<l))
                        dp[l][i] = g[0][l+1];
                    else{
                        dp [l][i] = INF;
                        for(int k=0;k<n;++k){
                            if(k!=l &&(i&(1<<k)))
                                dp[l][i] = min(dp[k][i^(1<<l)]+g[k+1][l+1],dp[l][i]);
                        }
                    }
                }
            }
        }

        int ans =INF;
        for(int i =0; i<n;++i){
            ans = min(ans, dp[i][((1<<n) -1)] + g[i+1][0]);
        }
        printf("%d\n",ans);

    }
}
