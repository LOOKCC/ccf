#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int site[100];
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        int find = 0;
        if(x == 1){
            for(int j=0; j<100; j++){
                if(site[j] == 0){
                    site[j] = 1;
                    cout<<j+1<<endl;
                    break;
                }
            }
        }
        if(x == 2){
            for(int j=0; j<99; j++){
                if(site[j] == 0 && site[j+1] == 0 && (j+1)%5!= 0){
                    site[j] = 1;
                    site[j+1] = 1;
                    cout<<j<<" "<<j+1<<endl;
                    find = 1;
                    break;
                }
            }
        }
        if(x == 3){
            for(int j=0; j<98; j++){
                if(site[j] == 0 && site[j+1] == 0 && site[j+2] == 0){
                    if((j+1)%5 != 0 && (j+2)%5 != 0){
                        site[j] = 1;
                        site[j+1] = 1;
                        site[j+2] = 1;
                        cout<<j<<" "<<j+1<<" "<<j+2<<endl;
                        find = 1;
                        break;
                    }
                }
            }
        }
        if(x == 4){
            for(int j=0; j<100; j++){
                if(site[j] == 0 && site[j+1] == 0 && site[j+2] == 0 && site[j+3] == 0){
                    if((j+1)%5 != 0 && (j+2)%5 != 0 && (j+3)%5 != 0){
                        site[j] = 1;
                        site[j+1] = 1;
                        site[j+2] = 1;
                        site[j+3] = 1;
                        cout<<j<<" "<<j+1<<" "<<j+2<<" "<<j+3<<endl;
                        find = 1;
                        break;
                    }
                }
            }
        }
        if(x == 5){
            for(int j=0; j<100; j++){
                if(site[j] == 0 && site[j+1] == 0 && site[j+2] == 0 && site[j+3] == 0 && site[j+4] == 0){
                    if((j+1)%5 != 0 && (j+2)%5 != 0 && (j+3)%5 != 0 && (j+4)%5 != 0){
                        site[j] = 1;
                        site[j+1] = 1;
                        site[j+2] = 1;
                        site[j+3] = 1;
                        site[j+4] = 1;
                        cout<<j<<" "<<j+1<<" "<<j+2<<" "<<j+3<<" "<<j+4<<endl;
                        find = 1;
                        break;
                    }
                }
            }
        }
        if(find == 0){
            for(int j=0; j<x; j++){
                for(int k=0; k<100; k++){
                    if(site[k] == 0){
                        if(j == x-1)
                            cout<<k<<" ";
                        else
                            cout<<k<<endl;
                    }
                }
            }
        }
    }
    return 0;
}