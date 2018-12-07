#include<iostream>
#include<string>
#include<vector>
using namespace std;
string process(vector<string> info, string relu){
    
    return 0;
}
int main(){
    int m,n;
    cin>>m>>n;
    cin.get();
    vector<string> info;
    vector<string> relu;
    for(int i=0; i<m; i++){
        string temp;
        getline(cin, temp);
        info.push_back(temp);
    }
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        relu.push_back(temp);
    }
    
    return 0;
}