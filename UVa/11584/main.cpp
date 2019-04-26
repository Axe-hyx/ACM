#include <cstdio>
#include <cstring>

#define INF 1000000
#define size 1001

#define min(a,b ) a<b? a:b

int main(){
    int n;
    char ca[size];
    scanf("%d", &n);
    bool s[size][size];

    while(n--){
        memset(ca, 0, sizeof(ca));
        scanf("%s", ca);
        memset(s, 0, sizeof(s));
        int len= strlen(ca);
        for(int i=0;i<2* len;++i){
            if(i%2 ==0)
                s[i/2][i/2] = 1;
            int st = i%2 == 0 ? 2:1;
            int l = i-st, r = i+st;
            while(l>=0 && r< 2* len +1){
                int x,y;
                if(i%2 == 0)
                {
                    x = l/2;
                    y = r/2;
                }else{
                    x = l/2;
                    y = (r+1)/2;
                }

                if(ca[x]==ca[y]){
                    s[x][y] = 1;
                }
                else
                    break;
                l-=2;
                r+=2;
            }
        }

        int dp[size];

        memset(dp, 0, sizeof(dp));

        for(int i = 1;i<=len;++i){
            dp [i] = s[0][i-1] ? 1 : INF;
            for(int j=0; j<i; ++j){
                if(s[j][i-1])
                    dp[i] = min(dp[i], dp[j] + 1);

            }

        }
        printf("%d\n", dp[len]);
    }


    return 1;
}
