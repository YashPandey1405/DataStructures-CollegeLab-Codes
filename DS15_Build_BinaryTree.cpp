// We Will Build Binary Tree Using PreOrder Traversal Of Binary Tree....

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

static int Index=(-1);

class BinaryTree{
    public:
        Node* BuildTree(int arr[]){
            Index++;
            //Base Case Of Recursion.....
            if(arr[Index]==(-1)){  //When The Root Node Is NULL.....
                return NULL;
            }
            Node* NewNode=new Node(arr[Index]);
            NewNode->Left=BuildTree(arr);
            NewNode->Left=BuildTree(arr);
            return NewNode;
        }
};

int main(){
    int arr[13]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree Tree;  //Object Of Class-'BinaryTree'......
    Node* Root=Tree.BuildTree(arr);
    cout<<"THE ROOT OF BINARY TREE IS ::: "<<Root->data<<endl;
    return 0;
}