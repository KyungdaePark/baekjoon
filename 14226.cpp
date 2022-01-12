#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int dp[1001];
//bool dp[1001]={false};
vector<int> v;
int main(){
    int S; cin>>S;
    queue<pair<int,int>> q; //before, now
    for(int i=0;i<1001;i++){
        dp[i] = -1;
    }
    q.push({-1,1});
    while(!q.empty()){
        int before = q.front().first;
        int now = q.front().second;
        q.pop();
        if(before==-1){
            q.push({1,2});
            continue;
        }
        if(dp[now]==-1){
            dp[now] = before;
        }
        if(now == S){
            break;
        }
        for(int next:{now*2, before+now, now-1}){
            if(next>=2 && next<=1000 && dp[next]==-1){
                q.push({now,next});
            }
        }
    }
    for(int i=S;i!=1;i=dp[i]){
        v.push_back(i);
    }
    int cnt =0;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]/v[i+1] == 2 && v[i] % v[i+1] ==0) cnt+=2;
        else cnt++;
    }
    cout<<cnt+2;
}