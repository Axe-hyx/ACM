#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxnode  = 17;

int n;
char bo[maxnode][maxnode];
int b[maxnode];
int vaild(int row,int k){
    for(int i=0; i<n;++i){
        if(b[i] == k || abs(row- i) == abs (k - b[i]) || bo[row][k]=='*'){
            return 0;
        }
    }
    return 1;
}
void queue(){
    int i=0, j=0;
    int ans = 0;
    while(i<n){
        while(j<n){
            if(vaild(i,j)){
                b[i] = j;
                j = 0;
                break;
            }else
                ++j;
        }
        if(b[i] == -1){
            if(i == 0){
                break;
            }else{
                --i;
                j = b[i] +1;
                b[i] = -1;
                continue;
            }
        }
        if(i == n-1){
            ans ++;
            j = b[i] + 1;
            b[i] = -1;
            continue;
        }
        ++i;
    }
    printf("%d\n", ans);
}

int main(){
    int kase = 0;
    while(scanf("%d", &n)&&n){
        for(int i=0; i<n; ++i){
            scanf("%s", bo[i]);
        }
        memset(b, -1, sizeof(b));
        printf("Case %d: ", ++kase);
        queue();

    }
    return 0;
}
