#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void dfs(int v[MAX][MAX], int nowy, int nowx, int width, int height, bool visited[MAX][MAX]){
    if(visited[nowy][nowx]) return;
    visited[nowy][nowx] = true;
    if(v[nowy][nowx]==1){
        for(int i=0;i<4;i++){
            int nexty = nowy + dy[i];   
            int nextx = nowx + dx[i];
            if(nexty<height && nexty >=0 && nextx<width && nextx>=0 && 
                !visited[nexty][nextx]){
                    if(v[nexty][nextx]==1){
                        dfs(v,nexty,nextx,width,height,visited);
         
                    }
            }
        }
    }
}

int main(){
    int T;
    cin>>T;
    bool visited[MAX][MAX];
    for(int i=0;i<T;i++){
        int v[MAX][MAX]= {};
        int width, height,tall;
        cin>>width>>height>>tall;
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                visited[i][j] = false;
                v[i][j] = 0;
            }
        }
        int cnt = 0;
        for(int i=0;i<tall;i++){
            int p1, p2;
            cin>>p1>>p2;
            v[p2][p1] = 1;
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(!visited[i][j] && v[i][j]==1)
                    ++cnt;   
                    dfs(v,i,j,width,height,visited);
                                
            }
        }
    cout<<cnt;
    }
}