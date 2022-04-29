#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[500][500];
    int dp[500][500];

    int n; cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            int sum1 = 0;
            int sum2 = 0;

            if(i!=j) sum1 = arr[i][j] + dp[i-1][j];
            if(j!=0) sum2 = arr[i][j] + dp[i-1][j-1];

            dp[i][j] = sum1 > sum2 ? sum1 : sum2;
        }
    }


    // cout<<"===========================\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"===========================\n";


    int ans = 0;
    for(int i=0;i<n;i++){
        if(ans < dp[n-1][i]) ans = dp[n-1][i];
    }

    cout<<ans;
}