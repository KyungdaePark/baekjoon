#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int board[16];
int cnt=0;
int N;

void solve(int now_y, int ea){
    cnt = ea;
    for(int i=0;i<ea;i++){
        int queen = board[i];
        int next_y = now_y+1;
        for(int x=0;x<N;x++){
            if(board[i] !=-1 && abs(i-queen) != abs(next_y - x)){
                board[next_y] = x;
            }
        }
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        //board 초기화 here
        board[0] = i;
        solve(1);
    }
    cout<<cnt;
}