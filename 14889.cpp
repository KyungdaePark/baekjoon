#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#define MAX 21
using namespace std;

int N;
int sum1 = 0;
int sum2 = 0;
int result = 99999;
int map[MAX][MAX];
int arr[MAX];
bool visited[MAX] = {false};


void dfs(int idx, int cnt, int target,int end,vector<int> v){
    if(cnt == target){
        for(int i=0;i<cnt;i++){
            v.push_back(arr[i]);
        }
        return;
    }
    for(int i=idx;i<end;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[cnt] = i;
            dfs(i,cnt+1,target,end,v)
            visited[i]=false;
        }
    }
}
void cal(int arr[], vector<int> arr2){
    vector<int> v;
    dfs(0,0,2,arr2.size(),v);   
    int cnt =0;
    int arr3[3];
    for(int i=0;i<v.size();i++){
        arr3[cnt] = v[i];
        if(cnt==2){
            for(int i=0;i<)
        }
    }
}
void sol(){
    vector<int> v;
    dfs(0,0,N/2,end,v); //target은 숫자 몇개씩 묶을건지 end는 0부터 몇까지 계산할건지 //v는 그것들을 저장할 벡터
    int cnt = 0;
    int arr[3];
    vector<int> arr2;
    for(int i=0;i<v.size();i++){
        arr[cnt] = v[i];
        cnt++;
        if(cnt==2){
            for(int j=0;j<N;j++){
                for(int k=0;k<3;k++){
                    if(j!=v[k]){
                        arr2.push_back(j);
                    }
                }
            }
            cal(arr,arr2);
            memset(arr2,0,sizeof(arr2)); //grammar
            cnt=0;
        }

    }
}
int main()터
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    sol();
    
    
}