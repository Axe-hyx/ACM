#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 7;

int f[maxn];
int n;
char p[maxn];
int main(){
	scanf("%d", &n);
	f[0] = f[1] =0;
	while(n--){
		scanf("%s", p);
		int m = strlen(p);
		for(int i=1; i<m;++i){
			int j = f[i];
			while(j && p[i] != p[j]) j = f[j];
			f[i+1] = (p[i] == p[j] ? j + 1 : 0);//already count the f[m]
		}
		
		for(int i =2; i<=m; ++i){
			if(f[i] > 0 && (i % (i-f[i])==0)) printf("%d %d\n", i, i/(i - f[i]));
		}		
	}
	return 0;
}