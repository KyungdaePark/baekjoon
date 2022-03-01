#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){ //return이 false면 swap
    if(p1.second == p2.second) return p1.first < p2.first; 
    else return p1.second < p2.second;
}
int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> meet;
    for(int i=0;i<N;i++){
        int p1,p2; cin>>p1>>p2;
        meet.push_back(make_pair(p1,p2));
    }
    sort(meet.begin(), meet.end(), cmp);
    
    int time = meet[0].second;
    int n = 1;
    for(int i=1;i<N;i++){
        if(time <= meet[i].first){
            n++;
            time = meet[i].second;
        }
    }
    cout<<n;
}