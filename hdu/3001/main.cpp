#include <cstdio>
#include <cstring>
#include <algorithm>
#define INf 0x1f1f1f1f
using namespace std;
int n,m;
int dp[59050][11];
int base[12] = {0, 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int g[10][10];
#define INF 0x1f1f1f1f
int state[59050][11];
int main(){
    for(int i=0;i<59049;++i){
        int t = i;
        for(int k=0;k<10;++k){
            state[i][k] = t% 3;
            t /=3;
            if(!t) break;
        }
    }
    while(scanf("%d %d", &m, &n) != EOF){
        if(!m || !n) break;
        memset(g,INF, sizeof(g));

        for(int i =0;i<n;++i){
            int a,b,t;
            scanf("%d%d%d",&a, &b, &t);
            if(t < g[a-1][b-1])
                g[a-1][b-1]  = g[b-1][a-1] = t;
        }

        memset(dp,INF,sizeof(dp));
        for(int i=0; i<m;++i){
            dp [base[i+1]][i] = 0;
        }
        int ans = INF;
        for(int i =0;i<base[m+1];++i){
            int all =1;
            for(int k=0;k<m;++k){
                if(!state[i][k]) {all = 0;}
                if(dp[i][k] == INF) continue;
                for(int l=0;l<m;++l){
                    if(l==k || g[k][l] == INF||state[i][l]>=2 ) continue;
                    int ds = i + base[l+1];
                    dp[ds][l]= min(dp[ds][l], dp[i][k] + g[k][l]);
                }
            }
            if(all){
                for(int e=0;e<m;++e){
                    ans  = min(ans, dp[i][e]);

                }
            }
        }
        if(ans ==INF){
            printf("-1\n");
            continue;
        }
        printf("%d\n", ans);
    }
}
