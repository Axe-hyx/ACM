#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
#define maxn 13
long long  dp[1<<maxn][2];
int cur;
void update(int s, int n){
    if(n& (1<<m)) dp[n^(1<<m)][cur]+= dp[s][1-cur];

}
int main(){
    while(scanf("%d%d", &n, &m)){
        if(!n || !m) break;
        if(n > m)
            swap(n,m);

        cur =0;
        memset(dp, 0, sizeof(dp));
        dp[(1<<m)-1][cur] =1;

        for(int i =0; i<n;++i){
            for(int k =0; k<m;++k){
                cur ^=1;

                memset(dp[cur],0,sizeof(dp[cur]));
                for(int d= 0; d<1<<m;++d){
                    update(d,d<<1);
                    if(i && !(d&(1<<(m-1)))) update(d, (d<<1) ^ (1<<m) ^ 1);
                    if(k && !(d&1)) update(d,(d<<1) ^ 3);
                }
            }
        }
      printf("%lld\n", dp[(1<<m)-1][cur]);
    }
}
