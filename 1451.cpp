#include<iostream>
using namespace std;

#define MAX 100
int main(){
    int N,M;
    cin>>N>>M;
    int board[MAX][MAX];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
}