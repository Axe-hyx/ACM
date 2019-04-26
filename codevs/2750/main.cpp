#include <cstdio>

int main(){
    long int m;
    int n;
    scanf("%ld %d", &m,&n);
    printf("%ld", (long int)m /n + (m %n == 0 ? 0:1));
}
