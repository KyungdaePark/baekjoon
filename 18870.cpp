#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct x{
    int num;
    int input_order;
    int sort_order;

    x(int a, int b, int c) :num(a), input_order(b), sort_order(c) {};
};

bool comp_sort(x a, x b){
    return a.num < b.num;
}

bool comp_input(x a, x b){
    return a.input_order < b.input_order;
}
int main(){
    int N;
    cin>>N;
    vector<x> v;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(x(tmp, i, 0));
    }
    
    sort(v.begin(), v.end(), comp_sort);
    
    for(int i=1;i<N;i++){
        if(v[i].num > v[i-1].num){
            v[i].sort_order = v[i-1].sort_order +1;
        } else if(v[i].num == v[i-1].num){
            v[i].sort_order = v[i-1].sort_order;
        }
    }
    
    sort(v.begin(), v.end(), comp_input);

    for(int i=0;i<N;i++){
        //cout<<v[i].num<<" "<<v[i].input_order<<" "<<v[i].sort_order<<"\n";
        cout<<v[i].sort_order<<" ";
    }


}