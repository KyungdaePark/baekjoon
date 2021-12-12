/*
    14500 테트로미노
     ㅡ,ㄴ,ㅁ,ㄹ 모양은 dfs를 이용해서 depth=4 (처음 depth = 1) 까지 이동하며 숫자의 합을 구한다.
     단, 한 loop 에서 이미 방문한 좌표는 제거하기 위해 visited 체크한다.
     ㅗ 모양은 직접 하드코딩한다.
*/

#include<iostream>

#define MAX 501
using namespace std;
int board[MAX][MAX];
bool visited[MAX][MAX]{false};
int dfs_result = 0;

void dfs(int start_y, int start_x){
    if(visited[start_y][start_x]) return;
    
    
}

int func_cal(int y, int x){
    dfs(y,x);
}
int main(){
    int N,M; //N 세로 M 가로
    cin>>N>>M;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin>>board[y][x];
        }
    }
    int result = 0;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            result = max(result, func_cal(N, M)); //func_cal will return dfs result
        }
    }   
}