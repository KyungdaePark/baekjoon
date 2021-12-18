/*
    1~N중 중복없이 M개 고른 수열 모두 출력
    N=4 M=2 -> 12 13 14 21 23 24 31 32 34 41 42 43

    답을 출력할 때 각 숫자는 배열의 한 칸
    ex) 2 3 을 출력할때는 arr[0]에 2 arr[1]에 3
*/
#include<iostream>
#include<vector>
using namespace std;

int N,M;
int arr[9];
bool visited[9]={false};

void dfs(int cnt){ //cnt는 총개수
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=N;i++)    { 
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            visited[i] = false;
        }        
    }
    // 왜 cnt는 0으로 시작하는건가?
    /* 
        arr[0] = 1
        arr[1] = 2
        arr[2] = 1
        arr[3] = 3
    */
}


//N이 3 M이 2
// 12 13 21 23 31 32
int main(){
    cin>>N>>M;
    dfs(0);
}