#include <cstdio>
#include <cstring>
#define size 80
#define INF 1000

#define min(a,b) a<b ? a:b
// 不要被输入输出流坑了 注意dp方程
int main()
{
    int n, nT;
    int kase = 1;
    while(scanf("%d%d", &n, &nT)==2 && n){
        int m1, m2;
        int T[size];
        int M1[2][size];
        for(int i=1; i<n;++i)
            scanf("%d", &T[i]);
        T[n] = 0;
        scanf("%d", &m1);
        for(int i=0; i<m1; ++i) scanf("%d", &M1[0][i]);
        scanf("%d", &m2);
        for(int i=0; i<m2; ++i) scanf("%d", &M1[1][i]);
        int dp[size][size];
        for(int i=1; i<n;++i)
            dp[nT][i]=INF;
        dp[nT][n] = 0;

        bool has_train[size][size][2];
        memset(has_train, 0, sizeof(has_train));
        /*
           int all= 0;
           for(int i = 1;i<n;++i){
           all += T[i];
           }
           for(int dir = 0; dir<2 ; ++dir)
           {
           int  sum=0, sum2= all;
           for(int j=1;j<n; ++j)
           {
           for(int i=0; i<nT; ++i)
           {
           for(int k = 0; k< (dir == 0 ? m1:m2); ++k)
           {
           if(M1[dir][k]+ (dir==0? sum : sum2)
           == i){
           has_train[i][j][dir] = 1;
           break;
           }
           }
           }
           sum+=T[j];
           sum2-=T[j];
           }
           }
           */
        for(int j=0; j<m1;++j)
        {
            for(int i=1;i<n;++i)
            {
                if(M1[0][j] <= nT)
                    has_train[M1[0][j]][i][0]=1;
                M1[0][j] += T[i];
            }
        }

        for(int j=0; j<m2;++j)
        {
            for(int i=n-1;i>=1;--i)
            {
                if(M1[1][j] <= nT)
                    has_train[M1[1][j]][i+1][1]=1;//注意该处是从下一个车站开来的火车
                M1[1][j] +=T[i];
            }
        }
        printf("DEBE %d\n", has_train[nT-3][n][1]);
        for(int i=nT-1; i>=0; --i)
        {
            for(int j=1;j<=n; ++j)
            {
                dp[i][j] = dp[i+1][j] + 1;
                if(j < n && i + T[j] <= nT && has_train[i][j][0])
                    dp[i][j] = min(dp[i][j], dp[i+T[j]][j+1]);
                if(j > 1 && i + T[j-1] <= nT && has_train[i][j][1])
                    dp [i][j] = min(dp[i][j], dp[i+T[j-1]][j-1]);
                printf("%d ", dp[i][j]);
            }
            printf("\n");

        }

        printf("Case Number %d: ",kase++);
        if(dp[0][1]==INF) printf("impossible\n");
        else
            printf("%d\n", dp[0][1]);

    }
    return 1;
}
