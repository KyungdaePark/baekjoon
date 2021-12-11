/*
    N은 3~50사이
    서로 바꿔보는 모든 경우의 수 : (N-1)+(N-1)+N

    제한시간 1초 충분.

    갯수 세는법
    dy dx , 만약 상하 / 좌우 중 같은 게 있다면 거기서 한번 더 탐색
    0,0 -> 0,1 -> ...으로만 가도 됨
    무조건 오른쪽, 아래쪽 방향으로만 실시

    
*/

#include<iostream>
#include<algorithm>
using namespace std;
char map[51][51];

int func_cal(int n){
    int result = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] < )
        } 
    }
}
int main(){
    int N; cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    
}