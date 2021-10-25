#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

void dfs(int n,bool visited[], int checked[],vector<vector<int>> v){
    int current = n;
    if(visited[current])  return;
    visited[current] = true;
    for(int i=0;i<v[current].size();i++){
        if(!visited[i]){
            checked[i] = checked[current]+1;
            dfs(v[n][i],visited, checked, v);
        }
    }
}
int main(){
    int C, N;
    cout<<"Gd";
    cin>>C;
    for(int i=0;i<C;i++){
        vector<vector<int>> v(MAX, vector<int>(0,MAX)); //2차원 벡터 만들터
        cin>>N;

        for(int i=0;i<N-1;i++){
           int p1, p2;
           cin>>p1>>p2;    
           v[p1].push_back(p2);
           v[p2].push_back(p1);
        }
        int realsmall = 999999999;
        int answer = 0;
        for(int i=0;i<N;i++){
            bool visited[MAX];
            int checked[MAX];
            checked[i] = 1;
            dfs(i,visited, checked,v);
            int small = 99999999;
            for(int k=0;k<N;k++){
                small = min(small, checked[k]);
                if(small < realsmall){
                    realsmall = small;
                    answer = k;
                }
            }
        }
        cout<<answer;
    }
}