#include <cstdio>
#include <vector>
#include <cstring>
const int maxn = 17;
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int board[maxn][maxn];
int dir[4][2] = {0,0, 0,-1, -1,0, 0,1};

int flip[maxn][maxn]; 
int ans [maxn][maxn]; 

void print(){
  for(int i=0;i<m;++i){
    printf("%d", ans[i][0]);
    for(int k=1; k<n; ++k)
     printf(" %d", ans[i][k]);
    printf("\n");
    
  }
}

int get (int x, int y){      
  int c = board[x][y];
  for(int i =0;i<4;++i){
   int dx = x + dir[i][0];
   int dy = y + dir[i][1];
   if(dx >=0 && dy>=0 && dx <n)
     c += flip[dx][dy];
  }
  return (c&1);
}

int calc(){
  int count =0;
  for(int i =1;i<m;++i){
    for(int k=0; k<n;++k){
      if(get(i-1,k)){
        flip[i][k] = 1;
    	++count;
      }
    }
  }
  for(int i=0; i<n; ++i){
    if(get(m-1,i)) return 0;
  }
  for(int i=0;i<n;++i){
    count += flip[0][i];
  }
  return count; 
}

void dowork(){
    int num = INF;
    for(int i=0; i<(1<<n);++i){
      memset(flip, 0, sizeof(flip));
      for(int j=0; j<n; ++j){
        flip[0][n-j-1]= i>>j &1;
      }
      int cnt = calc();
      if(cnt <num && cnt !=0){
        num = cnt;
	memcpy(ans, flip, sizeof(flip));
      }
    }  
    if(num == INF){
      printf("IMPOSSIBLE\n");
    }else{
      print();
    }
}
int main(){

  while(scanf("%d%d", &m, &n) ==2 ){
    for(int i=0; i<m; ++i){
      for(int k=0; k<n; ++k){
        scanf("%d", &board[i][k]);
      }
    } 
    dowork();
  }
  return 0;                       	
}