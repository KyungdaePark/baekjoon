/*
    소수 list 중에서, 만들고자 하는 숫자 n을 만족시키는지 체크한다.
    n=a+b에서 a가 소수가 들어있는 벡터의 요소라고 할 때,
    b도 역시 벡터에 들어있는지 체크한다.
    없다면 다른 a로 넘어간다.
    모두 체크했는데 없다면 오류 출력
*/

#include<iostream>
#include<vector>
using namespace std;
int dp[1000001]{};
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
    int n;
    while(cin>>n){
        if(n==0) break;
        bool judge = false;
        for(int a=0;a<v.size();a++){
            if(v[a] > n) break;
            int b = n - v[a];
            for(int i = 0; i<v.size();i++){
                if(v[i] == b){
                    cout<<n<<" = "<<v[a]<<" + "<<v[i]<<"\n";
                    judge = true;
                    break;
                }
            }
            if(judge) break;
        }
        if(!judge) cout<<"Goldbach's conjecture is wrong."<<"\n";
    }    
}

