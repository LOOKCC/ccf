#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int const N = 100;

int valid[N+1][N+1][301];
const int dir_size = 4;
struct direct{
    int draw, dcol;
}direct[dir_size] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct node{
    int raw, col, time;
};

int bfs(int n, int m){
    node start, front, v;
    start.raw = 1;
    start.col = 1;
    start.time = 0;
    queue<node> q;
    q.push(start);
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front.raw == n  && front.col == m){
            return front.time;
        }
        for(int i=0; i<dir_size; i++){
            v.raw = front.raw + direct[i].draw;
            v.col = front.col + direct[i].dcol;
            v.time = front.time + 1;
            if(v.raw <= 0 || v.raw > n || v.col <= 0 || v.col > n )
                continue;
            if(valid[v.raw][v.col][v.time])
                continue;
            valid[v.raw][v.col][v.time] = 1;
            q.push(v);
        }
    }
    return 0;
}

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0; i<t; i++){
        int r,c,a,b;
        cin>>r>>c>>a>>b;
        for(int j=a; j<=b; j++){
            valid[r][c][j] = 1;
        }
    }
    int res = bfs(n, m);
    cout<<res<<endl;
    return 0;
}