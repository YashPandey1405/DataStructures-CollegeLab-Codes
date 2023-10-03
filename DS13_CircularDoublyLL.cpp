#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int CurrData){
            this->data=CurrData;
            this->prev=this->next=NULL;
        }
};

static int size_CDLL;

class CircularDLL{
    private:
        Node* Head;
        Node* Tail;
    public:
        CircularDLL(){
            this->Head=NULL;
            this->Tail=NULL;
        }

        void AddFront(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_CDLL++;
                return;
            }
            NewNode->next=Head;
            Head->prev=NewNode;
            Head=NewNode;
            Head->prev=Tail;
            Tail->next=Head;
            size_CDLL++;
        }

        void AddLast(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_CDLL++;
                return;
            }
            Tail->next=NewNode;
            NewNode->prev=Tail;
            Tail=NewNode;
            Head->prev=Tail;
            Tail->next=Head;
            size_CDLL++;
        }

        int RemoveFirst(){
            if(Head==NULL){
                cout<<"CIRCULAR DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* Temp=Head;
            int Value=Temp->data;
            Head=Head->next;
            Head->prev=Tail;
            Tail->next=Head;
            Temp->next=Temp->prev=NULL;
            free(Temp);
            size_CDLL--;
            return Value;
        }

        int RemoveLast(){
            if(Head==NULL){
                cout<<"CIRCULAR DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* Temp=Tail;
            int Value=Temp->data;
            Tail=Tail->prev;
            Tail->next=Head;
            Head->prev=Tail;
            Temp->prev=Temp->next=NULL;
            free(Temp);
            size_CDLL--;
            return Value;
        }

        Node* GetMiddle(){
            Node* Slow=Head->next;
            Node* Fast=Head->next->next;
            while(Fast!=Tail && Fast->next!=Tail){
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
            return Slow;
        }

        void AddMiddle(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_CDLL++;
                return;
            }
            Node* Slow=GetMiddle();
            NewNode->next=Slow->next;
            Slow->next->prev=NewNode;
            Slow->next=NewNode;
            NewNode->prev=Slow;
            size_CDLL++;
        }

        int RemoveMiddle(){
            if(Head==NULL){
                cout<<"DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* MidNode=GetMiddle();
            int Value=MidNode->data;
            Node* Prev=MidNode->prev;
            Prev->next=MidNode->next;
            MidNode->prev=NULL;
            MidNode->next->prev=Prev;
            MidNode->next=NULL;
            free(MidNode);
            size_CDLL--;
            return Value;
        }

        void PrintCDLL(){
            Node* Temp=Head;
            cout<<"THE Circular Doubly-LinkedList IS ::: ";
            while(Temp != Tail){
                cout<<Temp->data<<" <--> ";
                Temp=Temp->next;
            }
            cout<<Temp->data<<endl;
        }

        void PrintReverse_CDLL(){
            Node* Temp=Tail;
            cout<<"THE REVERSED Circular Doubly-LinkedList IS ::: ";
            while(Temp != Head){
                cout<<Temp->data<<" <--> ";
                Temp=Temp->prev;
            }
            cout<<Temp->data<<endl;
        }
};

int main(){
        CircularDLL cdll;

        // cdll.AddFront(3);
        // cdll.AddFront(2);
        // cdll.AddFront(1);
        // cdll.AddLast(5);
        // cdll.AddLast(6);
        // cdll.AddLast(7);
        // cdll.PrintCDLL();
        // cout<<"THE SIZE OF Circular Doubly-LinkedList IS ::: "<<size_CDLL<<endl;


        // Node* temp=cdll.GetMiddle();
        // cout<<"MIDDLE NODE OF Circular Doubly-LinkedList IS ::: "<<temp->data<<endl;

        // cdll.AddMiddle(4);
        // cdll.PrintCDLL();
        // cout<<"THE SIZE OF Circular Doubly-LinkedList IS ::: "<<size_CDLL<<endl;

        // cdll.RemoveFirst();
        // cdll.PrintCDLL();
        // cout<<"THE SIZE OF Circular Doubly-LinkedList IS ::: "<<size_CDLL<<endl;

        // cdll.RemoveLast();
        // cdll.PrintCDLL();
        // cout<<"THE SIZE OF Circular Doubly-LinkedList IS ::: "<<size_CDLL<<endl;

        // cdll.RemoveMiddle();
        // cdll.PrintCDLL();
        // cout<<"THE SIZE OF Circular Doubly-LinkedList IS ::: "<<size_CDLL<<endl;

        // cdll.PrintCDLL();
        // cdll.PrintReverse_CDLL();
    return 0;
}