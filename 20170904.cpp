#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    int send[n+1][n+1];
    int receive[n+1][n+1];
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i == j){
                send[i][j] = 1;
                receive[i][j] = 1;
            }else{
                send[i][j] = 0;
                receive[i][j] = 0;
            }
        }
    }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        send[x][y] = 1;
        receive[y][x] = 1;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=i+1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
               if(k == i || k == j) continue;
                if(send[i][k] == 1 && send[k][j] == 1){
                    send[i][j] = 1;
                    receive[j][i] = 1;
                }
            }
        }
    }
    // for(int i=1; i<n+1; i++){
    //     for(int j=1; j<n+1; j++){
    //         cout<<send[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1; i<n+1; i++){
    //     for(int j=1; j<n+1; j++){
    //         cout<<receive[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int count = 0;
    for(int i=1; i<n+1; i++){
        int flag = 1;
        for(int j=1; j<n+1; j++){
            if(send[i][j] == 0 && receive[i][j] == 0)
                flag = 0;
        }
        if(flag != 0 )
            count++;
    }
    cout<<count<<endl;
    return 0;
}