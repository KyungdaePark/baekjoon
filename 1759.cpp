#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> v;
bool visited[16];
int pick[16];
vector<int> vowel;
int L,C; //L : 뽑는갯수 C : 전체갯수


bool check(){
    int cons = 0;
    int vowels = 0;
    bool isvowel = false;
    for(int i=0;i<L;i++){
        for(int j=0;j<5;j++){
            if(v[pick[i]] == vowel[j]){
                vowels++;
                isvowel = true;
                break;
            }
        }
    }
    cons = L - vowels;
    if(cons>1 && vowels>0){
        return true;
    }
    else return false;
}
void dfs(int index, int depth){
    if(depth==L){
        // if(check(pick)){
        //     for(int i=0;i<L;i++){
        //         cout<<pick[i];
        //     }
        //     cout<<"\n";
        // }
        if(check()){
            for(int i=0;i<L;i++){
                cout<<v[pick[i]];
            }
            cout<<"\n";
        }
        return;
    }
    for(int i=index;i<C;i++){
        if(!visited[i]){
            visited[i] = true;
            pick[depth] = i;
            dfs(i+1,depth+1);
            visited[i] = false;   
        }
    }

}
int main(){
    cin>>L>>C;
    for(int i=0;i<C;i++){
        char tmp; cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    vowel.push_back('a');
    vowel.push_back('e');
    vowel.push_back('i');
    vowel.push_back('o');
    vowel.push_back('u');
    dfs(0,0);
}