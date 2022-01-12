#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int N,K;
int dp[200001];
vector<int> v;
queue<int> q;
void bfs(){
    q.push(N);
    dp[N] = N;
    while(!q.empty()){
        int now = q.front();
        if(now==K) break;
        q.pop();

        if(dp[now*2]==-1 && now*2<=100000){
            dp[now*2] = now;
            q.push(now*2);
        }
        
        if(dp[now-1]==-1 && now-1>=0){
            dp[now-1] = now;
            q.push(now-1);
        }
        if(dp[now+1]==-1 && now+1<=100000){
            dp[now+1] = now;
            q.push(now+1);
        }
        
    }
    for(int i=K;i!=N;i=dp[i]){
        v.push_back(i);
    }
    v.push_back(N);
}
int main(){
    cin>>N>>K;
    for(int i=0;i<200001;i++){
        dp[i] = -1;
    }
    bfs();
    int cnt = 0;
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<v.size()<<"\n";
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]==0){
            cnt++;
            break;
        }
        if(v[i]/v[i+1] ==2 && v[i]%v[i+1]==0) continue;
        else cnt++;
    }
    cout<<cnt;
}