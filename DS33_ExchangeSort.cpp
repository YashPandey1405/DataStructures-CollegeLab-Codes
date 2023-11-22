#include <iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

void ExchangeSort(int arr[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"After Exchange Sort(In Ascending Order) --> ";
    PrintArray(arr,n);
}

void PrintArray(int arr[],int n){ //Function To Print Array...
    // int n=sizeof(arr)/sizeof(int);
    cout<<"THE ARRAY IS ::: { ";
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

int main() {
    int arr[9] = {5,2,8,3,1,9,4,7,6};
    PrintArray(arr,9);
    ExchangeSort(arr, 9);
    return 0;
}