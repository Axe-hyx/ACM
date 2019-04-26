#include <cstdio>
#include <algorithm>
const int maxn = 500000 + 7;
const int maxnode = 1000000 + 7;
typedef std::pair<int, int> Interval;

int ql, qr;

long long prefix_sum[maxn];
long long sum(int L, int R){
    return prefix_sum[R] - prefix_sum[L-1];
}

Interval greator(const Interval &a, const Interval &b){
    if(sum(a.first, a.second) == sum(b.first, b.second)) return a<b?a:b;
    else return sum(a.first,a.second) > sum(b.first, b.second) ? a:b;
}

struct IntervalTree{
    int max_suffix[maxnode]; //save the min position
    int max_prefix[maxnode];
    Interval max_sub[maxnode];

    void build(int o, int L, int R){
        if(L == R){
            max_prefix[o] = max_suffix[o] = L;
            max_sub[o] = std::make_pair(L,L);
        }else{
            int ln = o*2 , rn = o*2 + 1;
            int M = (R-L)/2 + L;
            build(ln, L, M);
            build(rn, M+1, R);

            long long v1,v2;
            v1 = sum(L, max_prefix[ln]);
            v2 = sum(L, max_prefix[rn]);
            if(v1 == v2)
                max_prefix[o] = std::min(max_prefix[ln],max_prefix[rn]);
            else
                max_prefix[o] = v1 > v2? max_prefix[ln] : max_prefix[rn];

            v1 = sum(max_suffix[ln], R);
            v2 = sum(max_suffix[rn], R);
            if(v1 == v2)
                max_suffix[o] = std::min(max_suffix[ln], max_suffix[rn]);
            else
                max_suffix[o] = v1 > v2? max_suffix[ln] : max_suffix[rn];

            max_sub[o] = greator(max_sub[ln], max_sub[rn]);
            max_sub[o] = greator(max_sub[o], std::make_pair(max_suffix[ln], max_prefix[rn]));
        }
    }
    Interval query_prefix(int o, int l, int r){
        if(max_prefix[o] <=qr) return  std::make_pair(l, max_prefix[o]);

        int m = (r-l)/2 + l;
        int ln = o*2, rn = o*2+1;
        if(qr<=m) return query_prefix(ln, l, m);
        Interval i2 = query_prefix(rn, m+1,r);
        i2.first =  l;
        return greator(i2, std::make_pair(l,max_prefix[ln]));



    }
    Interval query_suffix(int o, int l, int r){
        if(ql <= max_suffix[o]) return std::make_pair(max_suffix[o],r);

        int m = (r-l) /2 + l;
        int ln =  2*o, rn = 2*o+1;

        if(ql>m) return query_suffix(rn,m+1,r);
        Interval i2 = query_suffix(ln,l,m);
        i2.second = r;
        return greator(i2, std::make_pair(max_suffix[rn],r));

    }
    Interval query (int o, int l, int r){
        if (ql <= l && r <= qr) return max_sub[o];
        int m = (r-l) /2 + l;
        int ln = o*2;
        int rn = o*2 + 1;
        if( qr <=m) return query(ln, l, m);
        if( ql >m) return query(rn, m+1, r);

        Interval i1 = query_prefix(rn,m+1,r);
        Interval i2 = query_suffix(ln,l,m);

        Interval i3 = greator(query(rn, m+1, r),query(ln, l, m));

        return greator(std::make_pair(i2.first, i1.second), i3);
    }
};

struct IntervalTree tree;
int main(){
    int kase=0 ,n ,m;

    while(scanf("%d%d", &n, &m)==2){
        ++kase;
        prefix_sum[0] = 0;
        int tvar;
        for(int i=0; i<n; ++i){
            scanf("%d", &tvar);
            prefix_sum[i+1] = prefix_sum[i] + tvar;
        }

        tree.build(1,1,n);
        printf("Case %d:\n", kase);
        int l,r;
        while(m--){
            scanf("%d%d", &l, &r);
            ql = l, qr = r;
            Interval ans = tree.query(1,1,n); //注意查询范围
            printf("%d %d\n",ans.first, ans.second);
        }
    }
    return 0;
}
