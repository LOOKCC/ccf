#include<iostream>
#include<string>
#include<vector>
using namespace std;
//some small func, such as is_number, to_upper, tolower

//main process func
vector<string> process(vector<string> info, string rule){

}
int main(){
    int n,m;
    cin>>n>>m;
    cin.get(); //you may need this to get the \n.
    vector<string> info;
    vector<string> rule;
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        info.push_back(temp);
    }
    for(int i=0; i<m; i++){
        string temp;
        getline(cin, temp);
        info.push_back(temp);
    }
    for(int i=0; i<m; i++){
        vector<string> res;
        res = process(info, rule[i]);
        //cout res
    }
    return 0;
}  