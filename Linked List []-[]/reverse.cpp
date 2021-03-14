#include<iostream>
using namespace std;

//Basic Node Structure
struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};


//Reverse List
node* reverseList(node* &head){
    node *prev=NULL;
    node *curr = head;
    node *next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}


node* recursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* newhead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


//Inserting new node
void insertLast(node* &head, int val){
    node *n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }


    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

//Display linkedList
void display(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    cout<<"\nCreating a null LinkedList ";
    node *head = NULL;      //NULL

    insertLast(head,1);
    insertLast(head,3);
    insertLast(head,5);
    insertLast(head,7);
    insertLast(head,9);
    cout<<"\nList : ";display(head);          //1,3,5,7,9

    head = reverseList(head);
    cout<<"\nList : ";display(head);          //9,7,5,3,1

    head = recursiveReverse(head);  
    cout<<"\nList : ";display(head);          //1,3,5,7,9
}