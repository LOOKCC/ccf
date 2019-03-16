#include<iostream>
#include<string>
#include<vector>
using namespace std;

string del_dir(string x){
    for(int i=0; i<x.length()-1; i++){
        if(x[i] == '/' && x[i+1] == '/'){
            x = x.erase(i, 1);
            i--;
        }
    }
    return x;
}

vector<string> split(string dir){
    dir = del_dir(dir);
    vector<string> temp;
    if(dir[0] == '/'){
        dir = dir.substr(1, dir.length()-1);
        temp.push_back("/");
    }
    while(dir.length()>0){
        int pos = dir.find_first_of('/');
        if(pos == string::npos){
            temp.push_back(dir);
            break;
        }
        string front = dir.substr(0, pos);
        temp.push_back(front);
        dir = dir.substr(pos+1, dir.length()-1-pos);
    }
    return temp;
}

string process(string now_dir, string dir){
    string result;
    vector<string> now_dir_split = split(now_dir);
    vector<string> dir_split = split(dir);
    if(dir_split[0] == "/"){
        result += "/";
    }
}

int main(){
    int n;
    cin>>n;
    string now_dir;
    cin>>now_dir;
    vector<string> dirs;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        dirs.push_back(temp);
    }
    for(int i=0; i<n; i++){
        dirs[i] = process(now_dir, dirs[i]);
    }
    for(int i=0; i<n; i++){
        cout<<dirs[i]<<endl;
    }
    return 0;
}