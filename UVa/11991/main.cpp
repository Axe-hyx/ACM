#include <cstdio>
#include <vector>
#include <map>
int l, r;
int t;
int main(){
    while(scanf("%d%d", &l, &r)==2){
        std::map<int ,std::vector<int >> map;
        for(int i=0;i<l;++i){
            scanf("%d", &t);
            if(!map.count(t)){
                std::vector<int > v;
                v.push_back(i);
                map[t] = v;
            }else
                map[t].push_back(i);
        }
        int var,pos;
        for(int i=0; i<r;++i){
            scanf("%d%d", &pos, &var);
            if(map.count(var) && (int)map[var].size() >=pos){
                printf("%d\n", map[var][pos-1]+1);
            }
            else{
                printf("0\n");
            }
        }
    }
}
