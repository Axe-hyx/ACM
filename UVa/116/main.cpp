#include <cstdio>
#include <algorithm>
#include <cstring>

#define ms 10
#define ns 100
#define REP(i,n) for(int i=0; i<n; ++i)
#define INF 10000
using namespace std;
int main(){
    int m,n;
    while(scanf("%d %d" ,&m, &n) == 2 && m){
        int cur[ms][ns];
        int next[ms][ns];
        int dp[ms][ns];
        int ans = INF;
        int from = 0;
        REP(i,m)
            REP(d,n)
                scanf("%d", &cur[i][d]);

        memset(dp, 0, sizeof(dp));
        memset(next, 0, sizeof(next));

        for(int i=0; i<m; ++i)
            dp[i][n-1] = cur[i][n-1];

        for(int i=n-2; i>=0; --i){
            REP(p, m){
                int k[3]={p-1,p,p+1};

                if(p == 0) k[0] = m-1;
                if(p == m-1) k[2] = 0;

                sort(k, k+3);
                dp[p][i] = INF;
                REP(f, 3){
                    int var  = dp [k[f]][i+1] + cur[p][i];
                    if( var < dp[p][i]){
                        dp[p][i] = var;
                        next[p][i] = k[f];
                    }
                }

                if(i == 0 && dp[p][0] < ans)
                {
                    ans  = dp [p][0];
                    from = p;
                }
            }
        }
        printf("%d", ++from);
        REP(i, n-1){
            printf(" %d" ,next[from][i] + 1);
            from = next[from][i];
        }printf("\n%d\n", ans);

    }
}
