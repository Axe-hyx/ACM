#include <cstdio>
#include <algorithm>
const int maxn = 20000 + 5;


int d[maxn];
int pa[maxn];

int findset(int p){
    if(pa[p] !=p){
        int root = findset(pa[p]);
        d[p]  += d[pa[p]];
        return pa[p] = root;
    }
    else
        return p;
}
int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n;++i) {pa[i] = i; d[i] = 0;}
        char op[3];
        int l,r;
        while(scanf("%s", op)==1 && op[0]!='O'){
            if(op[0] == 'E'){
                scanf(" %d", &l);
                findset(l-1);
                printf ("%d\n",d[l-1]);
            }
            else{
                scanf("%d%d", &l, &r);
                pa[l-1] =r-1 ;
                d[l-1] = std::abs(l-r) % 1000;
            }
        }


    }
    return 0;
}
