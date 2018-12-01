#include<iostream>
#include<string>
#include<vector>
using namespace std;

string erase_point(string x){
    if(x[0] == '.')
        erase_point(x.erase(x.begin()));
    else
        return x;
}

int level(string x){
    int count = 0;
    for(int i=0; i<x.length(); i++){
        if(x[i] == '.')
            count++;
    }
    return count/2;
}

vector<int> process1(string title, ,vector<string> info){
    vector<int> reslut;
    for(int i=0; i<info.size(); i++){
        string sub = erase_point(info[i]);
        if(sub.find('') != string::npos)
            sub =  sub.substr(0, sub.find_first_of(' ')); 
        if(sub == title){
            reslut.push_back(i+1);
        }
    }
    return reslut;
}

vector<int> process2(string id, vector<string> info){
    vector<int> reslut;
    for(int i=0; i<info.size(); i++){
        if(info.find('#') == string::npos)
            continue;
        string sub = erase_point(info[i]); // 0123#45
        sub = sub.substr(sub.find_first_of('#'), sub.length()-sub.find_first_of('#'));
        if(sub == id)
            reslut.push_back(i+1);
    }
    return reslut;
}

vector<int> process3(string mul, vector<string> info){
    vector<int> result;
    int last_level = 0;
    string to_fit ;
    if(mul.find(' ') == string::npos){
        last_level = 1; 
        to_fit = mul;
    }else{
        last_level = 0;
        to_fit = mul.substr(0, mul.find_first_of(' '));
    }
    for(int i=0; i<info.size(); i++){
        string sub = erase_point(info[i]);
        if(sub.find('') != string::npos)
            sub =  sub.substr(0, sub.find_first_of(' '));
        if(sub == to_fit){
            if(last_level == 1){
                reslut.push_back(i+1);
            }else{
                vector<int> temp_res;
                vector<string> temp_info;
                int now_level = level(info[i]);
                for(int j=i+1; j<info.length; j++){
                    if(level(info[j] > now_level))
                        temp_info.push_back(info[j]);
                    else
                        break;
                }
                int temp_pos = mul.substr(mul.find_first_of(' ');
                temp_res = process3(mul.substr(temp_pos+1, substr.length()-temp_pos-1), temp_info);
                for(int j=0; j<temp_res.size(); j++){
                    reslut.push_back(i+1+temp_res[j]);
                }
            }
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n,m;
    vector<string> info;
    vector<string> res;
    vector<int> result;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        info.push_back(temp);
    }
    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        res.push_back(temp);
    }
    for(int i=0; i<m; i++){
        if(res[i].find('#') != string::npos){
            result = process2(res[i], info);
            cout<<result.size();
            for(int j=0; j<reslut.size(); j++){
                cout<<" "<<result[j];
            }
            cout<<endl;
        }
        if(res[i].find(' ') != string::npos){
            result = process3(res[i], info);
            cout<<result.size();
            for(int j=0; j<reslut.size(); j++){
                cout<<" "<<result[j];
            }
            cout<<endl;
        }
        if(res[i].find(' ') == string::npos){
            result = process1(res[i], info);
            cout<<result.size();
            for(int j=0; j<reslut.size(); j++){
                cout<<" "<<result[j];
            }
            cout<<endl;
        }
    }
    return 0;
}