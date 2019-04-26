#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define size 1001

using namespace std;

struct cor{
    int x;
    int y;
    bool operator < (const cor& b){
        return x < b.x;
    }
};

int vis[size];
float dp[size][size];
int n;
struct cor xy[size];

float dist(int i1, int i2)
{
    return sqrt( (xy[i1].x - xy[i2].x) * (xy[i1].x - xy[i2].x)
                + (xy[i2].y - xy[i1].y) * (xy[i2].y - xy[i1].y)
            );
}

float dpp(int i, int j){
    float ans = dp[i][j];
    if(vis[i])
        return ans;
    vis[i] = 1;
    if(i == n-2)
        return dist(n-1, n-2) + dist(j,n-1);
    ans = max(ans, max(dpp(i+1, j) + dist(i, i+1), dpp(i+1,i) + dist(j, i+1)));
    return ans;

}

int main(){
    while(scanf("%d", &n)==1 && n){
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; ++i){
            scanf("%d %d", &xy[i].x, &xy[i].y);
        }
       sort(xy, xy+n);

       float ans = dpp(0,1) + dist (0,1);

       printf("%.2f\n", ans);


    }
    return 1;
}
