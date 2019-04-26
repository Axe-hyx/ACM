#include <cstdio>

#define bit(var,pos) ((var)&(unsigned)(1<<pos))
#define min(a,b ) a<b ? a: b
int ans = 17;
void solve(unsigned int &u, int res)
{
    if(u == 0 || u == (unsigned)(~0)>>16){
        printf("%d",res);
        ans = min(ans, res);
        return;
    }
    if(res > ans)
        return;
    for(int i = 0; i < 16; ++i)
    {
        unsigned int t = u;
        if((u & (1<<i)) == (unsigned)(1<<i))
        {
            if(i>3 && bit(u,(i-4)))
                t &= 1<<(i-4);
            if(i<12 && bit(u,(i+4)))
                t &= 1<<(i+4);
            if(i % 4 ==0  && bit(u,(i+1)))
                t &= 1<<(i+1);
            if(i % 4 ==3  && bit(u,(i-1)))
                t &= 1<<(i-1);

        }
        else{

            unsigned int t = u;
            if(i>3 && bit(u,(i-4)))
                t &= ~(1<<(i-4));
            if(i<12 && bit(u,(i+4)))
                t &= ~(1<<(i+4));
            if(i % 4 ==0  && bit(u,(i+1)))
                t &= ~(1<<(i+1));
            if(i % 4 ==3  && bit(u,(i-1)))
                t &= ~(1<<(i-1));

        }
        solve(t,res+1);
    }
}

int main()
{
    unsigned int u = 0;

    char  c;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(scanf("%c",&c)==1 && c =='b')
                u |= (1<<(4 *i +j));

        }
        c =getchar();
    }
    int res =0;

    solve(u, res);

}
