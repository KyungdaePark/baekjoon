#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int N;
void solve(int r, int c, int T,vector<int> order){
    if(T==1){
        int n = pow(4,N-1);
        int ans = 0;
        for(int i=0;i<order.size();i++){
            ans += order[i]*n;
            n=n/4;
        }
        cout<<ans;
        return;
    }

    if(0<=r && r<T/2 && 0<=c && c<T/2){ // 북서 
        order.push_back(0);
        solve(r,c,T/2,order);
    } else if(0<=r && r<T/2 && T/2<=c){ // 동북
        order.push_back(1);
        solve(r,c-T/2,T/2,order);
    } else if(T/2<=r && 0<=c && c<T/2){ // 서남
        order.push_back(2);
        solve(r-T/2,c,T/2,order);
    } else if(T/2<=r && T/2<=c){ // 남동
        order.push_back(3);
        solve(r-T/2,c-T/2,T/2,order);
    }
}

int main(){
    cin>>N;
    int T = pow(2,N);
    int r,c; cin>>r>>c;
    vector<int> order;
    solve(r,c,T,order);
    
}