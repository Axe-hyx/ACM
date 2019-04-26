#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
const int maxn = 1001 * 100 + 10;

struct SA{
	int sa[maxn], t[maxn], t1[maxn];
	int c[maxn], rank[maxn], height[maxn];
	int s[maxn];
	int n;
	void init(){
		n = 0;
		memset(sa, 0, sizeof(sa));
	}
	void build_sa(int m){
		int i;
		int *x = t, *y = t1;
		for(i = 0; i<m; ++i) c[i] = 0;
		for(i = 0; i<n; ++i) c[x[i] = s[i]]++;
		for(i = 1; i<m; ++i) c[i] += c[i-1];
		for(i = n-1; i>=0; --i) sa[ --c[x[i]]] = i;

		for(int k =1; k<=n ; k<<=1){
		  int p = 0;
		  for(i = n-k; i<n; ++i) y[p++] = i;
		  for(i = 0; i<n; ++i) if(sa[i] >=k) y[p++] = sa[i] -k;

			for(i = 0; i<m; ++i) c[i] = 0;
			for(i = 0; i<n; ++i) c[x[y[i]]]++;
			for(i = 1; i<m; ++i) c[i] += c[i-1];
			for(i = n-1; i>=0; --i) sa[ --c[x[y[i]]]] = y[i];

			swap(x,y);
			p = 1;
			x[sa[0]] = 0;
			for (i=1; i<n; ++i)
				x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1: p++;
			if(p>=n) break;
			m = p;
		}
	}

	void get_Height(){
		int i, k=0;
		for(i =0; i<n; ++i) rank[sa[i]] = i;
		for(i =0; i<n; ++i){
			if(k) --k;
			int j = sa[rank[i]-1];
			while(s[i+k] == s[j +k] ) ++k;
			height[rank[i]]= k;
		}
	}
};

SA sa;

int n;
const int maxc = 1000 + 10;
const int maxk = 100 + 10;
int idx[maxn];
char S[maxc];
int flag[maxk];
void add(int  c, int id){
	idx[sa.n] = id;
	sa.s[sa.n++] = c;
}


bool good(int L, int R){
	if(R-L <= n/2) return false;

	int cnt =0;
	memset(flag, 0, sizeof(flag));
	for(int i =L; i<R; ++i){
		int x = idx[sa.sa[i]];
	 	if(x!=n && !flag[x]){
	 		flag [x] = 1;
	 		cnt++;
	 	}
	}
	return cnt > n/2;
}
void print_sol(int L, int R){
	for(int i =L; i<R; ++i){
		printf("%c", sa.s[i] + 'a' -1);
	}
	printf("\n");
}
bool print_solutions(int len, bool print){
	int L = 0;
	for(int R =1; R<=sa.n; ++R){
		if( R==sa.n || sa.height[R] < len){
			if(good(L,R)){
				if(print) print_sol(sa.sa[L], sa.sa[L] + len);
				else return true;
			}
			L = R;
		}
	}

	return false;
}
void solve(int maxlen){
	if(!print_solutions(1,false)){
		printf("?\n");
	}else{
		int L = 1, R = maxlen, M;
		while(L < R){
			M = (R-L +1 ) /2 + L; //cation here the binary search
			if(print_solutions(M, false))
				L = M;
			else
				R = M -1;
		}
		print_solutions(L,true);
	}
}
int main(){
	int kase = 0;
	while(scanf("%d", &n) ==1 && n){
		if(kase++ > 0)
			printf("\n");
		sa.init();
		int maxlen = 0;
		for(int i=0; i<n; ++i){
			scanf("%s", S);
			int len = (int)strlen(S);
			maxlen = max(maxlen, len);
 			for(int j=0; j<len; ++j)
 				add(S[j] - 'a' +1, i);
 			add(100 + i,n);
		}
		add(0,n);
//		printf("%s\n", sa.s);
		if(n == 1) printf("%s\n", S);
		else{
			sa.build_sa(100 +n);
			for(int i =0; i<sa.n;++i){
	//			printf("%d\n", sa.sa[i]);
			}
			sa.get_Height();
			for(int i =0; i<sa.n; ++i){
//				printf("%d\n", sa.height[i]);
			}
			solve(maxlen);
		}
	}
	return 0;
}
