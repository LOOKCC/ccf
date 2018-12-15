#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int person_1[n][2];
    int person_2[n][2];
    int count = 0;
    for(int i=0; i<n; i++)
        cin>>person_1[i][0]>>person_1[i][1];
    for(int i=0; i<n; i++)
        cin>>person_2[i][0]>>person_2[i][1];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(person_1[i][1] <= person_2[j][0]){
                continue;
            }
            if(person_1[i][0] >= person_2[j][1]){
                continue;
            }
            if(person_1[i][0] <= person_2[j][0] && person_1[i][1] <= person_2[j][1]){
                count += (person_1[i][1] - person_2[j][0]);
            }
            else if(person_1[i][0] <= person_2[j][0] && person_1[i][1] >= person_2[j][1]){
                count += (person_2[j][1] - person_2[j][0]);
            }
            else if(person_1[i][0] >= person_2[j][0] && person_1[i][1] >= person_2[j][1]){
                count += (person_2[j][1] - person_1[i][0]);
            }
            else if(person_1[i][0] >= person_2[j][0] && person_1[i][1] <= person_2[j][1]){
                count += (person_1[i][1] - person_1[i][0]);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}