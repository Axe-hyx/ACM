#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 20000 + 1;
const int maxl = 20+3;
const int INF = 0x3f3f3f3f;
int ql, qr;
int v, op;
int _max, _min, _sum;
struct segementtree{
    int addv[maxn<<1], setv[maxn<<1], min[maxn<<1], max[maxn<<1], sum[maxn<<1];
    void maintain(int o, int l, int r){
        int ln = o*2, rn = o*2 +1;
        if(r>l){
            min[o] = std::min(min[ln], min[rn]);
            max[o] = std::max(max[ln], max[rn]);
            sum[o] = sum[ln] + sum[rn];
        }
        if(setv[o] >=0){min[o] = setv[o]; max[o] = setv[o]; sum[o] = (r-l+1) * setv[o];}//少写一个=号
        if(addv[o]){ min[o] +=addv[o]; max[o]+=addv[o]; sum[o] += (r-l+1)*addv[o];}
    }
    void query(int o, int l, int r, int add){
        if(setv[o] >=0){
            int v = setv[o] + add + addv[o];
            _min = std::min(_min, v);
            _max = std::max(_max, v);
            _sum += v*(std::min(r, qr) - std::max(l,ql)+1);
        }
        else if( ql  <=l && r <= qr){
            _min = std::min(_min, add + min[o]);
            _max = std::max(_max, add + max[o]);
            _sum += add * (r-l +1) + sum[o];
        }else{
            int m = (r-l) /2;
            if(ql <=m) query(o*2, l, m, add + addv[o]);
            if(qr > m) query(o*2+1, m+1, r, add + addv[o]);
        }
    }
    void update(int o, int l, int r){
        int m = (r-l)/2 + l;
        if(ql <= l && r<= qr){
            if(op ==1 ) addv[o] += v;
            else if(op ==2 ) {setv[o] = v; addv[o] = 0;}
        }else{
            int ln = o*2, rn = o*2 +1;
            push_down(o,l,r);
            if(ql <=m) update(ln, l, m); else maintain(ln, l, m);
            if(qr >m) update(rn, m+1, r); else maintain(rn, m+1, r);
        }
        maintain(o,l,r);
    }
    void push_down(int o, int l, int r){
        int ln = o*2, rn = o*2 + 1;
        if(setv[o] >=0){
            setv[ln] = setv[rn] = setv[o];
            addv[ln] = addv[rn] = 0;
            setv[o] = -1;
        }
        if(addv[o]){
            addv[ln] += addv[o];
            addv[rn] += addv[o];
            addv[o] = 0;
        }
    }
};
int r,c,m;
struct segementtree tree[maxl];
int main(){
    while(scanf("%d%d%d", &r, &c, &m)==3){
        std::memset(tree, 0, sizeof(tree));
        int x1,x2;
        for(int i =1;i<=r;++i){
            memset(tree[i].setv,-1,sizeof(tree[i].setv));
            tree[i].setv[1]=0; //没初始化线段树setv集
        }
        while(m--){
            scanf("%d%d%d%d%d", &op, &x1, &ql, &x2, &qr);
            if(op == 1 || op == 2){scanf("%d", &v);
                for(int x = x1; x<=x2;++x){
                    tree[x].update(1,1,c);
                }
            }else{
                _sum =0, _min = INF, _max = -INF;
                for(int x=x1; x<=x2; ++x){
                    tree[x].query(1,1,c, 0);
                }
                printf("%d %d %d\n", _sum, _min, _max);
            }
        }
    }
    return 0;
}
