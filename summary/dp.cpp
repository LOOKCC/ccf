#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1005;
const int maxw = 1000005;
int w[maxn];
int sum[maxn];
int dp[maxn][maxn];
int n;
int main(){
    cin>>n;
    int temp = 0;
    for(int i=0; i<n; i++){
        cin>>w[i];
        temp += w[i];
        sum[i] = temp;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = maxw;
        }
    }
    for(int len=2; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            for(int k=i; k<j; k++){
                if(dp[i][j] > dp[i][k] + dp[k+1][j] + sum[j]-sum[i-1])
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j]-sum[i-1];
            }
        }
    }
    //cout what you want
    return 0;
}