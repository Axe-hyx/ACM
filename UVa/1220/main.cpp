#include <cstdio>
#include <unordered_map>
#include <cstring>
#include <vector>
#define ss 200
using namespace std;

char n1[ss];
char n2[ss];

int n;
vector<int > man[ss];

string s[2] = {"Yes", "No"};
int dp[ss][2];
bool sa[ss][2];
void dpp(int u, bool s){
    int k = man[u].size();
    if(k == 0){
        dp[u][1] = 1;
        dp[u][0] = 0;
        sa[u][1] = sa[u][0] = 1;
        return;
    }
    if(s){
        int ans = 1;
        for(int i=0; i<k;++i){
            dpp(man[u][i], 0);
            ans += dp[man[u][i]][0];
            if(!sa[man[u][i]][0])
                sa[u][1] = 0;
        }
        dp[u][1] = max(ans,1);
    }else{
        int ans = 0;
        for(int i=0; i<k;++i){
            dpp(man[u][i], 0);
            dpp(man[u][i], 1);
            ans += max(dp[man[u][i]][0],dp[man[u][i]][1]);
            if(dp[man[u][i]][0] == dp[man[u][i]][1] || sa[man[u][i]][1]
                    == 0)
                sa[u][0] = 0;
        }
        dp[u][0] = max(ans, 1);

    }

    if(dp[u][0] == dp[u][1])
        sa[u][1] = 0;
}

int main(){
    while(scanf("%d", &n) == 1 && n){
        unordered_map<string, int> map;
        scanf("%s", n1);
        map[n1] = 0;
        for(int i =1;i<n;++i){
            scanf("%s %s", n1, n2);
            if(!map.count(n1)){
                map[n1] = i;
            }
            man[map[n2]].push_back(i);
        }

        memset(dp, 0, sizeof(dp));
        memset(sa, 0 ,sizeof(sa));
        dpp(0,1);
        dpp(0,0);

        for(int i=0;i<ss;++i)
         man[i].clear();

        if(dp[0][0] == dp[0][1]){
            printf("%d No\n", max(dp[0][0], dp[0][1]));
            continue;
        }

        printf("%d %s\n", max(dp[0][0], dp[0][1]),
                (dp[0][0] > dp[0][1] ?
                 s[sa[0][0]].c_str() : s[sa[0][1]].c_str()
                ));


    }

}
