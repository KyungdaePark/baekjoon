#include<iostream>
#define MAX 1000000
using namespace std;

long long arr[MAX];
long long dp[MAX];
int N,M,K;

void cal(){
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        dp[i] = dp[i-1] + arr[i];
    }
}
void sol(int a, int b, int c){
    int dif = 0;
    if(a==1){
        //dif = c - arr[b-1];
        arr[b-1] = c;
        cal();
    }
    else if(a==2){
        if(b!=1) cout<<dp[c-1] - dp[b-2]<<"\n";
        else cout<<dp[c-1]<<"\n";
    }
}
int main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cal();
    for(int i=0;i<M+K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sol(a,b,c);
    }
}

/*
#include<iostream>
using namespace std;

int arr[1000001];

void sol(int a, int b, int c){
    if(a==1){
        arr[b-1] = c;
    }
    if(a==2){
        int sum = 0;
        for(int i=b-1;i<c;i++){
            sum+=arr[i];
        }
        cout<<sum;
    }
}
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int a, b, c;
    for(int i=0;i<M*K;i++){
        cin>>a>>b>>c;
        sol(a,b,c);
    }

} 
*/