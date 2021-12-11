/*
    소수 list 중에서, 만들고자 하는 숫자 n을 만족시키는지 체크한다.
    n=a+b에서 a가 소수가 들어있는 벡터의 요소라고 할 때,
    b도 역시 벡터에 들어있는지 체크한다.
    없다면 다른 a로 넘어간다.
    모두 체크했는데 없다면 오류 출력

    시간초과로 인해 b도 벡터에 들어있는지 체크하는 과정을
    binary search를 이용해 진행했다.
*/

#include<iostream>
#include<vector>
using namespace std;
int dp[1000001]{};
vector<int> v;

int search(int target, int start, int end){
    int mid = (start+end)/2;
    if(v[mid] == target) return v[mid];
    if(start>end) return -1;
    if(v[mid] > target) return search(target, start, mid-1);
    if(v[mid] < target) return search(target, mid+1, end);
}
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
    int n; int find=0;
    while(cin>>n){
        if(n==0) break;
        bool judge = false;
        for(int a=0;a<v.size();a++){
            if(v[a] > n) break;
            int b = n - v[a];
            find = search(b, 0, v.size()-1);
            if(find!=-1) judge=true;
            if(judge){
                cout<<n<<" = "<<v[a]<<" + "<<find<<"\n";
                break;
            }
        }
        if(!judge) cout<<"Goldbach's conjecture is wrong."<<"\n";
    }    
}

