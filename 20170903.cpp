#include<iostream>
#include<string>
#include<vector>
using namespace std;
int find_next_end(string info, int now){
    int count = 0;
    for(int i=now; i<info.length(); i++){
        if(info[i] == '{')
            count++;
        if(info[i] == '}')
            count--;
        if(count == 0)
            return i;
    }
    return -1;
}
string delete_neg(string x){
    string result;
    for(int i=0; i<x.length(); i++){
        if(x[i] == '\\'){
            result += x[i+1];
            i++;
        }else{
            result += x[i];
        }
    }
    return result;
}
string process(string info, string relu){
    if(relu.find('.') != string::npos){
        string pre = relu.substr(0, relu.find_first_of('.'));
        if(info.find(pre) == string::npos){
            return "NOTEXIST";
        }
        string after = relu.substr(relu.find_first_of('.')+1, relu.length()-relu.find_first_of('.')-1);
        int pos = info.find(pre)+pre.length()+3;
        int end  = find_next_end(info, pos);
        if(end == -1)
            return "error";//ee{er}ee
        string this_object = info.substr(pos, end-pos+1);
        // cout<<this_object<<endl;
        return process(this_object, after);
    }else{
        if(info.find(relu) == string::npos){
            return "NOTEXIST";
        }
        int pos = info.find(relu);
        // cout<<info[pos+relu.length()+3]<<endl;
        if(info[pos+relu.length()+3] == '{'){
            return "OBJECT";
        }
        else{//"dd":"dd",
             //0123456789
             //pos = 1 length = 2 end = 9
            int end = info.substr(pos, info.length()-pos).find_first_of(',');
            if(end == string::npos){
                end = info.substr(pos, info.length()-pos).find_first_of('}');
            }
            return info.substr(pos+relu.length()+4, end-5-relu.length());
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    cin.get();
    string info;
    vector<string> relu;
    for(int i=0; i<m; i++){
        string temp;
        getline(cin, temp);
        info += delete_neg(temp);
    }
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        relu.push_back(temp);
    }
    for(int i=0; i<relu.size(); i++){
        string res = process(info, relu[i]);
        if(res == "NOTEXIST")
            cout<<res<<endl;
        else if(res == "OBJECT")
            cout<<res<<endl;
        else{
            cout<<"STRING "<<res<<endl;
        }
    }
    return 0;
}