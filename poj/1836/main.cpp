#include <cstdio>
#include <algorithm>
#define ss 1001

float le[ss];
float ri[ss];
float so[ss];
int dpl[ss];
int dpr[ss];

using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) ==1 && n){
        int ltop=0;
        int rtop= 0;
        for(int i=0; i<n; ++i) scanf("%f", &so[i]);

        le[0] = 0;
        for(int i=0; i<n;++i){
            if(so[i]>le[ltop])
                le[++ltop] = so[i];
            else{
                int l=1, r=ltop;
                while(l<=r){
                    int mid = l + (r-l) /2;
                    if(le[mid] >= so[i]){
                        r = mid -1;
                    }else
                        l = mid +1;
                }
                le[l] = so[i];
            }
            dpl[i]=ltop;
        }

        ri[0] = 0;
        for(int i=n-1; i>=0;--i){
            if(so[i] > ri[rtop])
                ri[++rtop] = so[i];
            else{
                int l= 1,r = rtop;
                while(l<=r){
                    int mid = l +(r-l) /2;
                    if(ri[mid] >= so[i])
                        r = mid- 1;
                    else
                        l = mid+1;

                }
                ri[l] = so[i];
            }
            dpr[i] = rtop;
        }
        int ans= 0;
        for(int i =0;i<n;++i){
            for(int j = i+1;j<n;++j){
                ans = max(dpl[i]+dpr[j], ans);
            }
        }
        printf("%d\n",n-ans);
    }
}
