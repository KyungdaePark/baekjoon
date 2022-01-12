#include<iostream>
#include<queue>
//최단거리 cost를 구한뒤 앞으로 M에 도착할 때 마다 cost랑 같은지 판단 : 같다면 cost++
#define MAX 100001
using namespace std;
int N,M;
int main(){
    cin>>N>>M;
    int total_cost = -1;
    int cnt = 0;
    queue<pair<int,int>> q; // N and cost
    bool visited[MAX] = {false};
    q.push({N,0});
    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        visited[now] = true;
        if(now == M && total_cost == -1){
            total_cost = cost;
            visited[now] = false;
        }
        
        if(now == M && total_cost !=-1 && cost==total_cost){
            cnt++;
            visited[now] = false;
        }
        for(int dif : {now+1, now-1, now*2}){
            if(dif>=0 && dif<=MAX-1 && !visited[dif]){
                q.push({dif,cost+1});
            }
        }
    }

    cout<<total_cost<<"\n"<<cnt;
}