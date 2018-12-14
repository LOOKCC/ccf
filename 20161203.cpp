#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int p;
    cin>>p;
    string temp;
    unordered_map<string, vector<string>> permission;
    unordered_map<string, vector<string>> name;
    for(int i=0; i<p; i++){
        cin>>temp;
    }
    int r;
    cin>>r;
    for(int i=0; i<r; i++){
        cin>>temp;
        int x;
        cin>>x;
        vector<string> per;
        for(int j=0; j<x; j++){
            string temp_per;
            cin>>temp_per;
            per.push_back(temp_per);
        }
        permission.insert({temp, per});
    }
    int u;
    cin>>u;
    for(int i=0; i<u; i++){
        cin>>temp;
        int x;
        cin>>x;
        vector<string> per;
        for(int j=0; j<x; j++){
            string temp_per;
            cin>>temp_per;
            for(int k=0; k<permission[temp_per].size(); k++)
                per.push_back(permission[temp_per][k]);
        }
        name.insert({temp, per});
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        string person;
        string per;
        cin>>person;
        cin>>per;
        if(name.find(person) == name.end()){
            cout<<"false"<<endl;
            continue;
        }
        int result = -1;
        bool find_it = false;
        vector<string> to_search = name[person];
        for(int j=0; j<to_search.size(); j++){
            if(per.find_first_of(':') == string::npos){
                if(to_search[j].find_first_of(':') == string::npos){
                    if(per == to_search[j]){
                        find_it = true;
                    }
                }else{
                    int pos = to_search[j].find_first_of(':');
                    if(per == to_search[j].substr(0, pos)){
                        find_it = true;
                        int m = stoi(to_search[j].substr(pos+1, to_search[j].length()-pos-1));
                        if(m>result){
                            result = m;
                        }
                    }
                }
            }else{
                if(to_search[j].find_first_of(':') == string::npos){
                    continue;
                }else{
                    int search_pos = to_search[j].find_first_of(':');
                    int per_pos = per.find_first_of(':');
                    if(per.substr(0, per_pos) == to_search[j].substr(0, search_pos)){
                        int m = stoi(to_search[j].substr(search_pos+1, to_search[j].length()-search_pos-1));
                        int h = stoi(per.substr(per_pos+1, per.length()-per_pos-1));
                        if(m>=h){
                            find_it = true;
                            result = -1;
                        }
                    }
                }
            }
        }
        if(find_it == false)
            cout<<"false"<<endl;
        else{
            if(result == -1)
                cout<<"true"<<endl;
            else
                cout<<result<<endl;
        }
    }
    return 0;
}