
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
            arr[cnt] = i;
            dfs(cnt+1);
        }        
    }
   
}

int main(){
    cin>>N>>M;
    dfs(0);
}