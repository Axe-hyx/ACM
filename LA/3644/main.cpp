#include <cstdio>
const int maxn  = 100000  +5;
int pa [maxn];

int findset(int x){return x == pa[x]? x : pa[x]=findset(pa[x]);}

int main(){
    int l,r;
    while(scanf("%d",&l) == 1){
        for(int i =0;i<maxn;++i)
            pa[i] = i;
        int ans = 0;
        while(l!=-1){
            scanf("%d", &r);
            l = findset(l); r = findset(r);
            if(l == r )
                ++ans;
            else
                pa[l] = r;
            scanf("%d", &l);
        }
        printf("%d\n",ans);
    }
    return 0;
}
