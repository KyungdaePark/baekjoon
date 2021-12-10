#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;
int main(){
    int N;
    int map[MAX][3]={};
    int dp[MAX][3]={};
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>map[i][j];
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for(int i=1;i<=N;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + map[i-1][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + map[i-1][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + map[i-1][2];
    }

    
    int answer = 9999999;
    for(int i=0;i<3;i++){
        answer = min(answer,dp[N][i]);
    }
    cout<<answer;
}