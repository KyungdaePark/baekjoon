#include<iostream>
using namespace std;
int N;
int P[16];
int T[16]{0};
int dp[16];
int final_ans = 0;
void dfs(int now, int answer){
    int nd = now + T[now];
    if(nd > N || now == N){
        if(final_ans < answer){
            final_ans = answer;
        }
        return;
    }
    for(int i=nd;i<=N;i++){
        dfs(i,answer+P[now]);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>T[i]>>P[i];
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        dfs(i,answer);
        dp[i] = final_ans;
        final_ans = 0;
    }
    int result = 0;
    for(int i=0;i<N;i++){
        result = dp[i] > result ? dp[i] : result;
    }
    cout<<result;

}