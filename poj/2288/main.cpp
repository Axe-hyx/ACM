#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m;
#define maxn 13
int val[maxn];
int n,f;
int l,r;
int edge[maxn][maxn];
long long way[1<<maxn][maxn][maxn];
long long  dp[1<<maxn][maxn][maxn];
int main(){
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &n, &f);
       for(int i=0; i<n; ++i) scanf("%d", &val[i]);

        memset(edge,0 ,sizeof(edge));
        for(int i=0; i<f; ++i) {
            scanf("%d%d",&l, &r);
            edge[l-1][r-1]  = edge[r-1][l-1] = 1;
        }
        if(n == 1){
            printf("%d 1\n",val[0]);
            continue;
        }


        memset(dp, -1, sizeof(dp));
        memset(way, 0, sizeof(way));

        for(int i=0;i<n;++i){
            for(int k=0;k<n;++k){
                if( i == k || edge[i][k] == 0)continue;
                    int t = (1<<i) + (1<<k);
                    dp[t][k][i] =  val[i] *val[k] + val[k] + val[i];
                    way[t][k][i] =  1;
            }
        }
        for(int i=0;i<1<<n;++i){
            for(int k=0; k<n;++k){
                if((i&(1<<k)) ==0) continue;

                for(int m=0; m<n; ++m){
                    if((i&(1<<m)) ==0 || k ==m ||edge[k][m]==0) continue;

                    for(int d=0;d<n;++d){
                        if((i&(1<<d))!=0 ||edge[m][d]==0 || d ==k || d==m)  continue;
                        int newS = i + (1<<d);
                        if(dp[i][m][k] == -1 ) continue;

                        int na = dp[i][m][k] + val[d]* val[m] + val[d];
                        if(edge[k][d])
                            na += val[k]*val[m]*val[d];
                        if(dp[newS][d][m] <na){
                            way[newS][d][m] = way[i][m][k];
                            dp[newS][d][m] = na;
                        }else if(dp[newS][d][m] == na)
                            way[newS][d][m] += way[i][m][k];
                    }
                }
            }
        }
        long long ans = -1,num=0;
        int upp = ((1<<n)-1);
        for(int i=0;i<n;++i){
            for(int k=0;k<n;++k){
                if(i == k) continue;
                if(ans < dp[upp][k][i])
                {
                    ans = dp[upp][k][i];
                    num = way[upp][k][i];
                }else if(ans == dp[upp][k][i])
                    num +=way[upp][k][i];
            }
        }
        if(ans == -1){
            printf("0 0\n");
        continue;}
        printf("%lld %lld\n",ans,num/2);
    }

}
