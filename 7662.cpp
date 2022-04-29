#include<iostream>
#include<vector>
#include<queue>
#include<cstring>


#define MAX 1000001
using namespace std;

bool visited[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin>>T;

    for(int t=0;t<T;t++){
        memset(visited,false,sizeof(visited));
        int k; cin>>k;
        priority_queue<pair<int,int>> maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

        for(int i=0;i<k;i++){
            char op;
            int q;
            cin>>op>>q;
            if(op == 'I'){
                maxheap.push(make_pair(q,i));
                minheap.push(make_pair(q,i));
                visited[i] = true;
            }
            else if(op=='D' && (maxheap.empty() || minheap.empty())) continue;
            else{
                if(q==1){
                    while(!visited[maxheap.top().second] && !maxheap.empty())
                        maxheap.pop();
                    if(!maxheap.empty()){
                        visited[maxheap.top().second] = false;
                        maxheap.pop();
                    }
                }else{
                    while(!visited[minheap.top().second] && !minheap.empty())
                        minheap.pop();
                    if(!minheap.empty()){
                        visited[minheap.top().second] = false;
                        minheap.pop();
                    }
                }
            }
        }
        while(!visited[maxheap.top().second] && !maxheap.empty()) maxheap.pop();
        while(!visited[minheap.top().second] && !minheap.empty()) minheap.pop();

        if(maxheap.empty() && minheap.empty()) cout<<"EMPTY\n";
        else cout<<maxheap.top().first<<" "<<minheap.top().first<<"\n";
    }
    return 0;
}