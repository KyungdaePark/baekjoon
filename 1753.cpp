#include<iostream>
#include<vector>
#include<queue>
#define INF 9999999
using namespace std;

//int dp[20001][20001]; //가중치
vector<pair<int,int>> dp[20001];
int ans[20001];
int V,E;

// void dfs(int start,int cnt){
//     if(cnt==E) return;
//     for(int i=0;i<dp[start].size();i++){
//         int next = dp[start][i].first;
//         int next_add = dp[start][i].second + ans[start];
//         if(next_add < ans[next]) ans[next] = next_add;
//         dfs(next,++cnt);
//     }
// }

void bfs(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,start));
    ans[start] = 0;
    while(!pq.empty()){
        int now_num = pq.top().second; //U
        int now_add = pq.top().first;  //x
        pq.pop();

        if(ans[now_num] < now_add) continue;
        for(int i=0;i<dp[now_num].size();i++){
            int next_num = dp[now_num][i].first; //V
            int next_add = dp[now_num][i].second; //W

            // if(ans[now_num] + next_add < ans[next_num]){
            //     ans[next_num] = ans[now_num] + next_add;
            //     pq.push(make_pair(next_add, next_num));
            // }
            if(now_add + next_add < ans[next_num]){
                ans[next_num] = now_add + next_add;
                pq.push(make_pair(now_add + next_add, next_num));
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(ans[i] == INF) cout<<"INF\n";
        else cout<<ans[i]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>V>>E;
    for(int i=1;i<=V;i++){
        ans[i]=INF;
    }
    int K; cin>>K;
    //ans[K] = 0;
    for(int i=0;i<E;i++){
        int s,e,w;
        cin>>s>>e>>w;
        dp[s].push_back(make_pair(e,w));
        //dp[s][e] = w;
    }
    // for(int i=1;i<=V;i++){
    //     //dfs(K,0);
    //     bfs(K);
    //     if(ans[i] == INF) cout<<"INF\n";
    //     else cout<<ans[i]<<"\n";
    // }
    bfs(K);
}

/*
    dfs로 풀려다가(vector) 공간 초과
    다익스트라 - 
        queue로 풀려다가 시간 초과
        prioirty_queue 로 풀다가 pair의 first 값을 다음 정점으로 해서 시간초과
            (이러면 사실상 그냥 queue임)
        그래서 first에 가중치 넣었더니 78%에서 시간초과
        알고보니 first에 기존의 가중치까지 다 넣어줘야 시간초과 안생김
        
    
*/