#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int const maxn = 10005;
// int const maxm = 10005;
int const maxw = 1005;

struct node
{
    int u;
    int c;
    node(){}
    node(int _u, int _c){u = _u; c = _c;}
    bool operator<(const node n)const {
        return c > n.c;
    }
};


struct edge{
    int to;
    int weight;
};

int n;
int dis[maxn];
int visit[maxn];
int cost[maxn];
vector<edge> edges[maxn];
priority_queue<node> q;

void dij(){
    for(int i=1; i<=n; i++){
        visit[i] = 0;
        dis[i] = maxw;
        cost[i] = maxw;
    }
    dis[1] = 0;
    cost[1] = 0;
    q.push(node(1,0));

    node temp;
    while(!q.empty()){
        temp = q.top();
        q.pop();
        int v = temp.u;
        if(!visit[v]){
            visit[v] = 1;
            for(int i = 0; i<edges[v].size(); i++){
                int v2 = edges[v][i].to;
                if(visit[v2])
                    continue;
                
                if(dis[v2] > dis[v] + edges[v][i].weight){
                    dis[v2] = dis[v] + edges[v][i].weight;
                    cost[v2] = edges[v][i].weight;
                    q.push(node(v2, dis[v2]));
                }else if(dis[v2] == dis[v] + edges[v][i].weight){
                    cost[v2] = min(cost[v2], edges[v][i].weight);
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
        edge temp1;
        edge temp2;
        int from;
        cin>>from>>temp1.to>>temp1.weight;
        temp2.to = from;
        temp2.weight = temp1.weight;
        edges[from].push_back(temp1);
        edges[temp1.to].push_back(temp2);
    }
    dij();
    int total = 0;
    for(int i=2; i<=n; i++){
        total += cost[i];
    }
    cout<<total<<endl;
    return 0;
}