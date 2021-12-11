/*
    3
    iabucdpefcg

    나머지가 0
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num; cin>>num;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%num==0){
            v.push_back(s[i]);
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}