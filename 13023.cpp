#include<iostream>
#include<vector>
#include<cstring>
#define MAX 2001
using namespace std;
int N,M; //N은 사람수 M은 관계수
bool visited[MAX]={false};
bool check = false;
void dfs(vector<int> v[], int start, int cnt){
    if(cnt==5){
        check = true;
        return;
    }
    if(check) return;
        for(int j=0;j<v[start].size();j++){
            int next = v[start][j];
            if(!visited[next]){
                    visited[next] = true;
                    dfs(v,next,cnt+1);
                    visited[next] = false;
            }
        }
}
int main(){
    cin>>N>>M;
    vector<int> v[N+1];
    for(int i=0;i<M;i++){
        int p1, p2;
        cin>>p1>>p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }
    for(int i=0;i<N;i++){
        memset(visited,false,sizeof(visited));
        dfs(v,i,1);
        if(check==true){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
}