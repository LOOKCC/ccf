#include<iostream>
#include <stdlib.h> 
using namespace std;

int main(){
    int n;
    cin>>n;
    int days[n];
    int max_num = 0;
    for(int i=0; i<n; i++){
        cin>>days[i];
    }
    for(int i=0; i<n-1; i++){
        if(abs(days[i] - days[i+1]) > max_num)
            max_num = abs(days[i] - days[i+1]);
    }
    cout<<max_num<<endl;
    return 0;
}