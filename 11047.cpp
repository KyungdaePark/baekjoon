#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,K;
    vector<int> v;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    int now = K;
    int answer = 0;
    for(int i=N-1;i>=0;i--){
        if(v[i] <= now){
            now -= v[i];
            answer++;
            i=N-1;
        }
    }
    cout<<answer;
}