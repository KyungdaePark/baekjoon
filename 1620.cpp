#include<iostream>
#include<map>
#include<cctype>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string,int> p;
    map<int,string> p_num;

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp; cin>>tmp;
        p.insert(make_pair(tmp,i+1));
        p_num.insert(make_pair(i+1,tmp));
    }

    for(int i=0;i<m;i++){
        string tmp; cin>>tmp;
        if(isdigit(tmp[0]) == true){
            cout<<p_num[stoi(tmp)]<<"\n";
        }
        else cout<<p[tmp]<<"\n";
    }
}