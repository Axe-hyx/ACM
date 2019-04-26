#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define size 51
#define INF 0x3f3f3f3f

const double le = 1e-6;
using namespace std;
struct pos{
    double x;
    double y;
};

struct pos cor[size];
double dp[size][size];
int s;
double S(int i, int k, int j){
    return fabs( (cor[k].x-cor[i].x) * (cor[j].y - cor[i].y) - (cor[j].x - cor[i].x) * (cor[k].y-cor[i].y) ) /2.0;

    return (cor[i].x * cor[k].y + cor[j].x * cor[k].y + cor[k].x * cor[i].y -
            cor[i].x * cor[k].y -cor[k].x * cor[i].y - cor[j].x * cor[j].y)/2;

}

bool judge(int i, int k, int j){
    for(int p=0; p<s; ++p){
        if(p == i || p == k || p ==j)
            continue;
        double s = S (i, j, p) + S (j, k, p) + S(k, i, p);
        if(fabs(s - S(i, j, k)) < le)
            return true;

    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &s);
        for(int i=0; i<s;++i)
            scanf("%lf %lf", &cor[i].x, &cor[i].y);
        memset(dp, 0, sizeof(dp));

        /*
        for (int l=2;l<n-1;++l){
            for(int p=0;p+l<n;++p){
                dp[p][p+1] = INF;
                for(int k=p+1; k< p+l; ++k){
                    if(judge(p, k, p+l) )continue;
                    dp[p][p+l] = min(dp[p][p+l], max(dp[p][k], max(dp[k][p+l], S(p, k, p+l))));
                }
            }
        }
        */
        for(int i=0; i<s-2; ++i){
            for(int j=i+2;j<s;++j){
                dp[i][j] = INF;
                for(int k=i+1;k<j;++k){
                    if(judge(i, k, j)) continue;
                    dp [i][j] = min( dp[i][j],
                            max(dp[i][k],max(dp[k][j], S(i,k,j))));
                }
            }
        }

        printf("%.1f\n", dp[0][s-1]);

    }
}
