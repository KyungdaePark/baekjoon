#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

vector<int> v[MAX];
vector<int> ans;
bool visited[MAX]={false};
void dfs(int start){
    if(visited[start] == true){
        return;
    }
    visited[start] = true;
    ans.push_back(start);
    for(int i=0;i<v[start].size();i++){
        dfs(v[start][i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int computers;
    int connects;

    cin>>computers>>connects;
    for(int i=0;i<connects;i++){
        int t1, t2; cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1);
    cout<<ans.size()-1;
}