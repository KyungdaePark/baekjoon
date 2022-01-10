#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#define MAX 101
using namespace std;

int N,M;
int map[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[y][x] = 0;
    
    while(!q.empty()){
        int nowy = q.front().first;
        int nowx = q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int nexty = nowy + dy[i];
            int nextx = nowx + dx[i];

            if (nexty >=N || nexty <0 || nextx >=M || nextx<0) continue;

            if(map[nexty][nextx]==1){
                if(dist[nexty][nextx] > dist[nowy][nowx]+1){
                    dist[nexty][nextx]= dist[nowy][nowx]+1;
                    q.push({nexty,nextx});
                }
            }
            else if(map[nexty][nextx]==0){
                if(dist[nexty][nextx] > dist[nowy][nowx]){
                    dist[nexty][nextx]= dist[nowy][nowx];
                    q.push({nexty,nextx});
                }
            }
        }
    }
}
int main(){
     cin>>M>>N;
     for(int y=0;y<N;y++){
         string s; cin>>s;
        
         for(int i=0;i<s.size();i++){
             map[y][i] = s[i] - '0';
             dist[y][i] = 99999;
         }
     }
     bfs(0,0);
     cout<<dist[N-1][M-1];
}

// int N,M; //가로 M 세로 N
// int map[MAX][MAX];
// //vector<vector<int>> map;
// int dy[4] = {0,1,0,-1};
// int dx[4] = {1,0,-1,0};
// int result = 99999;
// bool visited[MAX][MAX]={false};

// void dfs(int y, int x, int cnt){
//     if(visited[y][x]) return;
//     if(x==M-1 && y == N-1){
//        result = result>cnt?cnt:result;
//        return;
//     }
//     visited[y][x] = true;
//     for(int i=0;i<4;i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if(nx<M && nx>=0 && ny<N && ny>=0){
//             if(map[ny][nx]==1) dfs(ny,nx,cnt+1);
//             else dfs(ny,nx,cnt);
//         }
//     }
//     visited[y][x] = false;

// }

// int main(){
//     cin>>M>>N;
//     for(int y=0;y<N;y++){
//         string s; cin>>s;
        
//         for(int i=0;i<s.size();i++){
//             map[y][i] = s[i] - '0';
//         }
//     }
//     dfs(0,0,0);
//     cout<<result;
// }
