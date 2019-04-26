#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 40000 + 10;
const int xe = 123;

int n, m, pos;


unsigned long long x[maxn], H[maxn];
int Rank[maxn];
unsigned long long hash[maxn];

int cmp(const int &a, const int &b){
	return hash[a] < hash[b] || (hash[a] == hash[b] && a<b);
}

int possible(int L){
	pos = -1;
	int c = 0;
	for(int i =0;i <n-L+1; ++i){
		Rank[i] = i;
		hash[i] = H[i] - H[i+L] * x[L];
	}
	sort(Rank, Rank+n-L+1 ,cmp);

	for(int i =0;i<n-L+1;++i){
		if(i==0 || hash[Rank[i-1]] != hash[Rank[i]]) c = 0;
		if(++c>=m) pos = max(pos, Rank[i]);
	}
	return pos >=0 ;

}
char s[maxn];
int main(){
	while(scanf("%d", &m) == 1 &&m){
		scanf("%s", s);
		n =(int)strlen(s);
		
		H[n] = 0;
		for(int i=n-1; i>=0; i--) H[i] = H[i+1] * xe + (s[i]-'a');
	
		x[0] = 1;
		for(int i=1; i<=n; ++i) x[i] = xe * x[i-1];


		if(!possible(1)){printf("none\n");}
		else{
			int L = 1, R = 1+n;
			while(R-L > 1){
				int M = L + (R-L) /2;
				if(possible(M)) L = M;
				else
					R = M;
			}
			possible(L);
			printf("%d %d\n", L, pos);
		}
	}
	return 0;
}