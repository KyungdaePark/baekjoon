#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin>>N;

    priority_queue<int> pq;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        
        if(tmp==0){
            if(pq.size()==0) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        } else{
            pq.push(tmp);
        }
    }
}