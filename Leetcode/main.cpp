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


void Merge(int array[], int low, int mid, int high){
    int *assist = (int *)malloc(sizeof(array));
    int i,j,k;
    for(k=low;k<=high;k++)
        assist[k] = array[k];
    for(i=low,j=mid+1,k=low;i<=mid&&j<=high;k++){
        cout<<"k="<<k<<endl;
        if(assist[i]<=assist[j])
            array[k] = assist[i++];
        else
            array[k] = assist[j++];
    }
    while(i<=mid) array[k++] = assist[i++];
    while(j<=high) array[k++] = assist[j++];
}


void MergeSort(int array[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);
        Merge(array, low, mid, high);
    }

}
int main() {
    int array[8] = {8,6,2,3,4,1,5,9};
    MergeSort(array,0, 7);
    for(int i=0;i<8;i++)
        cout<<"array["<<i<<"]= "<<array[i]<<endl;
    return 0;
}
