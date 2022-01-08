#include<iostream>
#include<vector>
#include<cmath>
#define MAX 21
using namespace std;

int N;
int sum1 = 0;
int sum2 = 0;
int result = 99999;
int map[MAX][MAX];
int arr[MAX];
int arr2[3];
bool visited[MAX] = {false};
bool visited2[MAX] = {false};
void sum_dfs(vector<int>, vector<int>,int,int);
void dfs(int start,int cnt){
    if(cnt == N/2){
        vector<int> v1;
        for(int i=0;i<cnt;i++){
            v1.push_back(arr[i]);
        }
        vector<int> v2;
        for(int i=0;i<N;i++){
            for(int j=0;j<v1.size();j++){
                if(i != v1[j]) v2.push_back(i);
            }
        }
        sum_dfs(v1,v2,0,0);
        sum1 = 0; sum2 = 0;
    }
    for(int i=start;i<N;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(i,cnt+1);
            visited[i] = false;
        }
    }
}

void sum_dfs(vector<int> v1, vector<int> v2, int idx, int cnt){
    if(cnt == 2){
        sum1 += map[v1[arr2[0]]][v1[arr2[1]]];
        sum2 += map[v2[arr2[0]]][v2[arr2[1]]]; //....
        int dif = abs(sum1 - sum2);
        if(dif < result){
            cout<<"sum1 : "<<sum1<<"sum2 : "<<sum2<<"dif : "<<dif<<"\n";
            cout<<"[";
            for(int i=0;i<v1.size();i++){
                cout<<v1[i]<<" ";
            } cout<<"]\n";
            cout<<"[";
            for(int i=0;i<v2.size();i++){
                cout<<v2[i]<<" ";
            } cout<<"]\n";
            result = dif;
        }
    }
    for(int i=idx;i<3;i++){
        if(!visited2[i]){
            visited2[i] = true;
            arr2[cnt] = i;
            sum_dfs(v1,v2,i,cnt+1);
            visited2[i] = false;            
        }
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    dfs(0,0);
    cout<<result;
}