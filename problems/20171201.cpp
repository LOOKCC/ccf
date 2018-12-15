#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[n];
    int small = 100000;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            if(x[i] - x[j] >= 0 && x[i] - x[j] < small)
                small = x[i] - x[j];
        }
    }
    cout<<small<<endl;
    return 0;
}