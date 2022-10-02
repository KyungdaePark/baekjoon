/*
    1 3
    2 3
    4 2
    1 2
    1 4



*/

#include<iostream>

#define MAX 32001
#define INF 999999
using namespace std;

int n, m;
int dp[MAX]={};

int main(){
    fill_n(dp,MAX,INF);
    cin>>n>>m;
    int initalizing = 1;
    int inp1, inp2;
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2;
        if(dp[inp1]==INF && dp[inp2]==INF) //둘다 null이면
            {
                dp[inp1] = initalizing;
                dp[inp2] = initalizing+1;
                initalizing+=MAX;
            }
        else if(dp[inp2] == INF){ 
            dp[inp2] = dp[inp1] + 1;
        }
        else if(dp[inp1] == INF){
            dp[inp1] = dp[inp2] - 1;
        }
        else if(dp[inp1] >= dp[inp2]){
            dp[inp1] = dp[inp2]-1;
        }
    }
    int cnt = 0;
    int compare = n * (-1);
    for(;;){
        for(int j=1;j<=n;j++){
            if(dp[j] == compare){
                cout<<j<<" ";
                dp[j] = INF;
                cnt++;
            }
        }
        compare++;
        if(cnt==n) break;
    }
    
}