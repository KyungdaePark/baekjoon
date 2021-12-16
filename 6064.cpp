/*
    N M x y
    13 11 5 6
    i가 돌아가는데, i가 5, 18,33,48...로 고정되게 하고
    그때마다 y 연산을 하면된다.
    그럼 O(N*M)만큼 하지 않아도 된다.
    N과 M의 최소공배수보다 작거나 같은동안만 i가 증가하면 된다.
*/

#include<iostream>
using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}
int main(){
    int T; cin>>T;
    while(T--){
        int N,M,x,y;
        cin>>N>>M>>x>>y;
        int ans = -1;
        int i = x;
        while(1){    
            if(lcm(N,M)<i) break;
            if(i%M==y){
                ans = i;
                break;
            }
            i += N;
        }
        cout<<ans<<"\n";
    }
}