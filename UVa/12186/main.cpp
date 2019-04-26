#include <cstdio>
#include <vector>
#include <algorithm>

#define ss (1<<5 + 1)

using namespace std;
vector<int> em [1<<6] ;
int n,T;

int dp(int u){

    if(em[u].empty())
        return 1;
    vector<int >d;
    int k = em[u].size();
    for(int i=0; i<k; ++i){
        d.push_back(dp(em[u][i]));
    }
    sort(d.begin(), d.end());
    int ans  =0;
    int c= (T*k-1)/100 + 1;
    for(int i=0; i<c; ++i){
        ans +=d[i];
    }
    return ans;
}
int main(){
    while(scanf("%d %d", &n, &T) == 2 && n){
        for(int i = 1; i<=n; ++i){
            int t;
            scanf("%d", &t);
            em[t].push_back(i);
        }
        printf("%d\n", dp(0));
        for(int i=0; i<1<<6;++i){
            em[i].clear();
        }

    }
}
