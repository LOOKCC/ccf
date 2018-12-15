#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0; i<n; i++){
        int big = 0;
        int small = 0;
        for(int j=0; j<n; j++){
            if(a[j] < a[i])
                small++;
            if(a[j] > a[i])
                big++;
        }
        if(small == big){
            cout<<a[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;  
    return 0;  
}