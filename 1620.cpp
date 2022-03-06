#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> v;

bool isNumber(string s){
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        string tmp;
        cin>>tmp;
        if(isNumber(tmp)){
            cout<<v[stoi(tmp)-1]<<"\n";
        }
        else{
            for(int j=0;j<v.size();j++){
                if(tmp == v[j]) cout<<j+1<<"\n";
            }
        }
    }
}