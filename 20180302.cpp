#include<iostream>
using namespace std;
int main(){
    int n,l,t;
    cin>>n>>l>>t;
    int position[n];
    int direction[n]; //direction 1 is ringht 0 is left
    for(int i=0; i<n; i++){
        cin>>position[n];
        direction[i] = 1;
    }
    for(int i=0; i<t; i++){
        for(int j = 0; j<n; j++){
             if(direction[i] == 1){
                if(position[i+1] == position[i] && direction[i] == 1 && direction[i+1] == 0){
                    direction[i] = 0;
                    direction[i+1] = 1;
                }
            }
            else{
                if(position[i-1] == position[i] && direction[i] == 0 && direction[i+1] == 1){
                    direction[i] = 1;
                    direction[i+1] = 0;
                }

            }
        }
        for(int j=0; j<n; j++){
            if(direction[i] == 1)
                position[i] += 1;
            else
                position[i] += -1; 
        }
    }
    for(int i=0; i<n-1; i++){
        cout<<position[i]<<" ";
    }
    cout<<position[n-1]<<endl;
    return 0;
}