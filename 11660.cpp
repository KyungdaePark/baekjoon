#include<iostream>
using namespace std;

int dp[1024][1024];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin>>N>>M;
    int num;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num;
            if(j==0) dp[i][j] = num;
            else dp[i][j] = dp[i][j-1] + num;
        }
    }
    
    for(int i=0;i<M;i++){
        int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
        x1 = x1-1; x2 = x2-1; y1 = y1-1; y2 = y2-1;
        int sum = 0;
        for(int x=x1;x<=x2;x++){
            int tmp;
            if(y1!=0) tmp = dp[x][y2] - dp[x][y1-1];
            else tmp = dp[x][y2];
            sum+=tmp;
        }
        cout<<sum<<"\n";
    }
}
    