#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;

//vector<pair<int,string>> v;
//deque<int> answer;
int dp[101]; //-1은 기본값
bool visited[101] = {false};
int N; //N은 단어의 수

void sol(int idx, int cnt,vector<pair<int,string>>& v, deque<int>& answer){
    visited[idx] = true;
    int charSize = v[idx].second.size();
    char last_letter = v[idx].second[charSize-1];

    int next = -1; //next가 -1이면 마지막
    for(int i=0;i<v.size();i++){
        if(!visited[i]){
            if(v[i].second[0] == last_letter){
                next = i;
                dp[next] = idx; 
                sol(next,cnt+1,v,answer);
                dp[next] = -1;
            }
        }
    }
    visited[idx] = false;
    if(next == -1 && cnt < N-1){ // 모든 단어를 방문하지 않고 끝난 경우
        return;
    }
    else if(next == -1 && cnt == N-1){
        //여기에 정답 출력
        for(int i = idx; i !=-1; i = dp[i]){
            answer.push_back(i);
        }
        return;
    }
}

int main(){
    int C; cin>>C; //C는 테스트 케이스의 수
    while(C--){
        vector<pair<int,string>> v;
        deque<int> answer;
        // while(true){
        //     if(v.size()!=0) v.pop_back();
        //     if(answer.size()!=0) answer.pop_back();
        //     if(v.size() == 0 && answer.size()==0) break;
        // }
        for(int i=0;i<101;i++){
            dp[i] = -1;
        }
        memset(visited,false,sizeof(visited));
        cin>>N;
        for(int i=0;i<N;i++){
            string tmp; cin>>tmp;
            v.push_back({i,tmp});
        }
        for(int i=0;i<N;i++){
            if(answer.size()==0){ //정답이 나오지 않았다면
                sol(i,0,v,answer);
            }
        }
        if(answer.size()==0){
            cout<<"IMPOSSIBLE";
        }
        else{
            while(!answer.empty()){
                int index = answer.back();
                cout<<v[index].second<<" ";
                answer.pop_back();
            }
            cout<<"\n";
        }
    }
}
