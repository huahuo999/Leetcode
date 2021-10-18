#include <iostream>
using namespace std;
typedef struct LinkNode{
    int data;
    LinkNode* next;
}LinkNode, *LinkList;


void create(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = nullptr;
    for(int i=1; i<=n;i++){
        LinkNode* current;
        current = (LinkNode*)malloc(sizeof(LinkNode));
        int number;
        cout<<"input a number"<<endl;
        cin>>number;
        current->data = number;
        current->next = L->next;
        L->next = current;
    }
    cout<<"-----------create end-------------------"<<endl;
}

void traverse(LinkList L){
    L = L->next;
    while (L!=nullptr){
        cout<<L->data;
        if (L->next!= nullptr)
            cout<<"->";
        L = L->next;
    }
    cout<<endl;
    cout<<"-----------traverse end-------------------"<<endl;
}

void insert(LinkList L, int i, int x){
    int step=0;
    while(step!=i-1){
        step++;
        L = L->next;
    }

    LinkNode *newNode;
    newNode = (LinkNode*)malloc(sizeof(LinkNode));
    newNode->data = x;
    newNode->next = L->next;
    L->next = newNode;
    cout<<"-----------insert end-------------------"<<endl;

}

int length(LinkList L){
    int depth = 0;
    L = L->next;
    while(L!= nullptr){
        depth++;
        L = L->next;
    }
    return depth;
}

bool empty(LinkList L){
    return L->next;
}

int visit(LinkList L, int i){
    L = L->next;
    int step=1;
    while(step!=i){
        step++;
        L = L->next;
    }
    return L->data;
}

int search(LinkList L, int x){
    L = L->next;
    int pos=1;
    while(L->data != x){
        L = L->next;
        pos++;
    }
    cout<<"-----------search end-------------------"<<endl;
    return pos;

}

void eraseXY(LinkList &L, int x, int y){
    LinkNode * temp  = L->next;
    while(temp->next!= nullptr){
        if(temp->next->data >=x&&temp->next->data<=y){
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    cout<<"-----------eraseXY end-------------------"<<endl;
}

void reverse(LinkList &L){
    L = L->next;
    LinkList L1;
    L1 = (LinkList)malloc(sizeof(LinkList));
    L1->next = nullptr;
    while(L!= nullptr){
        LinkNode* nextNode;
        nextNode = L->next;
        LinkNode* current;
        current = (LinkNode*)malloc(sizeof(LinkNode));
        current->data = L->data;
        current->next = L1->next;
        L1->next = current;
        L = nextNode;
    }
    L = L1;
    cout<<"-----------reverse end-------------------"<<endl;
}

void copy(LinkList &L){
    LinkNode* temp = L->next;
    while(temp!= nullptr)
    {
        LinkNode* current;
        current = (LinkNode*)malloc(sizeof(LinkNode));
        current->data = temp->data;
        current->next = temp->next;
        temp->next = current;
        temp = current->next;
    }
}
int main() {
    LinkList L;
    int n;
    cout<<"input node length"<<endl;
    cin>>n;
    create(L, n);
    traverse(L);
    copy(L);
    traverse(L);
    return 0;
}
