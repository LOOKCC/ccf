#include<iosteram>
#include<string>
using namespace std;


int suit(string now, string time){

}
string next(string now){

}

int main(){
    int n;
    cin>>n;
    string begin, end;
    cin>>begin>>end;
    srting task[n];
    for(int i=0; i<n; i++){
        cin>>task[i];
    }
    string now = begin;
    while(now != end){
        for(int i=0; i<0; i++){
            if(suit(now, task[i]))
                cout<<now<<" "<<   <<endl;
        }
        now = next(now);
    }
    return 0;
}