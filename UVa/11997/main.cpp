#include <cstdio>
#include <queue>
#include <algorithm>
struct Item{
    int s,b;
    Item(int s,int b): s(s), b(b){}
    bool operator <(const struct Item &t)const {
        return s>t.s;
    }

};
void merge(int *A, int *B, int *C, int n){
    std::priority_queue<Item> pq;
    for(int i= 0;i<n;++i){
        pq.push(Item(A[i]+B[0],0));
    }
    for(int i =0;i<n;++i){
        Item t = pq.top();
        pq.pop();
        C[i] = t.s;
        int b = t.b;
        if(b+1<n) pq.push(Item(t.s-B[b]+B[b+1],b+1));
    }
}
int n;
const int maxn = 769;
int A[maxn][maxn];
int main(){
    while(scanf("%d", &n)==1){
        for(int i =0;i<n;++i){
            for(int k=0;k<n;++k)
                scanf("%d", &A[i][k]);
            std::sort(A[i],A[i]+n);
        }

        for(int i=0; i<n-1;++i){
            merge(A[0],A[i+1],A[0],n);
        }

        printf("%d",A[0][0]);
        for(int i=1;i<n;++i){
            printf(" %d", A[0][i]);
        }
        printf("\n");
    }
    return 0;
}
