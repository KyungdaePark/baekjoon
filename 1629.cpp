#include<iostream>

using namespace std;
int dp[1000];
int modul;
void solve(int a, int b, int c, int mod){
    if(b==0){
        modul = mod;
        return;
    }
    int tmp  = a%c;
    solve(tmp*a,--b,c,tmp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;

    cin>>a>>b>>c;
    solve(a,b,c,0);
    cout<<modul;
}