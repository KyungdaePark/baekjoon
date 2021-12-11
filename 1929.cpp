/*
    아리스토테네스의 체를 사용한다
    2,3,4,5,6...의 배수를 모두 제거한다
    이때 이미 자기자신이 소수가 아닌 경우에는 skip한다.

    = 2 이상의 자연수 x가 1씩 늘어날때,
    2부터 백만 사이의 x의 배수를 모두 제거한다.
    이때 x가 이미 소수가 아닌경우에는 skip한다.
*/

#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
int dp[1000001]{};
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // time_t start = clock();

    for(int i=2;i<=1000000;i++){
        dp[i] = i;
    }
    for(int i=2;i<=1000000;i++){
        if(dp[i]==0) continue;
        for(int j=2;i*j<=1000000;j++){ //2,3 같은 "자기자신이 소수"인 경우는 제거하면 안되므로 j=2부터 시작
            dp[i*j] = 0;
        }
    }
    for(int i=0;i<1000000;i++){
        if(dp[i]!=0){
            v.push_back(dp[i]);
        }
    }
    

    int a;
    int b;
    cin>>a>>b;
    for(int i=0;i<v.size();i++){
        if(v[i] > b) break;
        if(v[i] >= a){
            cout<<v[i]<<"\n";
        }
    }
    // time_t end = clock(); // 시간 측정 끝
    // double result = (double)(end - start);
    // cout<<result<<endl;
}

