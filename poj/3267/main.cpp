#include <cstdio>
#include <string>
#include <cstring>

#define INF 10000
int W, L;
using namespace std;
#define ss 305
char str[ss];
char words[600][26];

int dp[ss];
int main(){
    while(scanf("%d %d", &W, &L) == 2 && W && L){
        scanf("%s",str);
        for(int i=0; i<W; ++i) scanf("%s", words[i]);

        //----错误解法 可能在计算dp[t]时 认为dp[i]为无穷
        //或者dp[t]使用了更老的dp[i]值 且当dp[i]值更新时 dp[t]没得到更新 即不满足最优子结构性质
        /*
        for(int i = 0;i<=L;++i)
            dp[i] = i;
        for(int i=1; i<=L; ++i){
            dp[i] = min(dp[i],dp[i-1] + 1);
            for(int k=0; k<W; ++k){
                int match = 0;
                int len = strlen(words[k]);
                int t= i;
                if(L - t < len && words[k][0] != str[t]) continue;
                while(t<=L){
                    if(str[t]== words[k][match])
                        ++match;
                    ++t;
                    if(match == len){
                        dp[t] = min(dp[i] + t - i - len, dp[t]);
                        break;
                    }
                }
            }
        }
        */
        dp[L] = 0;
        for(int i = L-1; i>=0; --i){
            dp[i] = dp[i+1] +1;
            for(int k=0; k<W; ++k){
                int match = 0;
                int t=i;
                int len = strlen(words[k]);
                if(L-t < len && words[k][0] != str[t]) continue;
                while(t<L){
                    if(str[t]==words[k][match])
                        ++match;
                    ++t;
                    if(match == len){
                        dp[i] = min(dp[i], dp[t] + t-i-len);
                        break;
                    }
                }

            }
        }
        printf("%d\n", dp[0]);

    }
}
