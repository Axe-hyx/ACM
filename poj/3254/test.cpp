#include <cstdio>
int n, m;
int dp[12][1<<12];
int g[12];

bool nei(int k ){
    if(k & k<<1) return true;
    return false;
}
int dpp(int ph, int p){
    if(ph == n) return 1;
    for(int i=0;i<1<<m;++i){
        if(nei(i) ||(g[ph] & i)!=0 ||(p & i) != 0) continue;
        dp[ph][i] += dpp(ph+1,i);
    }
    return 0;
}
int main(){
    while(scanf("%d %d", &n, &m) ==  2 && n){
        for(int i=0; i<n; ++i){
            int t;
            for(int k=0; k<m; ++k){
                scanf("%d", &t);
                if(!t)
                    g[i] |= 1<<k;
            }
        }
        dpp(0,0);
        printf("%d", dp[0][0]);
    }
}
