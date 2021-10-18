#include <iostream>
using namespace std;

typedef struct SeqList{
    char* array;
    int length;
    int currentLength;
}SeqList;

void create(SeqList &L, int n){
 L.array = (char*)malloc(n*sizeof(char));
 L.length = n;
}

void insert(SeqList &L, int i, char x){
    for(int j=L.length-1;j>=i;j--){
        L.array[j] = L.array[j-1];
    }
    L.array[i] = x;
    L.currentLength +=1;
    cout<<"-----------------------insert end-----------------------"<<endl;
}

void traverse(SeqList L){
    for(int i=0;i<=L.length-1;i++){
        cout<<"L.array["<<i<<"]="<<L.array[i]<<endl;
    }
    cout<<"-----------------------traverse end-----------------------"<<endl;
}

int length(SeqList L){
    return L.length;
}

bool empty(SeqList L){
    if(L.currentLength==0)
        return true;
    return false;
}

char visit(SeqList L, int i){
    return L.array[i];
}

int search(SeqList L, char x){
    for(int i=0;i<=L.length-1;i++){
        if(L.array[i]==x){
            return i;
        }
    }
}

void remove(SeqList &L, int i){
    for(int j=i;j<=L.length-2;j++){
        L.array[j] = L.array[j+1];
    }
    L.currentLength -=1 ;
}
//eraseXY(x, y): 删除顺序表中元素值在x到y（假设x≤y）之间的所有元素；
void eraseXY(SeqList &L, char x, char y){
    int deleteNumber = 0;
    for(int i=0;i<=L.length-1;i++){
        if(L.array[i-deleteNumber]>=x&&L.array[i-deleteNumber]<=y){
            cout<<"delete"<<L.array[i-deleteNumber]<<endl;
            remove(L, i-deleteNumber);
            deleteNumber += 1;
            traverse(L);
        }
    }
    L.currentLength -=deleteNumber;
}

void reverse(SeqList &L){
    for(int i=0;i<L.length/2;i++){
//        swap(L.array[i], L.array[L.length-i-1]);
        char temp = L.array[i];
        L.array[i] = L.array[L.length-1-i];
        L.array[L.length-1-i] = temp;
    }
}

int main() {
    SeqList seqList;
    int n;
    cout<<"input array length"<<endl;
    cin>>n;
    create(seqList, n);
    for(int i=0;i<=n-1;i++){
        char input;
        cout<<"input a char"<<endl;
        cin>>input;
        insert(seqList, i, input);
    }
    traverse(seqList);
    reverse(seqList);
    traverse(seqList);
//    eraseXY(seqList, 'x', 'y');
//    cout<<search(seqList, 'x');
//    cout<<"visit is "<<visit(seqList, 2);

    return 0;
}
