#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int to;
    int weight;
};


const int maxn = 1005;
const int maxm = 10005;

int n;
int visited[maxn];
vector<edge> edges[maxn];


void bfs(int i, int j){
    queue<int> q;
    visited[i] = 1;
    q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == j)
            return;
        for(int i=0; i<edges[v].size(); i++){
            if(visited[edges[v][i].to])
                continue;
            q.push(edges[v][i].to);
        }
    }
}

int main(){
    int m;
    cin>>n;
    for(int i=0; i<m; i++){
        edge temp;
        int from;
        cin>>from;
        cin>>temp.to>>temp.weight;
        edges[from].push_back(temp);
    }
    bfs(1,1);//if you count from 1;
    return 0;
}