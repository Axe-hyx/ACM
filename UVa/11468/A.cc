#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int T, K, N, L;
const int maxnode = 410;

const int sig_size = 70;
const int MAXS = 21;

char p[MAXS][MAXS];


float fre[sig_size];
int id[256];
int idx(char c);
struct AC{
	int val[maxnode];
	int ch[maxnode][maxnode];
	int last[maxnode];
	int f[maxnode];
	int sz;


	void print(int j){
		if(j){
			printf("%d \n", j);
			print(last[j]);
		}
	}

	void init(){
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
	}
	void find(char *T){
		int n = strlen(T);
		int j = 0;
		for(int i=0; i<n; ++i){
			int c = idx(T[i]); 			
 			while(j && !ch[j][c]) j = f[j];

 			j = ch[j][c];

 			if(val[j])
 				print(j);
 			else if(last[j])
 				print(last[j]);
		}		
	}
	void getFail(){
		queue<int> q;
		for(int i=0;i<sig_size; ++i){
			int u = ch[0][i];
			if(u) { q.push(u); }
		}		
		while(!q.empty()){
			int p = q.front(); q.pop();
			for(int i=0;i<sig_size; ++i){
				int u = ch[p][i];
				if(!u) continue;
				q.push(u);
				int v = f[p];
				while(v && !ch[v][i]) v = f[v];
				f[u] = ch[v][i];
				last[u] = val[f[u]] ? f[u]: last[f[u]];
			}		
		}
	}

	void insert(char *s, int v){
		int u = 0, n = strlen(s);
		for(int i=0; i<n; ++i){
			int c = id[s[i]];
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}		
			u = ch[u][c];
		}
		val[u] = v;
	}
};
AC ac;

double d[maxnode][105];
int vis[maxnode][105];
double dfs(int u,int l){
	if(!l) return 1.0;
	if(vis[u][l]) return d[u][l];
	vis[u][l] = 1;
	double &ans = d[u][l];
	ans = 0.0;
	for(int i=0; i<N ; ++i){
		if(ac.val[ac.ch[u][i]] == 0) ans += fre[i] * dfs(ac.ch[u][i], l-1);
	}
	return ans;
}

int main(){
	int kase =0;
	scanf("%d", &T);
	while(T--){

		scanf("%d", &K);
		ac.init();
		memset(vis, 0, sizeof(vis));
 		for(int i = 1; i<=K; ++i){
 			scanf("%s", p[i]);
 			ac.insert(p[i], i);
 		}
 		scanf("%d", &N);
 		char c[2];        
		for(int i=0; i<N; ++i){
			scanf("%s %f", c, &fre[i]);
			id[c[0]]  = i; //for indexing the array element when travesal
		}
		ac.getFail();
		scanf("%d", &L);
		printf("Case #%d : %.6lf\n", kase++, dfs(0, L));
	}
	return 0;
}                                            