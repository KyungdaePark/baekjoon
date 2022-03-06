#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1000001];
bool visited[1000001]{false};
bool dfs(int a, int start){
    if(a==start) return true;
    for(int i=0;i<v[start].size();i++){
        if(!visited[start]){
            visited[start] = true;
            dfs(a,v[start][i]);
            visited[start] = false;
        }
    }
    return false;
}
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==0){
            v[a].push_back(b);
            v[b].push_back(a);
        }
        else if(t==1){
            if(dfs(a,b)){
                cout<<"YES\n";
            }else cout<<"NO\n";
        }
    }
}