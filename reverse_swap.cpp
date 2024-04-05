#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};
class SinglyLL{
    public:
    Node* head;
    SinglyLL(){
        head=NULL;
    }
    void display(){
        Node* temp =  head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
    void insert(int value){
        Node* new_node = new Node(value);
        if(head==NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        Node* n = NULL;
        while(curr!=NULL){
            n =  curr->next;
            curr->next =  prev;
            prev = curr;
            curr = n;
        }
        head = prev;
    }
    void swap(int a, int b){
        reverse();
        if (head == NULL || head->next == NULL) {
            return;
        }
        Node* nodeA = head;
        Node* nodeB = head;
        while (nodeA != NULL && nodeA->data != a) {
            nodeA = nodeA->next;
        }
        while (nodeB != NULL && nodeB->data != b) {
            nodeB = nodeB->next;
        }
        if (nodeA == NULL || nodeB == NULL) {
            return;
        }
        if (nodeA == nodeB) {
            return;
        }
        int temp = nodeA->data;
        nodeA->data = nodeB->data;
        nodeB->data = temp;
    }
};
int main(){
    SinglyLL SL;
    int n;
    cout<<"Enter number of Nodes:-";
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        SL.insert(a);
    }
    SL.display();
    int A,B;
    cin>>A;
    cin>>B;
    SL.swap(A,B);
    SL.display();
    return 0;
}