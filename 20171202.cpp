#include<iostream>
using namespace std;
int cal(int n, int x[]){
    int count = 0;
    for(int i=0; i<n; i++){
        count += x[i];
        if(count > 1)
            return 0;
    }
    return 1;
}

int main(){
    int n,k;
    cin>>n>>k;
    int people[n];
    int flag[n];
    for(int i=0; i<n; i++){
        people[i] = i+1;
        flag[i] = 1;
    }
    int count = 0;
    while(cal(n, flag) != 1){
        for(int i=0; i<n; i++){
            if(flag[i] == 0)
                continue;
            else{
                count++;
                if(count%k == 0 || count%10 == k){
                    flag[i] = 0;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(flag[i] == 1)
            cout<<people[i]<<endl;
    }
    return 0;
}