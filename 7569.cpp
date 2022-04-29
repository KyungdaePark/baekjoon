#include<iostream>
using namespace std;

int box[101][101][101];
int dz[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,0,0,1,-1};
int dx[6] = {0,0,-1,1,0,0};

int cnt = 0;
int M,N,H;
void bfs(){
    bool ichanged = false;
    for(int z=0;z<H;z++){
        for(int y=0;y<N;y++){
            for(int x=0;x<M;x++){
                if(box[z][y][x]==1){
                    for(int i=0;i<6;i++){
                        int nz = z + dz[i];
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(nz>=0 && ny>=0 && nx>=0 && nz==0 && ny==0 && nx==0){
                            box[nz][ny][nx]=1;
                            ichanged = true;
                        }
                    }         
                }
            }
        }
    }

    if(ichanged){
        cnt++;
        bfs();
    }
    else{
        for(int z=0;z<H;z++){
            for(int y=0;y<N;y++){
                for(int x=0;x<M;x++){
                    if(box[z][y][x]==0){
                        cout<<-1;
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    cin>>M>>N>>H;
    for(int z=0;z<H;z++){
        for(int y=0;y<N;y++){
            for(int x=0;x<M;x++){
                cin>>box[z][y][x];
            }
        }
    }

    bfs();
    cout<<cnt;
}