#include<iostream>
using namespace std;
int main(){
    int n,l,t;
    cin>>n>>l>>t;
    int position[n];
    int direction[n]; //direction 1 is ringht 0 is left
    for(int i=0; i<n; i++){
        cin>>position[i];
        direction[i] = 1;
    }
    for(int i=0; i<t; i++){
        for(int j=0; j<n; j++){
            if(direction[j] == 1)
                position[j] += 1;
            else
                position[j] += -1; 
            if(position[j] == l)
                direction[j] = 0;
             if(position[j] == 0)
                direction[j] = 1;
        }
        for(int j = 0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(position[j] == position[k]){
                    direction[j] = 1-direction[j];
                    direction[k] = 1-direction[k];
                }
            }   
        }
    }
    for(int i=0; i<n-1; i++){
        cout<<position[i]<<" ";
    }
    cout<<position[n-1]<<endl;
    return 0;
}