#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int front = 0;
    int diff = 0;
    for(int i=0;i<progresses.size();i++)
        q.push(i);
    while(!q.empty()){
        while(true){
            for(int i=0;i<progresses.size();i++){
                progresses[i] = progresses[i] + speeds[i];
            }
            if(progresses[front]>=100) break;
        }
        bool done = false;
        while(!done){
            for(int i=front;i<progresses.size();i++){
                if(progresses[i]<100){
                    diff = abs(front - i);
                    front = i;
                   cout<<diff<<" "<<front;
                    done = true;
                }
            }
        }
        cout<<"gdgdgd";
        answer.push_back(diff);
        for(int i=0;i<diff;i++)
            q.pop();
    }
    return answer;
}

int main(){
    vector<int> p;
    vector<int> s;
    int temp; int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>temp;
        p.push_back(temp);
    }
    for(int i=0;i<size;i++){
        cin>>temp;
        s.push_back(temp);
    }
    vector<int> k = solution(p,s);
    for(int i=0;i<k.size();i++){
        cout<<k[i]<<" ";
    }
}