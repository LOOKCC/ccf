#include<iostream>
#include<string>
#include<vector>
using namespace std;
string process_out(string x){
    if(x[0] == '#'){
        int count = 0;
        for(int i=0; i<x.length(); i++){
            if(x[i] == '#')
                count++;
            if(x[i] == ' ')
                break;
        }
        x = "<h"+to_string(count)+">"+x+"</h"+to_string(count)+">";
    }else if(x[0] == '*'){
        x = "<ul>" + x + "</ul>";
        // int flag_1 = 0;
        // int flag_2 = 0;
        // for(int i=0; i<x.length(); i++){
        //     if(x[i] == '#')
        // }
    }else{
        x = "<p>" + x + "</p>";
    }
    return x;
}

string process_(string x){
    string result;
    int flag = 0;
    for(int i=0; i<x.length(); i++){
        if(x[i] == '_' && flag == 0){
            result += "<em>";
            flag = 1;
        }
        else if(x[i] == '_' && flag == 1){
            result += "</em>";
            flag = 0;
        }else{
            result += x[i];
        }
    }
    return result;
}
string process_url(string x){
    if(x.find_first_of('[') == string::npos){
        return x;
    }else{
        string result;
        int text_pre = x.find_first_of('[')+1;
        int text_af = x.find_first_of(']');
        int link_pre = x.find_first_of('(')+1;
        int link_af = x.find_first_of(')');
        string text = x.substr(text_pre, text_af-text_pre);
        string link = x.substr(link_pre, link_af-link_pre);
        result = x.substr(0, text_pre-1) + "<a href=\""+link+"\">"+text+"</a>"+x.substr(link_af+1, x.length()-link_af-1);
        return process_url(result);
    }
}
int main(){
    vector<string> info;
    string stage;
    string temp;
    while(getline(cin, temp)){
        if(temp == ""){
            info.push_back(stage);
            stage = "";
        }else{
            if(stage == "")
                stage += temp;
            else
                stage += ("\n" + temp);
        }
    }
    for(int i=0; i<info.size(); i++){
        string temp = process_(info[i]);
        temp = process_url(temp);
        temp = process_out(temp);
        cout<<temp<<endl;
    }
    return 0;
}