#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> get[10005];
    vector<int> put[10005];
    int n,k;
    cin>>n>>k;
    int keys[n+1];
    for(int i=1; i<n+1; i++){
        keys[i] = i;
    }
    for(int i=0; i<k; i++){
        int w,s,c;
        cin>>w>>s>>c;
        get[s].push_back(w);
        put[s+c].push_back(w);
    }
    for(int i=0; i<10005; i++){
        if(put[i].size() >= 1){
            sort(put[i].begin(), put[i].end());
            for(int j=0; j<put[i].size(); j++){
                for(int k=1; k<n+1; k++){
                    if(keys[k] == 0){
                        keys[k] = put[i][j];
                        break;
                    }
                }
            }
        }
        if(get[i].size() >= 1){
            for(int j=0; j<get[i].size(); j++){
                for(int k=1; k<n+1; k++){
                    if(keys[k] == get[i][j])
                        keys[k] = 0;
                }
            }
        }
    }
    for(int i=1; i<n; i++){
        cout<<keys[i]<<" ";
    }
    cout<<keys[n]<<endl;
    return 0;
}