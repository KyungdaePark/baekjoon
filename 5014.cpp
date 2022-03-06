#include<iostream>
#include<queue>
#define MAX 1000001
using namespace std;
int F,S,G,U,D;
// 총,지금,목표,위로,아래로
bool visited[MAX]={false};
int arr[MAX];

void bfs(){
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(visited[now]) continue;
        else visited[now] = true;
        if(now == G) break;
        int up = now + U;
        int down = now - D;
        if(down > 0){
            if(!visited[down]){
                q.push(down);
                arr[down] = now;
            }
        }
        if(up <= F){
            if(!visited[up]){
                q.push(up);
                arr[up] = now;
            }
        }
    }
    if(arr[G] == 0) cout<<"use the stairs";
    else{
        int cnt = 0;
        for(int i=G;i!=S;i=arr[i]){
            cnt++;
        }
        cout<<cnt;
    }
}
int main(){
    //fill_n(arr,MAX,-1);
    cin>>F>>S>>G>>U>>D;
    if(S==G) cout<<0;
    else bfs();
}