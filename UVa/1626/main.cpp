#include <cstdio>
#include <cstring>
#define min(a,b) a<b? a:b
#define size 100
#define match(i,j) (ch[i] == '(' && ch[j]==')') \
                           || (ch[i] == ')' && ch[j] == '(') \
                           || (ch[i] == '[' && ch[j] == ']')\
                           || (ch[i] == ']' && ch[j] == '[')
char ch[size];
int dp[size][size];

void dpp(){
    int len = strlen(ch);
    for(int i=len-1;i>=0;--i)
    {
        dp[i+1][i] = 0;
        dp[i][i] =1;
    }
    for(int i=len-1;i>=0;--i){
        for(int j = i+1;j<len;++j){
            dp[i][j] = len;
            if(match(i,j))
                dp[i][j] = min(dp[i+1][j-1], dp[i][j]);
            for(int k=i;k<j;++k){
                dp [i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    }

}
void ans(int i, int j){
    int t = dp[i][j];
    if(i>j) return; //cation here caller: ans(i,i+1) -> callee i>j 特殊判断
    if(i == j)
    {
        if(ch[i] == '(' || ch[i] ==')')
            printf("()");
        else
            printf("[]");
        return;
    }
    if(match(i,j))
        if(t == dp[i+1][j-1]){
            printf("%c", ch[i]); ans (i+1, j-1); printf("%c", ch[j]);
            return;
        }

    for(int k=i;k<j;++k){
        if(t == dp[i][k] + dp[k+1][j]){
            ans(i,k); ans (k+1,j);
            return ; //cation here 只打印一个优解
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        memset(ch, 0, strlen(ch));
        scanf("%s", ch);
        dpp();
        ans(0, strlen(ch)-1);
    }

}
