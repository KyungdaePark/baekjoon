#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> T;

int N,K;
int max_value = 0;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}

void solve(int start, int sum_weight, int sum_value){
    if(start >= N){
        if(max_value < sum_value) max_value = sum_value;
        return;
    }
    else if(sum_weight + T[start].first > K){
        solve(start+1, sum_weight, sum_value);
    }
    else if(sum_weight + T[start].first <= K){
        // sum_weight += T[start].first;
        // sum_value += T[start].second;
        solve(start+1, sum_weight+T[start].first, sum_value+T[start].second);
    }
    solve(start+1, sum_weight, sum_value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int w, v;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>w>>v;
        T.push_back(make_pair(w,v));
    }
    sort(T.begin(), T.end(), compare);
    
    for(int i=0;i<N;i++){
        solve(i,0,0);
    }
    cout<<max_value;
}