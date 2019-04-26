#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 12
int cas;
int a[maxn][maxn];
int dp[1<<maxn];
int main(){
    while(1){
        scanf("%d", &cas);
        if(cas == 0) break;
        for(int i =0; i<cas; ++i)
            for(int k=0; k<cas; ++k)
                scanf("%d", &a[i][k]);

        memset(dp, 0, sizeof(dp));

        /*
        for(int i =0;i<1<<cas;++i){
            for(int k=0; k<cas;++k){
                if((i&(1<<k))==0) continue;
                for(int d=0; d<cas; ++d){
                    if(k == d ||(i & (1<<d))==0) continue;
                    int s = i -(1<<d);
                    dp[s]= max(dp[s], dp[i] + a[k][d]); // dp[s]与遍历方向相反 错误
                }
            }
        }
        */

        for(int i=0;i<1<<cas;++i){
            for(int k=0;k<cas;++k){
                if(i&(1<<k)) continue;
                for(int m=0; m<cas; ++m){
                    if(k==m || (i&1<<m)) continue;
                    int news = i + (1<<m);
                    dp[news] = max(dp[news], dp[i]+a[k][m]); //news 方向与i递增方向一致 才保证循环不变 容易见取1为不存在状态

                }
            }
        }
        int ans =0;
        for(int i=0;i<(1<<cas);++i)
            ans = max(ans, dp[i]);
        printf("%d\n",ans);

    }
}
