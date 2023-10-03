#include<iostream>
using namespace std;

class Stacks_Arrays{
    private:
        int Capacity;
        int *arr;
        int Top=0;
    public:
        Stacks_Arrays(int c){
            this->Capacity=c;
            arr=new int[c];
            this->Top=-1;
        }
        void push(int data){
            if(this->Top == this->Capacity-1){
                cout<<"OverFlow Condition ::: Stack Is Full"<<endl;
                return;
            }
            this->Top++;
            this->arr[this->Top]=data;
        }
        int pop(){
            if(Top==(-1)){
                cout<<"UnderFlow Condition ::: Stack Is Empty"<<endl;
                return INT8_MIN;
            }
            int temp=this->arr[this->Top];
            this->Top--;
            return temp;
        }
        int peek(){
            if(Top==(-1)){
                cout<<"UnderFlow Condition ::: Stack Is Empty"<<endl;
                return INT8_MIN;
            }
            return this->arr[this->Top];
        }
        void SortStack(){
            int n=this->Top+1;
            for(int i=0;i<(n-1);i++){  //Selection Sort
                for(int j=(i+1);j<n;j++){
                    if(this->arr[j]<this->arr[i]){  
                        int temp=this->arr[i];
                        this->arr[i]=this->arr[j];
                        this->arr[j]=temp;                   
                    }
                }
            }
            cout<<"After SortQueue() Function , ";
        }
        void ReverseStack(){
            int n=this->Top+1;
            for(int i=0;i<(n/2);i++){  //Reverse A Queue....
                        int temp=this->arr[i];
                        this->arr[i]=this->arr[n-i-1];
                        this->arr[n-i-1]=temp;                   
            }
            cout<<"After ReverseQueue() Function , ";
        }
        void PrintStack(){
            cout<<"Stack Is ::: TOP-->";
            for(int i=this->Top;i>=0;i--){
                cout<<this->arr[i]<<" ";
            }
            cout<<endl;
        }
        int size(){      return (this->Top+1);   }
        bool isEmpty(){    return this->Top==(-1);     }
        bool isFull(){       return this->Top == (this->Capacity-1);     }

};

int main(){
        Stacks_Arrays s(5);
        cout<<endl;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.PrintStack();
        s.pop();
        s.PrintStack();
        cout<<endl;
        cout<<"TOP OF STACK IS ::: "<<s.peek()<<endl;
        cout<<"STACK IS EMPTY ::: "<<s.isEmpty()<<endl;
        cout<<"STACK IS FULL ::: "<<s.isFull()<<endl;
        cout<<"SIZE OF STACK IS ::: "<<s.size()<<endl;
        cout<<endl;
        s.SortStack();
        s.PrintStack();
        s.ReverseStack();
        s.PrintStack();
        cout<<endl;
    return 0;
}