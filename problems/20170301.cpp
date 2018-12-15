#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> cake;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        cake.push_back(x);
    }
    // sort(cake.begin(), cake.end());
    int count = 0;
    int now = 0;
    for(int i=0; i<cake.size(); i++){
        now += cake[i];
        if(now >= k){
            count++;
            now = 0;
        }
    }
    if(now != 0)
        count++;
    cout<<count<<endl;
    return 0;
}