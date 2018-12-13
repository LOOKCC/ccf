#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_number(string x){
    for(int i=0; i<x.length(); i++){
        if(x[i] < '0' || x[i] > '9'){
            return false;
        }
    }
    return true;
}

vector<string> process(vector<string> rule, string addr){
    vector<string> result; 
    for(int i=0; i<rule.size(); i++){
        string name = rule[i].substr(rule[i].find_first_of(' ')+1, rule[i].length()-rule[i].find_first_of(' ')-1);
        string rule_str = rule[i].substr(1, rule[i].find_first_of(' ')-1);
        result.push_back(name);
        string addr_str = addr.substr(1, addr.length()-1);
        vector<string> rule_vector, addr_vector;
        while(rule_str.length() > 0){
            if(rule_str.find_first_of('/') == string::npos){
                rule_vector.push_back(rule_str);
                addr_vector.push_back(addr_str);
                rule_str = "";
                addr_str = "";
                break;
            }
            if(addr.find_first_of('/') == string::npos){
                rule_vector.push_back(rule_str);
                addr_vector.push_back(addr_str);
                rule_str = "";
                addr_str = "";
                break;
            }
            int rule_pos = rule_str.find_first_of('/');
            int addr_pos = addr_str.find_first_of('/');
            rule_vector.push_back(rule_str.substr(0, rule_pos));
            addr_vector.push_back(addr_str.substr(0, addr_pos));
            rule_str = rule_str.substr(rule_pos+1, rule_str.length()-rule_pos-1);
            addr_str = addr_str.substr(addr_pos+1, addr_str.length()-addr_pos-1);
        }
        int flag = 1;
        if(addr_str.length() > 0 ){
            result.clear();
            continue;
        }
        for(int j=0; j<rule_vector.size(); j++){
            if(rule_vector[j] == "<int>"){
                if(!is_number(addr_vector[j])){
                    flag = 0;
                    break;
                }else{
                    result.push_back(addr_vector[j]);
                }
            }else if(rule_vector[j] == "<str>"){
                if(addr_vector[j].length() <= 0){
                    flag = 0;
                    break;
                }else{
                    result.push_back(addr_vector[j]);
                }
            }else if(rule_vector[j] == "<path>"){
                if(addr_vector[j].length() <= 0){
                    flag = 0;
                    break;
                }else{
                    result.push_back(addr_vector[j]);
                }
            }else{
                if(addr_vector[j] == rule_vector[j]){
                
                }else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1){
            return result;
        }else{
            result.clear();
        }
    }
    result.push_back("404");
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    cin.get();
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
    for(int i=0; i<addr.size(); i++){
        vector<string> result;
        result = process(rule, addr[i]);
        for(int j=0; j<result.size()-1; j++){
            cout<<result[j]<<" ";
        }
        cout<<result[result.size()-1]<<endl;
    }
    return 0;
}