#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int S[21];
void solve(string k, int n){  
    if(k=="add"){
        S[n]=1;
    }
    else if(k=="remove"){
        S[n]=0;
    }
    else if(k=="check"){
        if(S[n]==1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    else if(k=="toggle"){
        if(S[n]==1) S[n]=0;
        else S[n]=1;
    }
    else if(k=="all"){
        for(int i=0;i<21;i++){
            S[i]=1;
        }
    }
    else if(k=="empty"){
        for(int i=0;i<21;i++){
            S[i]=0;
        }
    }
}        

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int M; cin>>M;
    string s; int n;
    for(int i=0;i<M;i++){
        cin>>s;
        if(s=="empty" || s=="all") solve(s,0);
        else{
            cin>>n;
            solve(s,n);
        }
    }
}