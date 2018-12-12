#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_number(string x){
    for(int i=0; i<x.length(); i++){
        if()
    }
}

string process(vector<string> rule, string addr){
    for(int i=0; i<rule.size(); i++){
        string name = rule.substr(rule.find_first_of(' ')+1, rule.length()-rule.find_first_of(' ')-1);
        string rule_str = rule.substr(0, rule.find_first_of(' '));
        vector<string> rule_vector, addr_vector;
        while(rule_str.length() > 0){
            
        }

    }
    


}

int main(){
    int n,m;
    cin>>n>>m;
    cin.get()
    vector<string> rule;
    vector<string> addr;
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        rule.push_back(temp);
    }
    for(int i=0; i<m; i++){
        string temp;
        getline(cin, temp);
        addr.push_back(temp);
    }
    
    return 0;
}