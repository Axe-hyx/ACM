#include <cstdio>
#include <queue>
int n;
int time, period;
struct Item{
    int priod, num,time;
    bool operator <(const struct Item& l)const {
        return time > l.time || (time == l.time && num > l.num);
    }
};

int main(){
    char s[20];
    std::priority_queue<Item> pq;
    int l;
    while(scanf("%s", s) && s[0]!= '#'){
        struct Item t;
        scanf("%d %d", &t.num, &t.priod);
        t.time = t.priod;
        pq.push(t);
    }
    scanf("%d", &l);
    for(int i =0; i<l; ++i){
        Item t = pq.top();
        printf("%d\n", pq.top().num);
        pq.pop();
        t.time +=t.priod;
        pq.push (t);
    }
    return 1;
}
