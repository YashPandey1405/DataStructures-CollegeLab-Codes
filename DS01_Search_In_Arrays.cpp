#include<iostream>
using namespace std;

void PrintArray(int arr[],int size);

void LinearSearch(int arr[],int size,int Key){
    for(int i=0;i<size;i++){
        if(arr[i]==Key){
            cout<<"BY Linear Search ::: KEY "<<Key<<" FOUND AT INDEX "<<i<<" IN THE ARRAY ";
            PrintArray(arr,size);
            return;
        }
    }
    cout<<"BY Linear Search ::: KEY "<<Key<<" NOT FOUND IN THE ARRAY ";
    PrintArray(arr,size);
}

void BinarySearch(int arr[],int size,int Key){
    int start=0,end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==Key){
            cout<<"BY Binary Search ::: KEY "<<Key<<" FOUND AT INDEX "<<mid<<" IN THE ARRAY ";
            PrintArray(arr,size);
            return;
        }
        if(arr[mid]>Key){  end=mid-1;  }
        else {  start=mid+1;  }
    }
    cout<<"BY Binary Search ::: KEY "<<Key<<" NOT FOUND IN THE ARRAY ";
    PrintArray(arr,size);
}

void PrintArray(int arr[],int size){
    cout<<"{ ";
    for(int i=0;i<size;i++){
        if(i==(size-1)){  cout<<arr[i]<<" }"<<endl;  }
        else {  cout<<arr[i]<<", ";  }
    }
}

int main(){
    int key;
    int arr[7]={1,2,3,4,5,6,7};
    cout<<"ENTER THE KEY YOU WANT TO SEARCH IN THE ARRAY ::: ";
    cin>>key;
    LinearSearch(arr,7,key);
    BinarySearch(arr,7,key);
    return 0;
}