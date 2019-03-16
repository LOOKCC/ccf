//dijkstra use priority queue
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int to;
    int weight;
};

struct node
{
    int v, c;
    node() {}
    node(int _v, int _c){v = _v; c = _c;}
    bool operator<(const node n) const{
        return c > n.c;
    }
};


const int maxn = 1005;
const int maxm = 10005;
const int maxw = 10000005;

int n;
int dis[maxn];
int visited[maxn];
vector<edge> edges[maxn];
priority_queue<node> q;

void dij(int start){
    for(int i=1; i<=n; i++){
        dis[i] = maxw;
        visited[i] = 0;
    }
    visited[start] = 1;
    dis[start] = 0;
    q.push(node(start, 0));
    while(!q.empty()){
        node front;
        front = q.top();
        q.pop();
        int v = front.v;
        if(!visited[v]){
            visited[v] = 1;
            for(int i=0; i<edges[v].size(); i++){
                int v2 = edges[v][i].to;
                if(visited[v2])
                    continue;
                if(dis[v2] > dis[v] + edges[v][i].weight){
                    dis[v2] = dis[v] + edges[v][i].weight;
                    q.push(node(v2, dis[v2]));
                }
            }
        }
    } 
}

int main(){
    cin>>n;
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        edge temp;
        int from;
        cin>>from>>temp.to>>temp.weight;
        edges[from].push_back(temp);
    }
    dij(1);
    //cout  
    return 0;
}