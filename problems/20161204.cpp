#include<iostream>
using namespace std;
const int maxn = 1005;
const int maxw = 10000000;
int dp[maxn][maxn];
int w[maxn];
int sum[maxn];
int n;
int solve(int i, int j){
    if(dp[i][j] == maxw){
        for(int k=i; k<j; k++){
            int val = solve(i, k) + solve(k+1, j) + sum[j] - sum[i-1];
            if(val < dp[i][j])
                    dp[i][j] = val;
        }
    }
    return dp[i][j];
}
int main(){
    cin>>n;
    int temp = 0;
    for(int i=0; i<n; i++){
        cin>>w[i];
        temp += w[i];
        sum[i] = temp;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = maxw;
        }
    }
    solve(0, n-1);
    cout<<dp[0][n-1]<<endl;
    return 0;
}