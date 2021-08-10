#include <iostream>
using namespace std;

int partition(int array[], int low ,int high){
    int pivot = array[low];
    while(low<high){
        while(array[high]>=pivot&&low<high) --high;
        array[low] = array[high];
        while(array[low]<pivot&&low<high) ++low;
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;

}

void quickSort(int array[], int low ,int high){

    if(low < high){
        int pivotpos = partition(array, low, high);
        quickSort(array, low, pivotpos-1);
        quickSort(array, pivotpos+1, high);
    }
}

int main() {
    int array[5] = {2,3,4,1,5};
    quickSort(array,0,4);
    for(int i=0;i<5;i++)
        cout<<"array["<<i<<"]= "<<array[i]<<endl;
    return 0;
}
