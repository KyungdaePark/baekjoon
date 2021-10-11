#include<iostream>
#include<queue>
using namespace std;

int su, br;

int route[150000] = {0};

int main(){
    int result = 0;
    cin>>su>>br;
    if(su==br){
        cout<<0;
        return 0;
    }
    queue<int> q;
    q.push(su);
    route[su]=0;
    int cnt = 0;
    bool visited[150000] = {false};
    visited[su] = true;
    while(!q.empty()){
        int current = q.front();
       // for(int i=0;i<20;i++)
        //    cout<<route[i]<< " ";
       //  cout<<"\n";
        // cout<<current<<"\n";
        if(current == br){
            result = route[current];
            break;
        }
        q.pop();
        if(!visited[current+1]){
            int plus = current +1;
            route[plus] = route[current] +1;
            visited[plus] = true;
            q.push(plus);
        }
        if(current <= 70000 && current!=0 && !visited[current*2]){
            int multi = current*2;
            route[multi] = route[current] +1;
            visited[multi] = true;
            q.push(multi);
        }
        if(current != 0 && !visited[current-1] ){
            int minus = current -1;
            route[minus] = route[current] +1;
            visited[minus] = true;
            q.push(minus);
        }

    }
    cout<<result;
}