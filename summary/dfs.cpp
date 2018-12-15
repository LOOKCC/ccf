//this is a dfs template
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1005; //take 1000 for example
struct edge{ //you may need a struct to store edges
    //int from;
    int to;
    int weight;
};
int visit[maxn];
vector<edge> edges[maxn];
int n;
void dfs(int i, int j){
    visit[j] = 1;
    // do something you need to do according to the edge i->j;
    for(int k=0; k<edges[j].size(); k++){
        if(!visit[edges[j][k].to]){
            dfs(j, edges[j][k].to);
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
    dfs(1,1);//if you count from 1;
    return 0;
}