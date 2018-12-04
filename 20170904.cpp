#include<iostream>
#include<vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int flag[1005][1005];
int visit[1005];
vector<int> V[1005];
void dfs(int a, int t ){
    visit[a] = 1;
    flag[a][t] = 1;
    flag[t][a] = 1;
    for(int i=0; i<V[a].size(); i++){
        if(!visit[V[a][i]])
                dfs(V[a][i], t);
    }
}
int main(){
    int n,m;
    cin>>m>>n;
    for(int i=0; i<=n; i++){
        V[i].clear();
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            flag[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        V[x].push_back(y);
    }
    
    for(int i=1; i<n+1; i++){
        memset(visit, 0, sizeof(visit));
        dfs(i,i);
    }
    int count = 0;
    for(int i=1; i<n+1; i++){
        int j;
        for(j=1; j<n+1; j++){
            if(!flag[i][j] || !flag[j][i])
                break;
        }
        if(j == n+1)
            count++;
    }
    cout<<count<<endl;
    return 0;
}
