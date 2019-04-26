#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

const int maxnode = 17;
int n;
int a[maxnode];
int find (int i, int k){
    int j =1;
    while(j < i){
        if(a[j] == k || abs(j - i) == abs(k - a[j]))
            return 0;
        ++j;
    }
    return 1;
}
int ans = 0;
int solve(int i, int n){
    if(i >n) {
        ++ans;
        return 1;
    }
    int k =1;
    while(k <=n){
        if(find(i,k)){
            a[i] = k;
            solve(i+1, n);
            printf("%d %d \n", i, k);
        }
        ++k;
    }
}
int main(){
    solve(1,8);
    printf("%d\n",ans);
    return 0;
}
