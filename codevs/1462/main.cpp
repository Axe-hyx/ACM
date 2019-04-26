#include <cstdio>
#include <cmath>
#include <cstring>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
    int m =(int)sqrt(b + 0.5);

    bool vis[65537];
    memset(vis,0,sizeof(vis));
    for(int i = 2; i <=m;++i){
        if(!vis[i])
            for(int j = i* i;j <= b;j+=i){
                vis[j] = 1;
            }
    }

    long long ans = 0;
    for(int i = a+1;i < b;++i){
        if(!vis[i])
            ans += i;
    }
    printf("%lld",ans);
}
