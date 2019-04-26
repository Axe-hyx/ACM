#include <cstdio>

int main(){
    int f[41];
    f[0] =1;
    f[1] =1;
    for(int i = 2; i<41;++i)
    {
        f[i] = f[i-1] + f[i-2];
    }

    int n;
    scanf("%d", &n);
    printf("%d",f[n-1]);
}
