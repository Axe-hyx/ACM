#include <cstdio>
#include <cstring>
int n;
int sum[1000];
int dp[100];
#define INF 0x3f3f3f3f

#define min(a,b) a<b ? a:b
int peal[1000][2];
int main(){
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        memset(dp, INF,sizeof(dp));
        for(int i=0; i<m;++i){
            scanf("%d %d", &peal[i][0], &peal[i][1]);
            sum[i] = peal[i][0];
            if(!i){
                dp[i] = (peal[0][0] + 10) * peal[0][1];
            }else{
                sum[i] +=sum[i-1];
                dp[i] = (sum[i] + 10) * peal[i][1]; // 全买
                for(int k =0;k<i;++k){
                    dp[i]  = min(dp[k] + (sum[i] - sum[k] +10 ) * peal[i][1],dp[i]);
                }
            }
        }

        printf("%d\n",dp[m-1]);
    }
    return 1;
}
