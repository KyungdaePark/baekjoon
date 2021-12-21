#include <iostream>
using namespace std;

typedef int Elem;

class QuickSort {
//수정1 private이랑 public 위치 바꿨어 Vector를 인식 못하길래
private:
    int nElem;
    class Vector {
    public:
        Vector() :capacity(0), n(0), A(NULL) {}
        int size()const { return n; }
        bool empty()const { return size() == 0; }
        Elem& operator[](int i) { return A[i]; }
        Elem& at(int i) {
            return A[i];
        }
        void erase(int i) {
            for (int j = i + 1; j < n; j++)
                A[j - 1] = A[j];
            n--;
        }
        void insert(int i, const Elem& e) {
            if (n >= capacity)
                reserve(max(1, 2 * capacity));
            for (int j = n - 1; j >= i; j--)
                A[j + 1] = A[j];
            A[i] = e;
            n++;
        }
        void reserve(int N) {
            if (capacity >= N)return;
            Elem* B = new Elem[N];
            for (int j = 0; j < n; j++)
                B[j] = A[j];
            if (A != NULL)delete[]A;
            A = B;
            capacity = N;
        }
        void printAll() {
            for (int i = 0; i < n; i++) {
                cout << A[i] << endl;
            }
        }
    private:
        int capacity;
        int n;
        Elem* A;
    };
public:
//2. 여기서부터 그 매개변수로 vector&로 주는걸 Vector&로 바꿨어 여기서부터 메인함수 까지
    Vector vector;
    void set_vector(Elem i) {
        vector.at(i);
    }
    void Swap(int, int, Vector&);
    void qsort(Vector&,int start,int end);
    int partition(Vector&S,int start,int end);
    void display(Vector&S); //3. display 매개변수 S 넣어주기
   
};

void QuickSort::Swap(int start, int end, Vector& S) {
    if (S[start] != S[end]) {
        int temp = S[start];
        S[start] = S[end];
        S[end] = temp;
    }
}

void QuickSort::qsort(Vector&S,Elem start,Elem end) {
    if (start < end) {
        int pivotIndex = partition(S, start, end);
        display(S); //4. display에 S배열 넣어줬어
        qsort(S, start, pivotIndex - 1);
        qsort(S, pivotIndex + 1, end);
    }
}

int QuickSort::partition(Vector&S,int start,int end) {
    int pivot = start++;
    while (start < end) {
        while (S[start] < S[pivot]) {
            start++;
        }
        while (S[end] > S[pivot]) {
            end--;
        }
        if (start < end) {
            Swap(start, end, S);
        }
    }
}
//3. display에 매개변수 넣어줬어
void QuickSort::display(Vector&S) {
    for (int i = 0; i < S.size(); i++) {
        cout << S[i] <<" "; //5. 출력할 때 한칸 띄어서 할려고 ""를 " "로 바꿨어
    }
}

int main() {

/*
    QuickSort q;
    q.vector.insert(0,0); //0번째 칸에 0 넣기
    q.vector.insert(1,2); //1번째 칸에 2 넣기
    q.display(q.vector);
    return 0;

*/
    //과제대로 해보면,,
    QuickSort q;
    cout<<"How many elements do you want to sort?: ";
    int count; cin>>count;
    cout<<"\nEnter "<<count<<" elements to sort: ";
    for(int i=0;i<count;i++){
        int tmp; cin>>tmp;
        q.vector.insert(i,tmp);
    }
    cout<<"\nStart sorting\n";
    q.display(q.vector);
    //이 아래는 quick sorting 대루...
    q.qsort(q.vector,0,count-1);


}