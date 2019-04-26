#include <cstdio>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int maxnode = 1e4 + 7;
const int maxn = 1007;
const int maxx = 107;
const int sig_size = 26;
void process_match(int pos, int v);
int cur;
struct AC{
	int val[maxnode];
	int f[maxnode];
	int last[maxnode];
	int ch[maxnode][sig_size];
	int sz;

	void init(){
		memset(ch[0], 0, sizeof(ch[0]));
		sz = 1;
	}
	void insert(char *s, int v){
	  int n = strlen(s);
	  int u =0;
	  for(int i =0; i<n; ++i){
			int c = idx(s[i]);
			if(!ch[u][c]){
			   memset(ch[sz], 0, sizeof(ch[sz]));
			   val[sz] = 0;
			   ch[u][c] = sz++;
			}
			u = ch[u][c];
	  }
	  val[u] = v;
	}

	void print(int pos, int j){
		if(j){
			// get the line number
			process_match(pos,j);
			print(pos,last[j]);           
		}	
	}
	int idx(char c){
		return c- 'a';
	}
	void find(char *T){
		int n = strlen(T);
		int j =0;
		for(int i =0; i< n; ++i){
			int c = idx(T[i]);
			while(j && !ch[j][c]) j = f[j];
			j = ch[j][c];

			if(val[j]) print(i,val[j]);
			else if(last[j]) print(i,val[last[j]]);			
		}	
	}
	void getFail(){
		queue<int > q;
		f[0] = 0; // initialize
		for(int i =0; i<sig_size; ++i){
			int u = ch[0][i];
			if(u) { val[u] = 0; f[u]= 0; q.push(u);}
		}	
		while(!q.empty()){
			int p =q.front(); q.pop();
			for(int i =0; i<sig_size; ++i){
				int u = ch[p][i];
				if(!u) continue;
				q.push(u);

				int v = f[p];
				while(v && !ch[v][i]) v = f[v];

				f[u] = ch[v][i];
				last[u] = val[f[u]] ? f[u] : last[f[u]];
			}
		}
	}
};
AC ac;

int x,y, n,m,kase;
char T[maxn][maxn];
char P[maxx][maxx];
int  count [maxn][maxn];

int next [maxx];
int repr [maxx];
int lens [maxx];

void process_match(int pos, int v){ // find the line number;;
	int p = repr[v-1]; //find the match line
	int col = pos - lens[p] + 1;
	while(p!=-1){
		if(cur >=p)
			count[cur-p][col]++;
		p = next[p];
	}
}

int main(){
	scanf("%d", &kase);
	while(kase--){

	//	initialize
		memset(count, 0, sizeof(count));
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i){
			scanf("%s", T[i]);
		}
		ac.init();
		scanf("%d %d", &x, &y);

		for(int i=0; i<x; ++i){
			scanf("%s", P[i]);
			repr[i] = i;
			next[i] = -1;
			lens[i] = strlen(P[i]);
			for(int j=0;j<i;++j){
				if(strcmp(P[i], P[j]) == 0){
					repr[i] = j;
					next[i] = next[j];
					next[j] = i;
					break;
				}
			}
			if(repr[i] == i) {ac.insert(P[i], i+1);// remove the duplicates 
			}
		}
		ac.getFail();
		for(int i = 0; i<n; ++i){
			cur = i;
			ac.find(T[i]);
		}

		int ans =0;
		for(int i =0;i<n; ++i){
			for(int k=0; k<m;++k){
				if(count[i][k] == x){
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}