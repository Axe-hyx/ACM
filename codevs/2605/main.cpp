#include <cstdio>
#include <cstring>


int main(){
    unsigned long long x = 1UL<<32;

    bool b[4294967297];


    memset(b, 0, sizeof(b));
    int n;
    scanf("%d",&n);
    unsigned int c;
    while(n--){
        scanf("%u",&c);
        //        printf("%u",c);
        //b[(unsigned int)c] = !b[(unsigned int)c];
        b[c] = !b[c];
    }

    for(int i = 0;i< 65536;++i)
    {
        if(b[i]){
            if(i> (1>>31))
                printf("%d", i - (1<<31));
            else printf("%d", i);
        }
    }
}


/*
#include <cstdio>
#include <cstring>


int main() {

    int ans = 0;
    int n;
    scanf("%d", &n);
    while (n--){
        int c;
        scanf("%d",&c);
        ans ^=c;
    }
    printf("%d",ans);
}
 * */
