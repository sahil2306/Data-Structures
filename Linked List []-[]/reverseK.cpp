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

node* reverseListK(node* &head, int k){
    node *prev=NULL;
    node *curr = head;
    node *next;
    int count = 0;
    
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

        count++;
    }

    if(next!=NULL){
        head->next = reverseListK(next, k);
    }

    return prev;
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

    head = reverseListK(head, 2);
    cout<<"\nList : ";display(head);          //3,1,7,5,9

}


/*
if (k <= 1)
      return head;
    
    ListNode * nextHead = head;
    for (int i=0; i<k; ++i) {
      if (!nextHead)
        return head;
      nextHead = nextHead->next;
    }
    
    ListNode * prev = head;
    ListNode * next = head->next;
    for (int i=0; i<k-1; ++i) {
      ListNode * tmp = next->next;
      next->next = prev;
      prev = next;
      next = tmp;
    }
    
    head->next = reverseKGroup(nextHead, k);
    return prev;

*/