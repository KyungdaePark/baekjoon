    #include<iostream>
    using namespace std;

    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
    int main(){
        int b,s;
        cin>>b>>s;
        int mul = b*s;
        //최대공약수 구하기 : 유클리드 호제법
        if(s>b) swap(b,s);
        int temp;
        while(true){
            temp = b%s;
            if(temp==0) break;
            b = s;
            s = temp;
        }
        cout<<s<<endl;
        //최소공배수 구하기 : 최대공약수 * 최소공배수 = 두수의곱
        cout<< (mul / s);
    }