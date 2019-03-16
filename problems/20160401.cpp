#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int temp[n];
    for(int i=0; i<n; i++){
        cin>>temp[i];
    }
    int count = 0;
    for(int i=1; i<n-1; i++){
        if(temp[i-1] < temp[i] && temp[i] > temp[i+1]){
            count++;
        }
        if(temp[i-1] > temp[i] && temp[i] < temp[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}