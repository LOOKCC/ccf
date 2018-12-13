#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> queue;
    for(int i=1; i<n+1; i++){
        queue.push_back(i);
    }
    for(int i=0; i<m; i++){
        int people, dot;
        cin>>people>>dot;
        int pos;
        for(int j=0; j<queue.size(); j++){
            if(queue[j] == people)
                pos = j;
        }
        queue.erase(queue.begin()+pos);
        queue.insert(queue.begin()+pos+dot, people);
    }
    for(int i=0; i<n-1; i++){
        cout<<queue[i]<<" ";    
    }
    cout<<queue[n-1]<<endl;
    return 0;
}