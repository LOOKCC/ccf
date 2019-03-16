#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct IP
{
    int first;
    int second;
    int third;
    int forth;
    int cover;
    string all;
    friend bool operator< (const struct IP a,  const struct IP b){
        if(a.first < b.first){
            return true;
        }else if(a.first > b.first){
            return false;
        }else{
            if(a.second < b.second){
                return true;
            }else if(a.second > b.second){
                return false;
            }else{
                if(a.third < b.third){
                    return true;
                }else if(a.third > b.third){
                    return false;
                }else{
                    if(a.forth < b.forth){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }
};


string input_to_IP(string x){

}


int main(){
    int n;
    vector<string> info;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        info.push_back(temp);
    }
    
}