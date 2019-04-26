#include <cstdio>
#include <algorithm>

int n;
using namespace std;
#define ss 1005
int binarylower(int l, int r, int arr[], int val){
    while(r-l > 1){
        int mid = l + (r-l) /2;
        if(arr[mid] >= val)
            r = mid;
        else
            l = mid;
    }
    return r;
}
int binaryupper(int l, int r, int arr[], int val){
    while(r - l > 1){
        int mid= l+ (r-l) /2;
        if(arr[mid] >= val)
            l = mid;
        else
            r = mid;
    }
    return r;
}
float array[ss];
int la[ss];
int ra[ss];
int main(){
    while(scanf("%d", &n) == 1 &&n){
        int len,llen;
        int mm;
        for(int i=0; i<n; ++i)scanf("%f", &array[i]);
        for(int i =1;i<n-1;++i){
            la[0] = array[0];
            int len = 1;
            for(int k=1; k<=i;++k ){
                if(array[k] < la[0])
                    la[0] = array[k];
                else if(array[k] > la[len-1])
                    la[len++] = array[k];
                else
                    la[binarylower(0, len-1, la, array[k])] = array[k];
            }

            int llen = len;
            len = 1;
            ra[0] = array[i];
            for(int k=i+1; k<n;++k){
                if(array[k] > ra[0])
                    ra[0] = array[k];
                else if(array[k] < ra[len-1])
                    ra[len++] = array[k];
                else
                    ra[binaryupper(0,len-1 ,ra, array[k])] = array[k];
            }
            mm = max(n-llen-len + 1,mm);
        }
        printf("%d\n", mm);
    }
    return 1;
}
