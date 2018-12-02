// copy code from internet, for learning the style of global variables
// link: https://blog.csdn.net/miranda_ymz/article/details/83625557
#include<iostream>
using namespace std;
const int maxn = 310;
int flag, n;
int a[maxn], old_shop[maxn], ans[maxn];

void dfs(int u, int t[]){
    if(flag)
        return ;
    if(u == n){
        if((t[u-1] + t[u-2])/2 == a[u-1]){
            for(int i=0; i<n; i++){
                ans[i] = t[i];
            }
            flag =1;
            return ;
        }
    }
    int small, big;
    if(u == 1){
        small = a[u-1]*2 - t[u-1];
        big = (a[u-1]+1)*2 - t[u-1];
        if(big<= 0) return;
    }
    else
    {
        small = a[u-1]*3 - t[u-2] - t[u-1];
        big = (a[u-1]+1)*3 -t[u-2] - t[u-1];
        if(big<= 0) return; 
    }
    if(small <= 0)
        small = 1;
    for(int i=small; i<big; i++){
        t[u] = i;
        if(u != n-1 && t[u]>= a[u]*3) return;
        if(u == n-1 && (t[u] + t[u-1])/2 > a[u]) return;
        dfs(u+1, t);
    }    
}

int main(){
    cin>>n;
    flag = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<a[0]*2+2; i++){
        old_shop[0] = i;
        dfs(1, old_shop);
        if(flag)
            break;
    }
    for(int i=0; i<n-1; i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[n-1]<<endl;
    return 0;
}