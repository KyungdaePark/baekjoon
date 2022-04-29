#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<string> both;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<string> no_see;

    int n,m; cin>>n>>m;
        for(int i=0;i<n+m;i++){
        string name; cin>>name;
        no_see.push_back(name);
    }

    sort(no_see.begin(), no_see.end());
    for(int i=0;i<no_see.size()-1;i++){
        if(no_see[i]==no_see[i+1]){
            both.push_back(no_see[i]);
            i++;
        }
    }

    cout<<both.size()<<"\n";
    sort(both.begin(),both.end());
    for(string o : both){
        cout<<o<<"\n";
    }
}