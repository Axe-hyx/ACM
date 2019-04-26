#include <cstdio>
#include <algorithm>
#include <vector>

const int maxlg = 20;
const int maxn = 100000 + 7;

struct RMQ{
    int d[maxn][maxlg];

    void init(const std::vector<int > &q){
        int n = q.size();
        for(int i=0; i<n; ++i) d[i][0] = q[i];
        for(int i=1; (1<<i) <=n;++i){
            for(int k=0; k+(1<<i)-1 <n;++k){
                d[k][i] = std::max(d[k][i-1], d[k+(1<<(i-1))][i-1]);
            }
        }
    }

    int query(int L, int R){
        int k = 0;
        while(1<<(k+1) <= (R-L+1)) ++k;
        return std::max(d[L][k], d[R-(1<<k) +1 ][k]);
    }
};


int n,q;
int count[maxn], val[maxn], le[maxn], ri[maxn], num[maxn];
int a[maxn];
struct RMQ rmq;
int main(){
    while(scanf("%d%d", &n, &q)==2){
        for(int i=0;i<n;++i) scanf("%d", &a[i]);

        std::vector <int> idx;
        int start = 0;
        a[n] = a[n-1] + 1;
        for(int i= 1;i<=n;++i){
            if(a[i] > a[i-1]){
                idx.push_back(i-start);
                for(int k= start; k<i;++k){
                    num[k] = idx.size()-1;
                    le[k] = start;
                    ri[k] = i-1;
                }
                start = i;
            }
        }
        rmq.init(idx);

        int l,r;
        for(int i=0; i<q; ++i){
            scanf("%d%d", &l, &r);
            --l, --r;
            if(num[r]== num[l])
            {
                printf("%d\n", r-l+1);
                continue;
            }
            int ans = std::max(ri[l]-l, r-le[r])+1;
            if(num[l]<num[r]-1)
                ans = std::max(rmq.query(num[l]+1,num[r]-1), ans);
            printf("%d\n",ans);
        }

    }
    return 0;
}
