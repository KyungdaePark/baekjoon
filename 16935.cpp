#include<iostream>
#include<vector>
using namespace std;
int y, x;
void sol(int key, vector<int>* v, &vector<int>* a){
    if(key == 1){
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                a[i][j] = v[y-1-i][j];
            }
        }
    }

    if(key == 2){
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                a[i][j] = v[i][x-1-j];
            }
        }
    }
    return a;
}
int main(){
    cin>>y>>x;
    int R; cin>>R;

    vector<int> v[y];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int tmp; cin>>tmp;
            v[i].push_back(tmp);
        }
    }    
    vector<int> a[y];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            a[i].push_back(v[i][j]);
        }
    }
    while(R--){
        int key; cin>>key;
        sol(key,v,a);           
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}