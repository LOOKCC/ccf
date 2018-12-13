#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
    int from;
    int to;
    int cost;
    friend bool operator <(const edge a, const edge b){
        return a.cost<b.cost;
    }
};
const int maxn = 100005;
const int maxe = 200005;
int cost = 0 ;
int flag[maxn];
edge map[maxe];
int n,m;
int get_root(int x){
    if(flag[x] == x)
        return x;
    else
        return flag[x] = get_root(flag[x]);
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        struct edge temp;
        temp.to = to;
        temp.cost = cost;
        temp.from = from;
        map[i] = temp;
    }
    for(int i=0; i<maxn; i++){
        flag[i] = i;
    }
    sort(map, map+m);
    for(int i=0; i<m; i++){
        int x = get_root(map[i].from);
        int y = get_root(map[i].to);
        if(x != y){
            if(x > y)
                flag[x] = y;
            else
                flag[y] = x;
        }
        cost = map[i].cost;
        if(get_root(n) == 1) break;
    }
    cout<<cost<<endl;
    return 0;
}