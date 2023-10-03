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

class Stacks_LinkedList{
    private:
        Node* head;
        int size;
        int Capacity;
    public:
        Stacks_LinkedList(int c){
            this->Capacity=c;
            this->size=0;
            this->head=NULL;
        }
        void push(int data){
            if(this->size==this->Capacity){
                cout<<"OVERFLOW CONDITION ::: STACK IS FULL";
                return;
            }
            Node* NewNode=new Node(data);
            NewNode->next=this->head;
            this->head=NewNode;
            this->size++;
        }
        int pop(){
            if(this->head==NULL){
                cout<<"UNDERFLOW CONDITION ::: STACK IS EMPTY";
                return -1;
            }
            Node* temp=this->head;
            int Value=temp->data;
            this->head=this->head->next;
            temp->next=NULL;
            this->size--;
            free(temp);
            return Value;
        }
        int peek(){
            if(this->head==NULL){
                cout<<"UNDERFLOW CONDITION ::: STACK IS EMPTY";
                return -1;
            }
            return this->head->data;
        }
        void PrintStack(){
            cout<<"THE STACK IS ::: TOP--> ";
            Node* temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        }
        int Size(){  return this->size;  }
        bool isEmpty(){  return this->head==NULL;  }
        bool isFull(){  return this->size==this->Capacity;  }
};

int main(){
    Stacks_LinkedList sll(10);
    sll.push(1);
    sll.push(5);
    sll.push(3);
    sll.push(4);
    sll.push(2);
    sll.push(6);
    sll.PrintStack();
    sll.pop();
    sll.PrintStack();
    cout<<"TOP OF STACK IS ::: "<<sll.peek()<<endl;
    cout<<"STACK IS EMPTY ::: "<<sll.isEmpty()<<endl;
    cout<<"STACK IS FULL ::: "<<sll.isFull()<<endl;
    cout<<"SIZE OF STACK IS ::: "<<sll.Size()<<endl;
    cout<<endl;
    return 0;
}