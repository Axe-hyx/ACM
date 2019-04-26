#include <cstdio>
#include <cmath>
int main(){
    long int n;
    scanf("%ld", &n);

    for(int i = 2;i*i< n;++i)
    {
        if(n % i  ==0)
        {
            printf("%ld", n/i);
            break;
        }
    }
}
