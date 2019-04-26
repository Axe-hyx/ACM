#include <cstdio>
int n;
int main(){
    while(scanf("%d", &n) ==1 && n){
        int nums  = 0;
        while(n!=1){
            if(n %2 == 0){
                n = n>>1;
            }else
                n = (3 *n +1 ) /2;
            ++nums;
        }
        printf("%d\n",nums);
    }
}
