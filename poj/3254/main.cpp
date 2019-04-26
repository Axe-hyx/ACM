#include <cstdio>
int n,m;
int dp[12][1<<12];
int s[12];
const int mod = 1000000000;
bool nei(int k){
    if(k & (k<<1)) return true;
    return false;
}


int main(){
    while(scanf("%d %d", &n, &m)==2 &&n){
        for(int i=0;i<n;++i){
            int t;
            for(int k=0; k<m; ++k){
                scanf("%d", &t);
                if(!t)
                    s[i] |=1<<k;
            }
        }
        for(int i=0;i<1<<m;++i){
            if((s[0] & i) || nei(i)) continue;
            dp[0][i] = 1;
        }
        for(int i=1;i<n;++i){
            for(int k=0;k<1<<m;++k){
                if(nei(k) || (s[i] & k ))continue;
                for(int j=0;j<1<<m;++j){
                    if(nei(j) || (s[i-1] & j ))continue;
                    if((k&j))continue;
                    dp[i][k] = (dp[i-1][j] + dp[i][k]) % mod;
                }
            }
        }
        int ans =0;
        for(int i=0;i<1<<m;++i){
            if(nei(i) || (s[m-1] & i ))
                continue;
            ans = (dp[n-1][i] + ans ) %mod;
        }
        printf("%d\n", ans);
    }
}
