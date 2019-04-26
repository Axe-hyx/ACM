#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n){
        bool found = false;
        int t = n;
        for(int k =2; k*k <= t; ++k){
            int nums = 0;
            if(n%k == 0){
                if(found) printf("*");
                while(n%k == 0)
                {
                    n /=k;
                    ++nums;
                    found = true;
                }
                if(nums > 1)
                    printf("%d^%d",k, nums);
                else if(found)
                    printf("%d",k);
            }
        }
        if(n!=1){
            if(found)
                printf("*");
            printf("%d",n);
        }
        printf("\n");
    }
}
