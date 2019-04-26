#include <cstdio>
#include <math.h>
int main(){
    int N;
    scanf("%d", &N);

    printf("%d=",N);
    for (int i = 2; i <= N; ++i)
    {
        while(N % i == 0){
            N /=i;

           printf("%d",i);
           if(N != 1)
               printf("*");
        }
    }
}
