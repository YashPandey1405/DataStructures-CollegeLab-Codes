// In Counting Sort , We Create A Frequency Array Where We Store The Frequency Of Each Element.... 
// In Each Iteration , We Print The Number wrt Frequency Of The Element......
// Average Case Time Complexity Of Counting Sort Is O(n+k) , Where , n = No Of Elements In Array..... 
//                                                                   k = Range Of Elements In Array..... 
// Best Case Time Complexity Of Counting Sort Is O(n)...... 
 
#include<iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

//Function To Perform Counting Sort In Ascending Order.......
void CountingSort_AscendingOrder(int arr[],int n){  //O(n+k)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    int Largest=(-1);
    for(int i = 0 ; i < n ; i++){  //Loop To Get Largest Element In The Array....
        Largest = (arr[i]>Largest) ? arr[i] : Largest;
    }

    int FreqCount[Largest+1]={0};  //Initialized Each Index By Value-0.....

    for(int i = 0 ; i < n ; i++){  //Loop To Get Frequency Of Each Element Of The Array....
        if(FreqCount[arr[i]] == 0){    FreqCount[arr[i]]=1;    }
        else{   FreqCount[arr[i]]++;    }
    }

    int idx=0;
    for(int i = 0 ; i < (Largest+1) ; i++){  //Loop For Sorting In Ascending Order.....
        while(FreqCount[i]>0){
            arr[idx]=i;
            idx++;
            FreqCount[i]--;
        }
    }
    cout<<"After Counting Sort In Ascending Order --> ";
    PrintArray(arr,n);
}

//Change The Sign From '>' --> '<' In (1) To Get Sorting In Descending Order, Rest Code Will Be Same.....
//Function To Perform Counting Sort In Descending Order.......
void CountingSort_DescendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    int Largest=(-1);
    for(int i = 0 ; i < n ; i++){  //Loop To Get Largest Element In The Array....
        Largest = (arr[i]>Largest) ? arr[i] : Largest;
    }

    int FreqCount[Largest+1]={0};  //Initialized Each Index By Value-0.....

    for(int i = 0 ; i < n ; i++){  //Loop To Get Frequency Of Each Element Of The Array....
        if(FreqCount[arr[i]] == 0){    FreqCount[arr[i]]=1;    }
        else{   FreqCount[arr[i]]++;    }
    }

    int idx=0;
    for(int i = Largest ; i >=0 ; i--){  //Loop For Sorting In Descending Order.....
        while(FreqCount[i]>0){
            arr[idx]=i;
            idx++;
            FreqCount[i]--;
        }
    }
    cout<<"After Counting Sort In Descending Order --> ";
    PrintArray(arr,n);
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
    CountingSort_AscendingOrder(arr,8);
    CountingSort_DescendingOrder(arr,8);
    return 0;
}