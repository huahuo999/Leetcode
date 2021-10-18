#include <iostream>
using namespace std;


typedef struct disjointSet{
    int* set;
    int length;
    void create(int Length){
        set = (int*) malloc(Length*sizeof(int));
        for(int i=0;i<Length;i++){
            set[i] = -1;
        }
        length = Length;
    }

    void initByMatrix(int undirectedGraph[5][5]){
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=4;j++){
                if(undirectedGraph[i][j]!=0){
                    Union(i, j);
                }
            }
        }
    }

    int find(int node){
        int target = node;
        while (set[node]>=0){
            node = set[node];
        }
        while (set[target]>=0){
            int parent = set[target];
            set[target] = node;
            target = parent;
        }
        return node;
    }

    void Union(int node1, int node2){
        if(node1 == node2) return;
        set[node2] = node1;

    }

    int ComponentCount(int undirectedGraph[5][5]){
        initByMatrix(undirectedGraph);
        int count = 0;
        for(int i=0; i<=4;i++){
            if(set[i]<0)
                count++;
        }
        return count;
    }

    bool findCircle(int undirectedGraph[5][5]){
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=4;j++){
                if(undirectedGraph[i][j]!=0){
                    if(find(i)==find(j))
                        return true;
                    Union(i, j);
                }
            }
        }
        return false;
    }


    void display(){
        for(int i=0;i<length;i++){
            cout<<"set["<<i<<"]="<<set[i]<<endl;
        }
    }
}disjointSet;
int main() {
    disjointSet ufs;
    int undirectedGraph[5][5],i, j;
    for(i=0; i<=4;i++){
        for(j=0;j<=4;j++){
            int input;
            cin>>input;
            undirectedGraph[i][j] = input;
            cout<<"  ";
        }
        cout<<endl;
    }
    ufs.create(5);
    ufs.initByMatrix(undirectedGraph);
    ufs.display();
    ufs.find(2);
    ufs.find(4);
    ufs.display();
    cout<<ufs.findCircle(undirectedGraph);
//    cout<<ufs.ComponentCount(undirectedGraph);
    return 0;
}
