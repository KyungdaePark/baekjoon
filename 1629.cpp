#include<iostream>

using namespace std;
int dp[]
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin>>a>>b>>c;
    int ans = 1;
    int cnt = b;
    while(cnt > 0){
        int idx = c - cnt;
        ans = (ans * (a % c)) % c;
        cnt--;
    }       
    cout<<ans;
}