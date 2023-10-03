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

static int size_LL;

class LinkedList{
    private:
        Node* Head;
        Node* Tail;
    public:
        LinkedList(){
            this->Head=NULL;
            this->Tail=NULL;
        }
        void AddStart(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }
            NewNode->next=Head;
            Head=NewNode;
            size_LL++;
        }

        void AddLast(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }
            Tail->next=NewNode;
            Tail=NewNode;
            size_LL++;
        }

        Node* GetMiddle(){
            Node* Slow=Head;
            Node* Fast=Head->next;
            while(Fast!=NULL && Fast->next!=NULL){
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
            return Slow;
        }

        void AddMiddle(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }

            Node* Slow=GetMiddle();
            NewNode->next=Slow->next;
            Slow->next=NewNode;
            size_LL++;
        }

        int RemoveMiddle(){
            if(Head==NULL){
                cout<<"LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* MidNode=GetMiddle();
            Node* Prev=Head;
            while(Prev->next!=MidNode){
                Prev=Prev->next;
            }
            int Value=MidNode->data;
            Prev->next=MidNode->next;
            MidNode->next=NULL;
            free(MidNode);
            size_LL--;
            return Value;
        }

        void Insert_AnyWhere(int data,int idx){
            if(idx==0){
                AddStart(data);
                return;
            }
            Node* NewNode=new Node(data);
            Node* temp=Head;
            int CurrPos=0;
            while(CurrPos!=(idx-1)){
                temp=temp->next;
                CurrPos++;
            } 
            NewNode->next=temp->next;
            temp->next=NewNode;
            size_LL++;
        }

        void Update_Node(int data,int idx){
            if(idx==0){
                Head->data=data;
                return;
            }
            Node*temp=Head;
            int CurrPos=0;
            while(CurrPos!=(idx)){
                temp=temp->next;
                CurrPos++;
            }
            temp->data=data;
        }

        int DeleteStart(){
            if(Head==NULL){
                cout<<"LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return(-1);
            }
            Node*temp=Head;
            int Value=temp->data;
            Head=Head->next;
            temp->next=NULL;
            free(temp);
            size_LL--;
            return Value;
        }

        int Delete_Anywhere(int idx){
            if(idx==0){
                int Value=DeleteStart();
                return Value;
            }
            Node* temp=Head;
            Node* ptr=NULL;
            int CurrPos=0;
            while(CurrPos!=(idx-2)){
                temp=temp->next;
                CurrPos++;
            } 
            ptr=temp->next;
            int Value=ptr->data;
            temp->next=ptr->next;
            free(ptr);
            size_LL--;
            return Value;
        }

        int Delete_End(){
            if(Head==NULL){
                cout<<"LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return(-1);
            }
            Node*temp=Head;
            Node*ptr=NULL;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            ptr=temp->next;
            int Value=ptr->data;
            ptr->next=NULL;
            free(ptr);
            size_LL--;
            return Value;
        }

        void Reverse_LL(){
            Node* prev=NULL;
            Node* temp=Head;
            Node* ahead=NULL;
            while(temp!=NULL){
                ahead=temp->next;
                temp->next=prev;
                prev=temp;
                temp=ahead;
            }
            Head=prev;
        }

        void printLL(){
            cout<<"THE LINKED LIST IS ::: ";
            Node*temp=Head;
            while(temp!=NULL){
                cout<<temp->data<<" --> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};  

int main(){
    LinkedList ll;
    // ll.AddStart(2);
    // ll.AddStart(1);
    // ll.AddLast(5);
    // ll.AddLast(6);
    // ll.AddMiddle(3);
    // ll.AddMiddle(4);
    // ll.printLL();

    // // ll.Insert_AnyWhere(3,2);
    // // ll.Insert_AnyWhere(4,3);
    // // ll.printLL();

    // Node* temp=ll.GetMiddle();
    // cout<<"MIDDLE NODE OF LinkedList IS ::: "<<temp->data<<endl;

    // ll.Update_Node(4,3);
    // ll.printLL();

    // ll.DeleteStart();
    // ll.printLL();
    // ll.Delete_End();
    // ll.printLL();
    // ll.RemoveMiddle();
    // ll.printLL();

    // // ll.Delete_Anywhere(2);
    // // ll.printLL();

    // cout<<"SIZE OF LINKED LIST IS ::: "<<size_LL<<endl;
    // ll.Reverse_LL();
    // ll.printLL();
    return 0;
}