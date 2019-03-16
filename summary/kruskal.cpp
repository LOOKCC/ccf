#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
    int from;
    int to;
    int weight;
    friend bool operator < (const edge a, const edge b){
        return a.weight < b.weight;
    }
};
const int maxn = 1005;
const int maxm = 1005;
const int maxw = 1000005;
int n,m;
int flag[maxn];
edge edges[maxm];
int get_root(int x){
    if(flag[x] == x)
        return x;
    else
        return flag[x] = get_root(flag[x]);
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>edges[i].from>>edges[i].to>>edges[i].weight;
    }
    for(int i=0; i<=n; i++){
        flag[i] = i;
    }
    sort(edges, edges+m);
    for(int i=0; i<m; i++){
        int x = get_root(edges[i].from);
        int y = get_root(edges[i].to);
        if(x!=y){
            if(x < y)
                flag[y] = x;
            else
                flag[x] = y;
        }
        if(get_root(n) == 1) break;
    }
    //do something you want
    return 0;
}