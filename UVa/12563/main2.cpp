#include <cstdio>
#include <cstring>

#define REP(i,n) for(int i=0; i<n; ++i)
#define size 50
#define max(a,b) a>b? a:b
#define maxt 180*50+678


int le[size];

int dp[2][maxt];

int main(){
    int c;
    int kase = 0;
    scanf("%d", &c);

    while(c--){
        int n,t;
        scanf("%d %d", &n, &t);

        REP(i, n){
           scanf("%d", &le[i]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;

        int pos = 1;
        int re = 0;
        for(int i=0;i<n;++i){
            for(int l=0;l<t;++l){
                int ans = dp[pos^1][l];

                if(le[i] <=l && dp[pos^1][l-le[i]] >=0)
                    ans = max(ans, dp[pos^1][l-le[i]] + 1);
                dp[pos][l] = ans;
                re = max(dp[pos][l], re);
            }
            pos ^=1;
        }
        pos ^= 1;
        for(int i = t-1;i>=0;--i){
            if(dp[pos][i]== re){
                printf("Case %d : %d %d\n", ++kase, re+1, i+678);
                break;
            }
        }
    }



}
