//a template of dijkstra
#include<iostream>
#include<vector>
using namespace std;
int const maxn = 1005; //take 1000 for example
int const maxw = 100005; //take 100000 for example
struct edge{
    int to;
    int weight;
};
int n;
int dis[maxn];
int visit[maxn];
vector<edge> edges[maxn];

void dij(){
    for(int i=1; i<=n; i++){
        visit[i] = 0;
        dis[i] = maxw;
    }
    dis[1] = 0;
    while(1){
        int v = -1;
        for(int i=1; i<=n; i++){
            if(!visit[i])
                if(v == -1 || dis[i] < dis[v])
                    v = i;
        }
        if(v == -1)
            break;
        visit[v] = 1;
        for(int i=0; i<edges[v].size(); i++){
            if(dis[edges[v][i].to] > dis[v] + edges[v][i].weight)
                dis[edges[v][i].to] = dis[v] + edges[v][i].weight;
        }
    }
}

int main(){
    cin>>n;
    int m;
    cin>>n;
    for(int i=0; i<m; i++){
        edge temp;
        int from;
        cin>>from>>temp.to>>temp.weight;
        edges[from].push_back(temp);
    }
    dij();
    cout<<dis[n]<<endl;
    return 0;
}