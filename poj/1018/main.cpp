#include <cstdio>
#include <cstring>
int dp[100][1100];
int n,m;
#define INF 0x3f3f3f3f
#define min(a,b ) a<b ? a:b


int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        memset(dp,INF,sizeof(dp));
        scanf("%d", &m);
        for(int k=0; k<m; ++k){
            int num;
            scanf("%d", &num);
            for(int h=0;h<num;++h){
                int a,b;
                scanf("%d %d", &a, &b);
                if(k == 0)
                    dp[0][a] = b;
                else{
                    for(int l = 0;l<1100;++l){
                        if(dp[k-1][l]==INF) continue;
                        if(a >= l){
                            dp[k][l] = min(dp[k-1][l]+b,dp[k][l]);
                        }else{
                            dp[k][a] = min(dp[k-1][l]+b,dp[k][a]);
                        }
                    }
                }
            }
        }
        double ans = 0;
        for(int i=0; i< 1100;++i){
            if(dp[n-1][i]==INF) continue;
            double t  = (double)i / dp[n-1][i];
            if(t > ans)
                ans = t;
        }
        printf("%.3lf\n",ans);
    }
}
