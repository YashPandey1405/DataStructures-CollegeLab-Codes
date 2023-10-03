#include<iostream>
using namespace std;

class Deque_Arrays{
    private:
        int* arr;
        int Capacity;
        int Front,Rear;
    public:
        Deque_Arrays(int c){
            Capacity=c;
            arr=new int[Capacity];
            Front=(0); Rear=(-1);
        }
        void AddFirst(int data){
            if(Front==(-1)){
                cout<<"FRONT OF QUEUE IS FULL ::: INSERSTON AT START NOT POSSIBLE"<<endl;
                return;
            }
            arr[--Front]=data;
        }
        void AddLast(int data){
            if(Rear==Capacity){
                cout<<"REAR OF QUEUE IS FULL ::: INSERSTON AT END NOT POSSIBLE"<<endl;
                return;
            }
            arr[++Rear]=data;
        }
        int RemoveFront(){
            if(Rear==(-1)){
                cout<<"REAR OF QUEUE IS EMPTY ::: DELETION AT START NOT POSSIBLE"<<endl;
                return (-1);
            }
            int Temp=arr[Front++];
            return Temp;
        }
        int RemoveLast(){
            if(Front==(-1)){
                cout<<"FRONT OF QUEUE IS EMPTY ::: DELETION AT END NOT POSSIBLE"<<endl;
                return (-1);
            }
            int Temp=arr[Rear--];
            return Temp;
        }
        int PeekFront(){    return arr[Front];  }
        int PeekLast(){    return arr[Rear];  }
        bool isEmpty(){    return (Front==(-1) && Rear==(-1));  }
        bool isFull(){    return (Front==(-1) && Rear==Capacity);  }
        void PrintDeque(){
            cout<<"THE DEQUE IS ::: ";
            for(int i=Front;i<=Rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Deque_Arrays dq(10);
    dq.AddLast(1); dq.AddLast(2); dq.AddLast(3);
    dq.AddLast(4); dq.AddLast(5); dq.AddLast(6);
    dq.PrintDeque();
    dq.RemoveFront(); dq.RemoveFront(); dq.RemoveFront();
    dq.PrintDeque();
    dq.AddFirst(3); dq.AddFirst(2); dq.AddFirst(1);
    dq.PrintDeque();
    dq.RemoveLast();
    dq.PrintDeque();
    cout<<endl;
    cout<<"THE FRONT OF DEQUE IS ::: "<<dq.PeekFront()<<endl;
    cout<<"THE REAR OF DEQUE IS ::: "<<dq.PeekLast()<<endl;
    cout<<"THE DEQUE IS EMPTY ::: "<<dq.isEmpty()<<endl;
    cout<<"THE DEQUE IS FULL ::: "<<dq.isFull()<<endl;
    return 0;
}