/*
-> Heap sort is a comparison-based sorting algorithm which can be thought of as 
    an implementation of selection sort using the right data structure.......
-> For Ascending Order Sorting , We Create MaxHeap In The Array.....
-> For Descending Order Sorting , We Create MinHeap In The Array.....
-> Merge Sort & Quick Sort Are Used More Frequently Than Heap Sort.....
-> Time Complexity Of Heap Sort is O(nLogn)......
*/

#include<iostream>
using namespace std;

void Heapify_DescendOrder(int*,int,int); // Forward Declaration Of Function Heapify_DescendOrder()........

void HeapSort_DescendOrder(int arr[],int Size) { // O(nLogn).......
    int n = Size;

    // Step 1 ::: Build MinHeap.....
    for (int i = (n / 2); i >= 0; i--) {
        Heapify_DescendOrder(arr, i, n);
    }

    // Step 2 ::: Push Smallest At End.....
    for (int i = (n - 1); i > 0; i--) {
        // Swap --> (First<-->Last).....
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify_DescendOrder(arr, 0, i);
    }
}

void Heapify_DescendOrder(int arr[], int i, int size) { // O(Logn)........
    int Left = (2 * i) + 1;
    int Right = (2 * i) + 2;
    int MinIDX = i;

    // When The Left Child Is Valid & Parent Value > Left Child Value......
    if (Left < size && arr[Left] < arr[MinIDX]) {
        MinIDX = Left;
    }
    
    // When The Right Child Is Valid & Parent Value > Right Child Value......
    if (Right < size && arr[Right] < arr[MinIDX]) {
        MinIDX = Right;
    }
    if (MinIDX != i) {
        int temp = arr[i];
        arr[i] = arr[MinIDX];
        arr[MinIDX] = temp;

        Heapify_DescendOrder(arr, MinIDX, size);
    }
}

void PrintArray(int arr[],int n){ //Function To Print Array...
    // int n=sizeof(arr)/sizeof(int);
    cout<<"THE SORTED ARRAY IS ::: { ";
    for(int i=0;i<n;i++){
        if(i==(n-1)){
            cout<<arr[i]<<" }"<<endl;
        }
        else{
            cout<<arr[i]<<", ";
        }
    }
    cout<<endl;
}

int main(){
    int arr[8]={3,2,6,1,5,7,8,4};
    PrintArray(arr,8);
    HeapSort_DescendOrder(arr,8);
    cout<<"After Heap Sort In Descending Order , ";
    PrintArray(arr,8);
    return 0;
}