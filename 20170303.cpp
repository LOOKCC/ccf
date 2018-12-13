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
        // x = "<ul>" + x + "</ul>";
        int flag_1 = 0;
        int flag_2 = 0;
        for(int i=0; i<x.length(); i++){
            if(x[i] == '#')
        }
    }else{
        x = "<p>" + x + "</p>";
    }
    return x;
}

string process_in(string x){

}

int main(){
    vector<string> info;
    string stage;
    string temp;
    while(getline(cin, temp)){
        if(temp == "\n"){
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

    }
    return 0;
}