#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#define maxn 128
#define maxm 11
#define INF 0x3f3f3f3f

using namespace std;
int n,m;
char p[13];
int we[maxm];
int d[1<<11][1<<11];


int dp(int s, int a){
    int &ans = d[s][a];
    if(ans != -1) return ans;

    int num = 0;
    for(int i=0; i<m; ++i){
        if((s & we[i]) == a)
            ++num;
    }
    if(num <=1) return 0;
    ans = INF;
    for(int i =0;i<n;++i){
        if(s & (1<<i) )continue;
        ans = min(max(dp(s | (1<<i), a | (1<<i)), dp(s | (1<<i),a))+1, ans);
    }
    return ans ;
}
int getvalue(){
    int t =0;
    for(int i=0; i<n; ++i){
        t= t<<1;
        t|=p[i]-'0';
    }
    return t;
}

int main(){
    while(scanf("%d %d", &n, &m) == 2 && n){
        for(int i=0; i<m; ++i){
            scanf("%s", p);
            we[i] =getvalue();
            printf("%d\n", we[i]);

        }
        memset(d, -1,sizeof(d));
        printf("%d\n", dp(0,0));
        return 1;
    }
}
