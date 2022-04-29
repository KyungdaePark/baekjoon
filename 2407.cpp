#include<iostream>

using namespace std;


int main(){
    // long long dp[101];

    // dp[1] = 1;
    // for(int i=2;i<=100;i++){
    //     dp[i] = i * dp[i-1];
    // }

    // cout<<dp[3]; 

    int n,m; cin>>n>>m;

    if(m > n/2) m=n-m;

    long long up = 1;
    for(int i=n;i>n-m;i--){
        up = up * i;
    }

    long long down = 1;
    for(int i=1;i<=m;i++){
        down = down * i;
    }

    int div[4] = {2,3,5,7};
    for(int i=0;i<4;i++){
        if(up % div[i] == 0 && down % div[i] == 0){
            up = up / div[i];
            down = down / div[i];
        }
    }
    cout<<up<<" "<<down;
}