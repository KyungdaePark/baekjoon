#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v;
    int num; cin>>num;
    int temp;
    for(int i=0;i<num;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int ans = v[0] * v[v.size()-1];
    cout<<ans;
}