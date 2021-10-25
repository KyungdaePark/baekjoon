#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int answer = 0;
    for(int i=n;i>0;i--){
        answer += i*v[n-i];
    }
    cout<<answer;
}