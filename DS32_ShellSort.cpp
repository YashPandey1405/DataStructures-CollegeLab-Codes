#include <iostream> 
using namespace std; 

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

int ShellSort(int arr[], int n) { 
	for (int gap = n/2; gap > 0; gap /= 2) { 
		for (int i = gap; i < n; i += 1) { 
			int temp = arr[i]; 
			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap]; 
            }
			arr[j] = temp; 
		} 
	} 
    cout<<"After Shell Sort(In Ascending Order) --> ";
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
	int arr[6] = {12,34,54,46,33,29}; 
	PrintArray(arr,6);
    ShellSort(arr,6);
	return 0; 
} 
