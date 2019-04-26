#include <cstdio>
#include <algorithm>
#include <cstring>
int n,m;
int g[100];
int dp[105][32][32];
char buf[105][20];
using namespace std;
bool ne(int k){
    if(k& (k<<1) || k&(k<<2)) return true;
    return false;
}

int cout(int k){
    int ans =0 ;
    while(k){
        k&= (k-1);
        ++ans;
    }
    return ans;
}
int main(){ //不用下标0位置的dp值 可方便后面计算
    while(scanf("%d %d", &n, &m)!=EOF){
        if(!n || !m) break;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n;++i){
            scanf("%s", buf[i]);
            for(int j=0; j<m; ++j){
                if(buf[i][j] == 'H')
                    g[i] |= 1<<j;
            }
        }

        for(int i=0;i<1<<m;++i){
            if(ne(i) || g[1] &i ) continue;
            dp[1][0][i] = cout(i);
        }

        for(int p=2;p<=n;++p){
            for(int i=0;i<1<<m;++i){
                if(ne(i) || g[p-2]&i ) continue;
                for(int k=0;k<1<<m;++k){
                    if(ne(k) ||g[p-1] &k ) continue;
                    if(k & i ) continue;
                    for(int h=0;h<1<<m;++h){
                        if(ne(h) || g[p] & h) continue;
                        if(h&i || h & k) continue;
                        dp[p][k][h] = max(dp[p][k][h], dp[p-1][i][k] + cout(h));
                    }
                }
            }
        }
        int ans = 0;
        for(int f=1;f<=n;++f)
        for(int i =0;i<1<<m;++i){
            for(int t=0; t<1<<m; ++t)
            {
                ans= max(ans, dp[f][i][t]);
            }
        }
        printf("%d\n", ans);
    }
}
