#include <cstdio>
#include <cstring>
const int maxn = 20000;
int T;
int a[maxn];
int n;
int c[maxn];
int d[maxn];

const int maxa = 100000 + 7;
int ci[maxa];
#define lowbit(x) (x) & (-x)
int sum(int x){
    int ret = 0;
    while(x > 0)
    {
        ret += ci[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x, int d ){
    while(x <=n){
        ci[x] += d;
        x += lowbit(x);
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0;i<n;++i)
            scanf("%d", &a[i]);
        memset(ci,0,sizeof(ci));
        for(int i=0;i<n;++i){
            add(a[i],1);
            c[i] = sum(a[i]-1);
        }
        memset(ci,0,sizeof(ci));
        for(int i = n-1; i>=0; --i){
            add(a[i],1);
            d[i] = sum(a[i]-1);
        }
        long long ans = 0;
        for(int i =0;i<n;++i){
            ans += (long long)(i-c[i]) * d[i] + (long long)(n-i-1-d[i]) *c[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
