//Inorder Traversal Of Binary Tree Is Always In A Sorted Sequence.....
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* Left;
        Node* Right;
        Node(int CurrData){
            this->data=CurrData;
            this->Left=this->Right=NULL;
        }
};

//Function To Form BST Using A Given Array.....
Node* Build_BST(Node* Root , int Value){
    if(Root==NULL){
        Root=new Node(Value);
        return Root;
    }
    else if(Root->data>Value){
        Root->Left=Build_BST(Root->Left,Value);
    }
    else if(Root->data<Value){
        Root->Right=Build_BST(Root->Right,Value);
    }
    return Root;
}

//Function To Get Inorder Traversal Of The Binary Tree.....
void InOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    InOrder_Traversal(Root->Left);
    cout<<Root->data<<" ";
    InOrder_Traversal(Root->Right);
}

int main(){
    int arr[6]={5,1,3,4,2,7};
    Node* Root=NULL;
    for(int i=0;i<6;i++){
        Root=Build_BST(Root,arr[i]);
    }

    cout<<"THE IN-ORDER TRAVERSAL IS ::: ";
    InOrder_Traversal(Root);
    cout<<endl;

    return 0;
}