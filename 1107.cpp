#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int result = 0;
int ch, bu;
//bool visited[500001];
vector<int> ban;

bool isBan(int num){
    int digitnum = to_string(num).length();
    vector<int> v;
    for(int i=0;i<digitnum;i++){
       int up = pow(10,digitnum-1-i);
       up = num/up;
       up = up % 10;
       v.push_back(up);
    }

    // for(int i=0;i<v.size();i++){
    //     cout<<"v is : "<<v[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<ban.size();j++){
            if(v[i] == ban[j]) return true;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>ch>>bu;
    for(int i=0;i<bu;i++){
        int temp; cin>>temp;
        ban.push_back(temp);
    }
    //#1 find abs(N-100)
    result = abs(ch-100);
    if(ban.size() == 10 ){
        cout<<result;
        return 0;
    }
    int temp = ch;
    while(isBan(temp)){
        if(temp==1000001) break;
        temp+=1;
    }
    // cout<<"temp up" <<temp<<endl;
    int digitnum = to_string(temp).length();
    result = min (result, digitnum+abs(ch-temp));
    
    temp = ch;
    while(isBan(temp)){
        if(temp==-1) break;
        temp-=1;   
    }
    // cout<<"temp down" <<temp<<endl;
    digitnum = to_string(temp).length();
    if(temp!=-1) result = min (result, digitnum+abs(ch-temp));
    
    cout<<result;  
}