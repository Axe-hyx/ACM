#include <cstdio>

int N;
#define ss 1001
int lis[ss];
int dup[ss];

int binaryindex(int l, int r, int dup[],int val){
    while(r- l>1){
        int mid = l + (r-l) / 2;
        if(dup[mid] < val){
            l = mid;
        }else
            r =  mid;
    }
    return r;
}

int main(){
    while(scanf("%d", &N) == 1 && N){
        for(int i=0; i<N; ++i) scanf("%d", &lis[i]);
        int len = 1;
        dup[0] = lis[0]; //暂无active list 创建一个
        for(int i=1; i<N; ++i){
            if( lis[i] < dup[0]){
                dup[0] = lis[i];
            }else if(lis[i] > dup[len-1]){
                dup[len++] = lis[i];
            }else{
                dup[binaryindex(0,len-1, dup,lis[i])] = lis[i];
            }
        }
        printf("%d\n",len);
    }


}
