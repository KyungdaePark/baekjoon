#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define INF 9999999
int dp[1001];
//bool dp[1001]={false};
vector<int> v;
int main(){
    int S; cin>>S;
    queue<pair<int,int>> q; //before, now
    for(int i=0;i<1001;i++){
        dp[i] = INF;
    }
    q.push({-1,1});
    while(!q.empty()){
        int clip = q.front().first;
        int now = q.front().second;
       // cout<<now<<" ";
        q.pop();
        if(clip==-1){
            q.push({1,2});
            dp[1] = 0;
            dp[2] = 2;
            continue;
        }
        for(int elem : {now*2, now+clip, now-1}){
            if(elem>=0 && elem<= 1000){
             if(elem == now*2){
                 if(dp[now] + 2 <= dp[elem]){
                      dp[elem] = dp[now]+2;
                      q.push({now,elem}); //now를 복사한 격
                 }
                }
             else{
                 if(dp[now] + 1 <= dp[elem]){
                     dp[elem] = dp[now]+1;
                     q.push({clip,elem}); //clip은 그대로 가져가는 격 
                 }
               }
            }
        }
    }
    for(int i=0;i<100;i++){
        cout<<i <<" "<<dp[i]<<" \n";
    }
}   