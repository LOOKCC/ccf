#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 1005;
const int maxm = 10005;
const int maxw = 100005;

struct edge
{
    int to;
    int weight;
    bool operator<(const edge e)const{
        return weight > e.weight;
    }
};

int n;
int visited[maxn];
vector<edge> edges[maxn];
priority_queue<edge> q;

void prim(int start){
    int num = 0;
    visited[start] = 1;
    num++;
    for(int i=0; i<edges[start].size(); i++){
        q.push(edges[start][i]);    
    }
    while(num != n){
        edge temp;
        temp = q.top();
        q.pop();
        int v = temp.to;
        if(visited[v] == 1)
            continue;
        visited[v] = 1;
        num++;
        for(int i=0; i<edges[v].size(); i++){
            if(!visited[edges[v][i].to])
                q.push(edges[v][i]);    
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
    prim(1);
    //cout  
    return 0;
}
