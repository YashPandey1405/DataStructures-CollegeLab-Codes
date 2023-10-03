#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int CurrData){
            this->data=CurrData;
            this->next=NULL;
        }
};

class Deque_LinkedList{
    private:
        int Capacity , Size;
        Node* Head;
        Node* Tail;
    public:
        Deque_LinkedList(int c){
            Capacity=c; Size=0;
            Head=Tail=NULL;
        }
        void AddFirst(int data){
            if(Size==Capacity){
                cout<<"DEQUE IS FULL ::: INSERSTON NOT POSSIBLE"<<endl;
                return;
            }
            Node* NewNode=new Node(data);
            if(Head==NULL && Tail==NULL){
                Head=Tail=NewNode;
                Size++;
                return;
            }
            NewNode->next=Head;
            Head=NewNode;
            Size++;
        }
        void AddLast(int data){
            if(Size==Capacity){
                cout<<"DEQUE IS FULL ::: INSERSTON NOT POSSIBLE"<<endl;
                return;
            }
            Node* NewNode=new Node(data);
            if(Head==NULL && Tail==NULL){
                Head=Tail=NewNode;
                Size++;
                return;
            }
            Tail->next=NewNode;
            Tail=NewNode;
            Size++;
        }
        int RemoveFirst(){
            if(Head==NULL){
                cout<<"DEQUE IS EMPTY ::: DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* temp=Head;
            int Value=Head->data;
            Head=Head->next;
            free(temp);
            Size--;
            return Value;
        }
        int RemoveLast(){
            if(Head==NULL){
                cout<<"DEQUE IS EMPTY ::: DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* temp=Head;
            while(temp->next->next != NULL){  //Loop To Reach 2nd Last Node....
                temp=temp->next;
            }
            int Value=Tail->data;
            Node* ptr=Tail;
            Tail=temp;
            Tail->next=NULL;
            delete(ptr);
            Size--;
            return Value;
        }
        int PeekFront(){    return Head->data;  }
        int PeekLast(){    return Tail->data;  }
        bool isEmpty(){    return (Head==NULL);  }
        bool isFull(){    return (Size==Capacity);  }
        void PrintDeque(){
            cout<<"THE DEQUE IS ::: ";
            Node* temp=Head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main(){
    Deque_LinkedList dq(10);
    dq.AddFirst(3); dq.AddFirst(2); dq.AddFirst(1);
    dq.AddLast(4); dq.AddLast(5); dq.AddLast(6);
    dq.PrintDeque();
    dq.RemoveFirst();
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