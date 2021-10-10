#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M;
int input[8][8];
int temp[8][8];
int result = 0;
queue<pair<int,int>> q;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
void BFS(){
    int AfterSpread[8][8];

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            AfterSpread[i][j] = temp[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(AfterSpread[i][j] == 2){
                q.push(make_pair(i,j));     
            }
        }
    }

    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = dy[i] + current.first;
            int nx = dx[i] + current.second;
            if(0<=ny && ny < N && 0<=nx && nx<M)
                if(AfterSpread[ny][nx]==0){
                  AfterSpread[ny][nx] = 2;
                  q.push(make_pair(ny,nx));
                }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j=0;j<M;j++){
            if(AfterSpread[i][j] == 0) cnt++;
        }
    }
    result = max(result, cnt);
}


void makeWall(int cnt){
    if(cnt == 2){
        BFS();
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
                if(temp[i][j]==0){
                    temp[i][j] = 1;
                    makeWall(cnt+1);
                    temp[i][j]=0;
            }
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(input[i][j] == 0){

                for(int a=0;a<N;a++){
                    for(int b=0;b<M;b++){
                        temp[a][b] = input[a][b];
                    }
                }
                temp[i][j] = 1;
                makeWall(0);
                temp[i][j] = 0;
            }
        }
    }
    cout<<result;
}
