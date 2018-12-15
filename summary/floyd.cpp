#include<iostream>
#include<vector>
using namespace std;
struct edge{
    int to;
    int weight;
};
const int maxn = 1005;
const int maxw = 100005;
int dis[maxn][maxn];
int p[maxn][maxn];
int n;
int main(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            p[i][j] = j;
            if(i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = maxw;
        }
    }
    cin>>n;
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        dis[from][to] = weight;
        dis[to][from] = weight; //if the graph is undirected 
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    //cout what you want
    return 0;
}