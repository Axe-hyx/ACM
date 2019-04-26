#include <cstdio>
#include <cstring>

#define size 5001
#define maxn 26
#define REP(i,n) for(int i=0; i< (int)n; ++i)

#define INF 10000
#define min(a,b ) a<b? a:b

char n[size];
char m[size];

using namespace std;

int dp[size][size];
int Lc[size][size];

//  卡在下标
int main(){
    int s;
    scanf("%d", &s);
    while(s--){
        scanf("%s", n+1);
        scanf("%s", m+1);

        int e1[maxn],b1[maxn];
        int e2[maxn],b2[maxn];

        memset(e2, 0, sizeof(e2));
        memset(e1, 0, sizeof(e1));

        for(int i=0; i<26;++i){
            b1[i] = INF;
            b2[i] = INF;
        }
        for(int i=strlen(n+1); i>0; --i){
            if(!e1[n[i]-'A']) e1[n[i]-'A'] =i;
            b1[n[i]-'A'] = i;
        }
        for(int i=strlen(m+1); i>0; --i){
            if(!e2[m[i]-'A']) e2[m[i]-'A'] = i;
            b2[m[i]-'A'] = i;
        }

        memset(dp, 0, sizeof(dp));
        memset(Lc, 0, sizeof(Lc));
        REP(i, strlen(n+1) +1){
            REP(k, strlen(m+1) +1){
                if(!i && !k) continue;
                int l=INF,r=INF;
                if(i) l = dp[i-1][k] + Lc[i-1][k];
                if(k) r = dp[i][k-1] + Lc[i][k-1];
                dp[i][k] = min(l,r);

                // ------------------------------------ 主要理解以下如何计算未完成序列
                if(i){
                    Lc[i][k] = Lc[i-1][k];
                    if(b1[n[i]-'A'] == i &&  b2[n[i]-'A'] > k) ++Lc[i][k];
                    if(e1[n[i]-'A'] == i &&  e2[n[i]-'A'] <=k) --Lc[i][k];
                }else if(k){
                    Lc[i][k] = Lc[i][k-1];
                    if(b2[m[k]-'A'] == k && b1[m[k]-'A'] > i) ++Lc[i][k];
                    if(e2[m[k]-'A'] == k && e1[m[k]-'A'] <= i) --Lc[i][k];
                }

            }
        }
        printf("%d\n",dp[strlen(n+1)][strlen(m+1)]);
    }
}
