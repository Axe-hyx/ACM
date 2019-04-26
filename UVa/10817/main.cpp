#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

#define min(a,b) a<b ? a:b
#define maxs 8
#define maxn 1<<maxs
const int INF =10000000;
int d[maxs][maxn][maxn];
int m, n, sn;

int s[120];
int c[120];
int dp(int i, int s0, int s1, int s2){
    if(i == m+ n ) return s2 == (1<<sn) -1 ?  0: INF;

    int & ans = d[i][s1][s2];
    if(ans >= 0) return ans;
    int q1 = s[i] & s0;
    int q2 = s[i] & s1;

    ans = INF;
    if(i > m) ans = dp (i+1, s0, s1,s2);
    s0 ^= q1; s1 =(s1^q2) | q1; s2 |= q2;
    ans = min(dp(i+1, s0, s1, s2) + c[i],ans);
    return ans;
}
int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        ss >> sn >> m >> n;
        if(!m ) break;
        for(int i=0;i< m +n; ++i){
            string kl;
            getline(cin, kl);
            stringstream ss(kl);

            ss>>c[i];
            s[i] = 0;
            int x;
            while(ss>>x) s[i] |= (1<<(x-1));
        }
        memset(d,-1,sizeof(d));
        printf("%d\n",dp(0,(1<<sn)-1,0,0));

    }
}
