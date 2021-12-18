#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
int arr[9];
vector<int> v;
bool visited[9]={false};

void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0;i<N;i++){ 
        if(!visited[i]){
            arr[cnt] = v[i];
            dfs(cnt+1);
        }        
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    dfs(0);
}