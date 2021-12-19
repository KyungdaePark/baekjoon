/*
    인접한 칸 더하기 x 
    N M K 입력

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 11
using namespace std;
int N,M,K;

//우 하 좌 상
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int board[MAX][MAX];
bool visited[MAX][MAX];
int ans_sum = -10000;

bool check(int y, int x){
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx>=0 && nx<M && ny>=0 && ny<N){
            if(visited[ny][nx]) return false;
        }
    }
    return true;
}
void dfs(int depth,int sum){
    if(depth == K){
        if(sum>ans_sum) ans_sum=sum;
        return;
    }
    bool ok = false;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){ //이중포문을 dfs 안에서 처리할 경우, 시작 지점 자체에서 새로운 dfs를 계속해서 만들어내므로, main함수에서 이중포문을 사용했을땐 한칸씩만 움직일 수 있었던 것들이 여기서는 범위 내에서 자유롭게 움직 일 수 있다. (시작 지점 x, y 가 게속해서 바뀌기 때문에, 좀 비효율적이더라도 어짜피 visited가 해결해준다.)
           
            if(!visited[y][x] && check(y,x)){
            visited[y][x] = true;
            sum+=board[y][x];
            cout<<y<<" "<<x<<" "<<sum<<" "<<depth<<"\n";
            dfs(depth+1, sum);
            visited[y][x] = false;
            }
        }
    }
}
int main(){
    cin>>N>>M>>K;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin>>board[y][x];
        }
    }

    dfs(0,0);
    cout<<ans_sum;
}