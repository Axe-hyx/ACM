#include <cstdio>
#include <cstring>

int N;
const int maxnode = 4000 * 1000 + 7;
const int maxlen = 1000 + 7;
const int maxn = 4000 + 7;
struct Trie{
    int val [maxn], flag[maxn];
    int ch[maxnode][70];
    int sz;
    int idx(char c){
        if(c == '\0') return 68;
        return c -'A';
    }

    void clear(){sz = 1; memset(ch, 0, sizeof(ch)); memset(flag, 0, sizeof(flag));memset(val, 0, sizeof(val));}

    void insert(const char * s, int &v){
        int u = 0;
        int n = strlen(s);

        for(int i = 0; i<n; ++i){
            int c = idx(s[i]);
            v += val[ch[u][c]] * 2;

            if(!ch[u][c]){
                ch[u][c] = sz++;
                val[ch[u][c]] = 1;
            }else
                val[ch[u][c]]++;
            u = ch[u][c];
        }
        flag[u]++;
        v += flag[u] -1;
    }


};
Trie trie;
char str[maxlen];
int main(){
    int kase=0;
    while(scanf("%d", &N) && N){
        trie.clear();
        long long ans = 0;
        for(int i=0; i<N; ++i){
            scanf("%s", str);
            int val = 0;
            trie.insert(str, val);
            ans += val +i;
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}
