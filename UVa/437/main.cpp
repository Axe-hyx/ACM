#include <cstdio>
#include <cstring>

#define size 31
#define maxn 91
#define REP(i,n) for(int i=0; i<n; ++i)
#define max(a,b) a > b ? a:b

int dp[size][3];
int G[maxn][maxn];
int qube[size][3];
int n;
// 卡在记忆化搜索
int vis[maxn];
int dpp(int idx, int h){
    int &ans = dp[idx][h];

//    if(ans > 0) return ans;
    if(vis[idx*3 + h])
        return ans;

    //注意这样标记vis数组
    vis[idx *3 +h] =1;
    ans = qube[idx][h];
    REP(i,n){
        REP(d,3 )
        {
            if(G[idx*3+h][i*3+d])
                ans = max(ans, dpp(i, d)+ qube[idx][h]);
        }
    }
    return ans;
}

int main(){
    int kase = 0;
    while(scanf("%d", &n) ==1 && n)
    {
        memset(qube, 0, sizeof(qube));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i)  scanf("%d %d %d", &qube[i][0], &qube[i][1], &qube[i][2]);

        memset(G, 0, sizeof(G));
        memset(dp, 0, sizeof(dp));

        REP(i,n){
            REP(k,3){
                REP(m,n){
                    REP(d,3){
                        if((qube[i][(k+1) %3] > qube[m][(d+1)%3] && qube[i][(k+2)%3] > qube[m][(d+2) %3])
                                ||(qube[i][(k+2) %3] > qube[m][(d+1)%3] && qube[i][(k+1)%3] > qube[m][(d+2) %3])){
                            G[i*3+k][m*3+d] = 1;
                        }
                    }
                }
            }
        }
        REP(i,n){
            REP(d, 3)
            {
                dpp(i, d);
            }
        }

        int ans = 0;
        REP(i,n){
            REP(d, 3)
            {
                ans = max(ans, dp[i][d]);
            }
        }
        printf("Case %d: maximun height = %d\n" ,++kase ,ans);
    }
}

