#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    bool is =false;
    for(int i = 2; i*i<= n;++i)
    {
        if(n % i == 0 )
            is = true;
    }
    if(is)
        printf("\\n");
    else
        printf("\\t");
    //printf(is ? "\\n" : "\\t");
}
