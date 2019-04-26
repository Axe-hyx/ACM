//https://blog.csdn.net/becky_w/article/details/80005409
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
long long n,a,b,k;
const LL mod = 1e9 + 9;
const int maxn = 100000 + 7;
using namespace std;
long long pow_mod(long long a, long long b){
    long long res =1;
    while(b > 0){
        if(b & 1) res = (res*a) % mod;
        b = b>>1;
        a = (a * a) % mod;
    }
    return res;

}
int main(){
    char str[maxn];
    while(scanf("%lld%lld%lld%lld", &n, &a, &b, &k) ==4){
        scanf("%s" ,str);
        LL sum = 0;
        for(int i=0; i<k;++i){
            int flag = 1;
            if(str[i] == '-')
                flag = -1;
            sum = (sum + flag * (pow_mod(a, n-i)*pow_mod(b, i)) %mod + mod) %mod;
        }
        int m = (n+1) /k;
        LL  ak = pow_mod(a,k);
        LL  bk = pow_mod(b,k);
        LL ax = pow_mod(ak,mod -2 );
        LL q = (ax * bk)%mod;

        LL ans = 0;
        printf("%lud", sizeof(LL));
        printf("Sum is %lld\n", sum);
        if(q== 1){
            ans = sum*m % mod;
            printf("%lld\n", ans);
        }else{
            LL t1 = sum * (pow_mod(q,m)%mod -1 + mod) %mod;
            LL t2 = pow_mod(q-1,mod-2)%mod;
            ans = (t1 * t2)%mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
