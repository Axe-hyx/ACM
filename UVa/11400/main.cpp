#include <cstdio>
#include <algorithm>


#define size 1001
#define REP(i,n) for(int i=0; i<n; ++i)

#define min(a,b ) a<b ? a:b

#define INF 100000000
struct li{
    int V; //volt`
    int K; //power cost`
    int C; //per cost`
    int L; //needed`

    bool operator < (const li& b){
        return V < b.V;
    }
};

long dp[size];
int nums[size];
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        struct li l [size];
        REP(i,n){
                scanf("%d %d %d %d"
                        ,&l[i].V
                        ,&l[i].K
                        ,&l[i].C
                        ,&l[i].L);
        }
        sort(l,l+n);
        for(int i = 0;i<n;++i)
        {
            nums[i] = l[i].L + (i==0 ? 0: nums[i-1]);
            long ans = INF;
            for(int k=0; k<i; ++k)
            {
                ans = min(ans, dp[k] + (nums[i] - nums[k]) * l[i].C + l[i].K);
            }
            ans = min(ans, l[i].K + l[i].C*nums[i]);
            dp[i] = ans;
        }

        printf("%ld\n", dp[n-1]); // 这才是最终答案

    }
}
