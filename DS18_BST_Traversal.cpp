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

//Function To Get PreOrder Traversal Of The BST.....
void PreOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    cout<<Root->data<<" ";
    PreOrder_Traversal(Root->Left);
    PreOrder_Traversal(Root->Right);
}

//Function To Get InOrder Traversal Of The BST.....
void InOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    InOrder_Traversal(Root->Left);
    cout<<Root->data<<" ";
    InOrder_Traversal(Root->Right);
}

//Function To Get PostOrder Traversal Of The BST.....
void PostOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    PostOrder_Traversal(Root->Left);
    PostOrder_Traversal(Root->Right);
    cout<<Root->data<<" ";
}

/*
         4
       /   \
      2     6
     / \   / \
    1   3 5   7
*/

int main(){

    Node* NewNode=new Node(4);
    NewNode->Left=new Node(2);
    NewNode->Right=new Node(6);
    NewNode->Left->Left=new Node(1);
    NewNode->Left->Right=new Node(3);
    NewNode->Right->Left=new Node(5);
    NewNode->Right->Right=new Node(7);

    cout<<"THE PRE-ORDER TRAVERSAL IS ::: ";
    PreOrder_Traversal(NewNode);
    cout<<endl;

    cout<<"THE IN-ORDER TRAVERSAL IS ::: ";
    InOrder_Traversal(NewNode);
    cout<<endl;

    cout<<"THE POST-ORDER TRAVERSAL IS ::: ";
    PostOrder_Traversal(NewNode);
    cout<<endl;

    return 0;
}