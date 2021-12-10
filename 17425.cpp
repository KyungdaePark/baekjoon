/*
    약수 합 구하기 : dp 사용
    약수의 합2 문제(17427)은 g(N)의 경우 N을 1부터 N까지 나눈 후 자기 자신(1~N)을 곱하여 g를 계산하였다.
    하지만 이 문제를 그렇게 풀 경우 시간초과로 이어진다.
    따라서 이 문제는 17427문제를 역으로 생각하여, 1부터 백만까지 공간을 가지고 있는 배열을 만든 후,
    자기 자신(1~백만)의 배수에 해당하는 index에 스스로를 더하여 계산하였다.
    이렇게까지 계산하면 (j for문) f(x)를 구한 것이므로,
   그 전 f(x-1) 의 함숫값에 f(x)를 더하여 g(x)를 구현해 나가는 방식으로 진행하였다.
   이렇게 하면 테스트 케이스가 몇개이든 간에 무조건 1부터 백만까지 모두 계산해 놓은 상태에서 진행하므로 
   기존 O(백만*십만)이 아닌 O(백만 + 십만)이 될 수 있다.
*/

#include<iostream>
using namespace std;
long long dp[1000001]{};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin>>tc;
    for(int i=1;i<=1000000;i++){
        for(int j=1;i*j<=1000000;j++){
            dp[i*j] += i;
        }
        dp[i]+=dp[i-1];
    }
    for(int i=0;i<tc;i++){
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
}