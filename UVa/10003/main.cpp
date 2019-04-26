#include <cstdio>
#include <cstring>

#define size 51

#define min(a,b) a<b?a:b
#define INF 50000
int dp[size][size];
bool vis[size][size];
int pos[size];
int dpp(int i, int j)
{
    int &ans = dp[i][j];
    if( vis[i][j])
        return ans;
    vis[i][j] =1;
    ans = INF;
    for(int k=i+1; k<j; ++k){
        // 注意状态转移方程不要写成 ans = min(ans, dpp(i,k)+dpp(k,j)) + pos[j] -pos[i];
        ans = min(ans, dpp(i,k)+dpp(k,j) + pos[j] -pos[i]);
    }
    ans = ans == INF ? 0: ans;

    return ans;
    return ans = ans==INF? 0:ans;
}

int main(){
    int L;
    while(scanf("%d", &L) == 1 && L){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &pos[i]);
        pos[0] = 0;
        pos[n+1] = L;

        memset(vis, 0, sizeof(vis));
        for(int i=0; i<=n;++i){
            for(int j=i+1; j<=n+1; ++j){
                dpp(i,j);
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][n+1]);
    }
}
