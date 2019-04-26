#include <cstdio>
#include <algorithm>
#define maxn 10000

using namespace std;

int main()
{
    int n, m;
    int kase = 0;
    while(scanf("%d %d", &n, &m) == 2 && n){
        printf("CASE# %d:\n", ++kase);
        int st[maxn];
        for(int i = 0;i < n; ++i) scanf("%d", &st[i]);
        sort(st, st+n);

        int t;
        for(int i = 0;i < m; ++i)
        {
            scanf("%d",&t);
            int l = 0, r = n-1;
            int mid;
            while(l<=r)
            {
                mid = l + (r-l)/2;
                if(st[mid]==t)
                    break;
                else if(st[mid] > t)
                    r = mid -1;
                else l = mid +1;
            }
            if(st[mid] == t)
                printf("%d found at %d\n", t, mid+1);
            else printf("%d not found\n", t);
        }

    }

}
