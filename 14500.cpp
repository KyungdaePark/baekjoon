/*
    14500 테트로미노
     ㅡ,ㄴ,ㅁ,ㄹ 모양은 dfs를 이용해서 depth=4 (처음 depth = 1) 까지 이동하며 숫자의 합을 구한다.
     단, 한 loop 에서 이미 방문한 좌표는 제거하기 위해 visited 체크한다.
     ㅗ 모양은 직접 하드코딩한다.
*/

#include<iostream>
#include<cstring>
#include<algorithm>

#define MAX 510
#define k sum=max(sum,board[start_y][start_x] + board[start_y+1][start_x] + board[start_y+2][start_x] + board[start_y+1][start_x+1]);
#define j sum=max(sum,board[start_y][start_x] + board[start_y+1][start_x] + board[start_y+2][start_x] + board[start_y+1][start_x-1]);
#define n sum=max(sum,board[start_y][start_x] + board[start_y][start_x+1] + board[start_y][start_x+2] + board[start_y+1][start_x+1]);
#define h sum=max(sum,board[start_y][start_x] + board[start_y][start_x+1] + board[start_y][start_x+2] + board[start_y-1][start_x+1]);
using namespace std;
int board[MAX][MAX]{0};
bool visited[MAX][MAX]{false};
int dfs_result = 0;
int N,M; //세로 N 가로 M
// 우 하 좌 상
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void dfs(int start_y, int start_x, int depth, int sum){
    if(depth>4){
        dfs_result = max(sum, dfs_result);
        return;
    }
    if(visited[start_y][start_x]) return;
    if(start_y < 0 || start_y == N || start_x < 0 || start_x == M) return;

    visited[start_y][start_x] = true;
    sum+=board[start_y][start_x];

    cout<<"NOW DEPTH IS : "<<depth<<" "<<sum<<" "<<start_x <<" "<< start_y<<"\n";

    for(int i=0;i<4;i++){
        dfs(start_y + dy[i], start_x + dx[i], depth+1, sum);
    }
}
       
void shape(int start_y, int start_x){
    int sum = 0;
    if(start_x == 0 && start_y == 0){
        k n
    }
    else if(start_x == 0){
        k h n
    }
    else if(start_y == 0){
        k n j
    } else{
        k n j h
    }
    dfs_result = max(sum, dfs_result);
}


void func_cal(int y, int x){
    dfs(y,x,1,0);
    shape(y,x);
}
int main(){
    cin>>N>>M;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin>>board[y][x];
        }
    }
    int result = 0;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            func_cal(y, x); //func_cal will return dfs result
            memset(visited,false,sizeof(visited));
        }
    }
    cout<<dfs_result;

}