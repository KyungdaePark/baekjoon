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
    queue<pair<pair<int,int>,int>> q; //clip, now, before
    for(int i=0;i<1001;i++){
        dp[i] = INF;
    }
    q.push({{-1,1},1});
    while(!q.empty()){
        int clip = q.front().first.first;
        int now = q.front().first.second;
        int before = q.front().second;
        q.pop();
        if(clip==-1){
            q.push({{0,1},1});
            dp[1] = 0;
            continue;
        }
        if(now == clip*2){
            if(dp[now]>=dp[before]+2) dp[now] = dp[before]+2;
        }
        else{
            if(dp[now]>=dp[before]+1) dp[now] = dp[before]+1;
        }

        for(int elem : {now*2, clip+now, now-1}){
            if(now*2 == elem) q.push({{now,elem},now});
            else q.push({{clip,elem},now});
        }
    
        for(int i=0;i<11;i++){
            cout<<i<<" "<<dp[i]<<"\n";
        }
        cout<<clip<<" "<<now<<" "<<before<<"\n";
        cout<<"---------------";    
    }
    for(int i=0;i<100;i++){
        cout<<i <<" "<<dp[i]<<" \n";
    }
}   