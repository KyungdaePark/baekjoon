#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<pair<int,int>> v[501];

int re_sum = 987654321;
bool visited[501];
void dfs(int start, int target,int sum){
    if(start == target){
        if(re_sum > sum){
            re_sum = sum;
            return;
        }
    }

    for(int i=0;i<v[start].size();i++){
        int next_num = v[start][i].first;
        int next_time = v[start][i].second;

        if(!visited[next_num]){
            visited[next_num] = true;
            dfs(next_num, target, sum+next_time);
            visited[next_num] = false;    
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TC; cin>>TC;
    int wt;
    for(int t=0;t<TC;t++){
        int N,M,W;
        cin>>N>>M>>W;
        for(int i=0;i<M;i++){
            int S,E,T;
            cin>>S>>E>>T;
            v[S].push_back(make_pair(E,T));
            v[E].push_back(make_pair(S,T));
        }
        for(int i=0;i<W;i++){
            memset(visited,false,sizeof(visited));
            re_sum = 987654321;
            int S,E;
            cin>>S>>E>>wt; // for 웜홀
            dfs(S,E,0);
            if(re_sum < wt){
                cout<<"YES\n";
                break;
            }
        }
        if(re_sum >= wt) cout<<"NO\n";
    }
}