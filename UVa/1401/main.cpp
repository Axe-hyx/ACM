#include <cstdio>
#include <cstring>
#include <vector>
const int maxn = 300000 + 7;

const int sigma_size = 26;
const int maxnode = 4000 * 100 + 7;
struct Trie{
    int sz;
    char ch[maxnode][sigma_size];
    int val[maxnode];
    int idx(char c){
        return c - 'a';
    }

    void clear(){sz = 1; memset(ch[0], 0, sizeof(ch[0]));}
    void insert(const char *s, int v){
        int n = strlen(s);
        int u = 0;
        for(int i =0;i<n;++i){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val [sz] = 0;
                ch[u][c] = sz++;
            }
            u= ch[u][c];
        }
        val [u] = v;
    }
    void find_prefix(const char * s,std::vector<int> &p){
        int n = strlen(s);
        int u = 0;
        for(int i =0;i<n; ++i){
            if(s[i] == '\0') break;
            int c = idx(s[i]);
            if(!ch[u][c]) // 还没到结尾
                break;
            u  = ch[u][c];
            if(val[u]) p.push_back(val[u]);
        }
    }
};

char text[maxn];
const int maxw = 100 + 7;
char word[maxw];
int S;
int d[maxn];
struct Trie trie;
int main(){
    int kase =0;
    while(scanf("%s%d", text, &S)==2){
        trie.clear();
        for(int i =0;i<S; ++i){
            scanf("%s", word);
            int n = strlen(word);
            trie.insert(word, n);
        }
        memset(d, 0, sizeof(d));
        int L = strlen(text);
        d[L] =1;
        for(int i = L-1; i>=0;--i){
            std::vector<int > p;
            trie.find_prefix(text+i,p);
            for(int j = 0;j<(int)p.size(); ++j){
                d[i] = (d[i] + d[i+p[j]]) % 20071027;
            }
        }
        printf("Case %d: %d\n",++kase,d[0]);

    }
    return 0;
}

