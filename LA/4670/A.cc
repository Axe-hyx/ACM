#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
using namespace std;
int n;

const int maxn = 1e6 + 7;
const int lens = 70 + 1;
const int sig_size  = 26;
const int maxnode = 11000;
const int MAXS = 150 + 7;

char str[maxn], p[151][lens];
struct AC{
	int sz;
	int val[maxn], last[maxn];
	int ch[maxnode][sig_size];
	int cnt[MAXS];
	int f[maxnode];
	map<string, int> m;
	
	int idx (char c){ return c-'a';}

	void find (const char *T){
		int	len = strlen(T);
		int j = 0; 
		for(int i =0; i<len; ++i){
			int c = idx(T[i]);
			while(j && !ch[j][c]) j = f[j]; //to do
			j = ch[j][c]; // find previous match position

			if(val[j]) print(j);
			else print(last[j]);
		}
	}
	void insert(char *s, int v){
		int n = strlen(s);
		int u =0;
		for(int i=0; i<n; ++i){
			int c = idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
		m[string(s)] = v;

	}
	void print(int j){ //to do
		if(j){
//			print(last[j]);
//			printf("%c", );
				cnt[val[j]]++;
				print(last[j]);
		}	
	}
	void init(){
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(cnt, 0, sizeof(cnt));
		m.clear();

	}
	void getFail(){
		queue<int > q;
		f[0] = 0;
		for(int i =0;i<	sig_size; ++i){
				int u = ch[0][i];
				if(u){f[u]=0; q.push(u);}
		}		
		while(!q.empty()){
				int p = q.front(); q.pop();
				for(int c=0; c<sig_size; ++c){
					int u = ch[p][c];
					if(!u) continue;
					q.push(u);

					int v = f[p];
					while(v && !ch[v][c]) v = f[v];        //to do
					f[u] = ch[v][c];
					last[u] = val[f[u]] ? f[u] :last[f[u]];
				}
			}
	}
	
};

AC ac;
int main(){
	while(scanf("%d",&n) ==1 && n){
		ac.init();
		for(int i =1; i<=n; ++i){
			scanf("%s", p[i]);
			ac.insert(p[i],i);
		}
		ac.getFail();
		scanf("%s", str);
		ac.find(str);

		int ans = 0;
		
		for(int i=0;i<n;++i){
			if(ans < ac.cnt[i]) ans  = ac.cnt[i];
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i){
			if(ac.cnt[ac.m[string(p[i])]] == ans) printf("%s\n",p[i]);
		}

	}
	return 0;
}